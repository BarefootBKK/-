// server.cpp
#include "server.h"

// 构造函数
Server::Server(QObject * parent) : QTcpServer(parent)
{
	this->matchedPlayer = 0;
	this->socket_num = 0;
	this->room_num = 0;
	this->roomList = new QVector<Room *>;
	this->account = new Account();
	connect(account, SIGNAL(acc_msg(Socket *, QString)), this, SLOT(sendToClient(Socket *, QString)));
}

// 析构函数
Server::~Server()
{
	this->close();
}

// 若有客户端失去连接
void Server::clientDiscon()
{
	this->socket_num--;
}

// 关闭服务器
void Server::closeServer()
{
	if (socket_num > 0)
		emit closeServ();
}

// 若有新连接
void Server::incomingConnection(qintptr socketDescriptor)
{
	this->socket_num++;			// 已接入服务器的客户端个数
	emit conn_new();				// 发送新连接信号

	// 新socket，并建立信号与槽函数的连接
	socket = new Socket(Q_NULLPTR, socketDescriptor);
	connect(socket, SIGNAL(discon()), this, SLOT(clientDiscon()));
	connect(this, SIGNAL(closeServ()), socket, SLOT(On_discon()));
	connect(this, SIGNAL(serv_msg(QString)), socket, SLOT(SendStringData(QString)));
	connect(socket, SIGNAL(req_msg(QStringList, Socket *)), this, SLOT(ProcessMsg(QStringList, Socket *)));

	sendRoomInfo();
}

// 处理消息
void Server::ProcessMsg(QStringList list, Socket * in_socket)
{
	int req = list.at(0).toInt();

	if (req == SIGN_IN)							// 注册
	{
		sign_in(list, in_socket);
	}
	else if (req == LOG_IN)						// 登录
	{
		log_in(list, in_socket);
	}
	else if (req == ROOM_PU || req == ROOM_PR)	// 创建房间
	{
		this->createRoom(list, in_socket);
	}
	else if (req == ROOM_ADD)					// 加入房间
	{
		this->joinRoom(list, in_socket);
	}
	else if (req == MATCH)						// 匹配
	{
		this->match(list, in_socket);
	}
	else if (req == MATCH_CANCEL)				// 取消匹配
	{
		matchedPlayer = 0;
	}
	else if (req == ROOM_LEAVE)					// 离开房间
	{
		this->leaveRoom(list, in_socket);		
	}
	else if (req == ROOM_CLOSE)					// 关闭房间
	{
		this->closeRoom(list, in_socket);
	}
}
 
// 登录
void Server::log_in(QStringList list, Socket * in_socket)
{
	player = new PlayerInfo();
	player->account = list.at(1);
	player->password = list.at(2);
	// 登录
	account->Log_in(player, in_socket);
}

// 注册
void Server::sign_in(QStringList list, Socket * in_socket)
{
	player = new PlayerInfo();

	player->account = list.at(1);
	player->password = list.at(2);
	player->nickname = list.at(3);
	// 注册
	account->Sign_in(player, in_socket);
}

// 创建房间
void Server::createRoom(QStringList list, Socket * in_socket)
{
	room_num++;
	// 房间参数
	Room * room = new Room(in_socket);
	int		room_type = list.at(0).toInt();
	int		room_key  = list.at(2).toInt();
	QString room_name = list.at(1);

	room->SetRoomType(room_type);
	room->SetRoomName(room_name);
	room->SetRoomNum((DEFAULT_ROOM_NUM + room_num));	
	room->SetRoomKey(room_key);

	roomList->push_back(room);

	this->sendRoomInfo();
	sendToClient(in_socket, (QString::number(ROOM_NEW) + "|" + QString::number(room->GetRoomNum())));
}

// 加入房间
void Server::joinRoom(QStringList list, Socket * in_socket)
{
	int seq_num = list.at(1).toInt() - DEFAULT_ROOM_NUM - 1;
	int in_key  = list.at(2).toInt();
	Room * temp_room = roomList->at(seq_num);

	if (in_key == temp_room->GetRoomKey())
	{
		temp_room->AddPlayer(in_socket);		// 加入房间

		sendToClient(temp_room->GetRoomOwner(), QString::number(ROOM_ADD_SUCC));
		sendToClient(in_socket, QString::number(ROOM_ADD_SUCC));
		this->sendRoomInfo();

		// 放入线程处理
		QThread * thread = new QThread();
		temp_room->moveToThread(thread);
		thread->start();
	}
	else
		sendToClient(in_socket, QString::number(ROOM_KEY_ERROR));		// 密码错误
}

// 匹配玩家
void Server::match(QStringList list, Socket * in_socket)
{
	// 若未匹配到对手，则不开线程
	if (matchedPlayer == 0)
	{
		matchedPlayer = 1;					// 队列中玩家+1
		last_socket = in_socket;
	}
	// 一旦匹配到对手，将两个socket放到同一线程进行处理
	else
	{
		matchedPlayer = 0;					// 队列玩家清空

		QThread * thread = new QThread();	// 新开线程
		/*
		* 将匹配到的这两个客户端建立起连接，
		* 并放到同一线程中进行消息处理
		*/
		last_socket->SetOpp(in_socket);		// 匹配对手
		in_socket->SetOpp(last_socket);		// 匹配对手

		sendToClient(last_socket, (QString::number(MATCH_SUCC) + "|" + QString::number(PLAYER_1)));
		sendToClient(in_socket, (QString::number(MATCH_SUCC) + "|" + QString::number(PLAYER_2)));

		// 将socket移到线程中
		last_socket->moveToThread(thread);
		in_socket->moveToThread(thread);
		thread->start();			// 线程开始
	}
}

// 离开房间
void Server::leaveRoom(QStringList list, Socket * in_socket)
{
	int temp_room_num = list.at(1).toInt();

	for (int i = 0; i < roomList->size(); i++)
	{
		if (temp_room_num == roomList->at(i)->GetRoomNum())
		{
			roomList->at(i)->LeaveRoom();
			qDebug() << "离开的房间号：" << temp_room_num;
			break;
		}
	}

	this->sendRoomInfo();
}

// 关闭房间
void Server::closeRoom(QStringList list, Socket * in_socket)
{
	qDebug() << "房间号：" << list.at(1);

	int temp_room_num = list.at(1).toInt();
	
	for (int i = 0; i < roomList->size(); i++)
	{
		if (temp_room_num == roomList->at(i)->GetRoomNum())
		{
			roomList->erase(roomList->begin() + i);
			break;
		}
	}
	
	this->sendRoomInfo();
}

// 向客户端发送房间信息
void Server::sendRoomInfo()
{
	QString str_roomInfo = QString::number(ROOM_INFO_LIST);
	if (roomList->size() > 0)
		str_roomInfo += "|";

	for (int i = 0; i < (int)roomList->size(); i++)
	{
		QString str =   roomList->at(i)->GetRoomName() + "#" +
						QString::number(roomList->at(i)->GetRoomNum()) + "#" +
						QString::number(roomList->at(i)->GetRoomType()) + "#" + 
						QString::number(roomList->at(i)->GetPlayerNum());

		str_roomInfo += str;
		if (i != (int)roomList->size() - 1)
			str_roomInfo += "|";
	}
	
	emit serv_msg(str_roomInfo);
}

// 给服务端发消息
void Server::sendToClient(Socket * temp_socket, QString str_msg)
{
	temp_socket->write(str_msg.toLocal8Bit());
	temp_socket->waitForBytesWritten();
	temp_socket->flush();
}