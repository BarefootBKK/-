// server.cpp
#include "server.h"

// ���캯��
Server::Server(QObject * parent) : QTcpServer(parent)
{
	this->matchedPlayer = 0;
	this->socket_num = 0;
	this->room_num = 0;
	this->roomList = new QVector<Room *>;
	this->account = new Account();
	connect(account, SIGNAL(acc_msg(Socket *, QString)), this, SLOT(sendToClient(Socket *, QString)));
}

// ��������
Server::~Server()
{
	this->close();
}

// ���пͻ���ʧȥ����
void Server::clientDiscon()
{
	this->socket_num--;
}

// �رշ�����
void Server::closeServer()
{
	if (socket_num > 0)
		emit closeServ();
}

// ����������
void Server::incomingConnection(qintptr socketDescriptor)
{
	this->socket_num++;			// �ѽ���������Ŀͻ��˸���
	emit conn_new();				// �����������ź�

	// ��socket���������ź���ۺ���������
	socket = new Socket(Q_NULLPTR, socketDescriptor);
	connect(socket, SIGNAL(discon()), this, SLOT(clientDiscon()));
	connect(this, SIGNAL(closeServ()), socket, SLOT(On_discon()));
	connect(this, SIGNAL(serv_msg(QString)), socket, SLOT(SendStringData(QString)));
	connect(socket, SIGNAL(req_msg(QStringList, Socket *)), this, SLOT(ProcessMsg(QStringList, Socket *)));

	sendRoomInfo();
}

// ������Ϣ
void Server::ProcessMsg(QStringList list, Socket * in_socket)
{
	int req = list.at(0).toInt();

	if (req == SIGN_IN)							// ע��
	{
		sign_in(list, in_socket);
	}
	else if (req == LOG_IN)						// ��¼
	{
		log_in(list, in_socket);
	}
	else if (req == ROOM_PU || req == ROOM_PR)	// ��������
	{
		this->createRoom(list, in_socket);
	}
	else if (req == ROOM_ADD)					// ���뷿��
	{
		this->joinRoom(list, in_socket);
	}
	else if (req == MATCH)						// ƥ��
	{
		this->match(list, in_socket);
	}
	else if (req == MATCH_CANCEL)				// ȡ��ƥ��
	{
		matchedPlayer = 0;
	}
	else if (req == ROOM_LEAVE)					// �뿪����
	{
		this->leaveRoom(list, in_socket);		
	}
	else if (req == ROOM_CLOSE)					// �رշ���
	{
		this->closeRoom(list, in_socket);
	}
}
 
// ��¼
void Server::log_in(QStringList list, Socket * in_socket)
{
	player = new PlayerInfo();
	player->account = list.at(1);
	player->password = list.at(2);
	// ��¼
	account->Log_in(player, in_socket);
}

// ע��
void Server::sign_in(QStringList list, Socket * in_socket)
{
	player = new PlayerInfo();

	player->account = list.at(1);
	player->password = list.at(2);
	player->nickname = list.at(3);
	// ע��
	account->Sign_in(player, in_socket);
}

// ��������
void Server::createRoom(QStringList list, Socket * in_socket)
{
	room_num++;
	// �������
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

// ���뷿��
void Server::joinRoom(QStringList list, Socket * in_socket)
{
	int seq_num = list.at(1).toInt() - DEFAULT_ROOM_NUM - 1;
	int in_key  = list.at(2).toInt();
	Room * temp_room = roomList->at(seq_num);

	if (in_key == temp_room->GetRoomKey())
	{
		temp_room->AddPlayer(in_socket);		// ���뷿��

		sendToClient(temp_room->GetRoomOwner(), QString::number(ROOM_ADD_SUCC));
		sendToClient(in_socket, QString::number(ROOM_ADD_SUCC));
		this->sendRoomInfo();

		// �����̴߳���
		QThread * thread = new QThread();
		temp_room->moveToThread(thread);
		thread->start();
	}
	else
		sendToClient(in_socket, QString::number(ROOM_KEY_ERROR));		// �������
}

// ƥ�����
void Server::match(QStringList list, Socket * in_socket)
{
	// ��δƥ�䵽���֣��򲻿��߳�
	if (matchedPlayer == 0)
	{
		matchedPlayer = 1;					// ���������+1
		last_socket = in_socket;
	}
	// һ��ƥ�䵽���֣�������socket�ŵ�ͬһ�߳̽��д���
	else
	{
		matchedPlayer = 0;					// ����������

		QThread * thread = new QThread();	// �¿��߳�
		/*
		* ��ƥ�䵽���������ͻ��˽��������ӣ�
		* ���ŵ�ͬһ�߳��н�����Ϣ����
		*/
		last_socket->SetOpp(in_socket);		// ƥ�����
		in_socket->SetOpp(last_socket);		// ƥ�����

		sendToClient(last_socket, (QString::number(MATCH_SUCC) + "|" + QString::number(PLAYER_1)));
		sendToClient(in_socket, (QString::number(MATCH_SUCC) + "|" + QString::number(PLAYER_2)));

		// ��socket�Ƶ��߳���
		last_socket->moveToThread(thread);
		in_socket->moveToThread(thread);
		thread->start();			// �߳̿�ʼ
	}
}

// �뿪����
void Server::leaveRoom(QStringList list, Socket * in_socket)
{
	int temp_room_num = list.at(1).toInt();

	for (int i = 0; i < roomList->size(); i++)
	{
		if (temp_room_num == roomList->at(i)->GetRoomNum())
		{
			roomList->at(i)->LeaveRoom();
			qDebug() << "�뿪�ķ���ţ�" << temp_room_num;
			break;
		}
	}

	this->sendRoomInfo();
}

// �رշ���
void Server::closeRoom(QStringList list, Socket * in_socket)
{
	qDebug() << "����ţ�" << list.at(1);

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

// ��ͻ��˷��ͷ�����Ϣ
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

// ������˷���Ϣ
void Server::sendToClient(Socket * temp_socket, QString str_msg)
{
	temp_socket->write(str_msg.toLocal8Bit());
	temp_socket->waitForBytesWritten();
	temp_socket->flush();
}