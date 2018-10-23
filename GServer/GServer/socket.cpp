// scoket.cpp
#include "socket.h"

// 构造函数
Socket::Socket(QObject *parent, qintptr q) : QTcpSocket(parent)
{
	this->setSocketDescriptor(q);		// socket标识符
	this->isMatched = false;			// 未匹配到对手

	// 建立信号与槽的连接
	QObject::connect(this, SIGNAL(readyRead()), this, SLOT(On_read()));
	QObject::connect(this, SIGNAL(disconnected()), this, SLOT(On_discon()));
}

// 与服务器断开连接
void Socket::On_discon()
{
	emit discon();
	this->disconnectFromHost();
}

// 读取数据
void Socket::On_read()
{
	QByteArray buffer = this->readAll();

	if (!buffer.isEmpty())
	{
		parseData(tr(buffer));
	}
}

// 设置对手
void Socket::SetOpp(Socket * soc_opponent)
{
	this->isMatched = true;
	this->soc_opponent = soc_opponent;
}

// 删除对手的网络id
void Socket::DeleteOpp()
{
	this->isMatched = false;
}

// 发送数据给对手
void Socket::SendOppData(QString str_msg)
{
	soc_opponent->write(str_msg.toLocal8Bit());
	soc_opponent->waitForBytesWritten();
	soc_opponent->flush();
}

// 回馈客户端
void Socket::SendStringData(QString acc_msg)
{
	this->write(acc_msg.toLocal8Bit());
	this->waitForBytesWritten();
	this->flush();
}

// 发送Int 类型的消息
void Socket::SendIntData(int int_msg)
{
	SendStringData(QString::number(int_msg));
}

// 解析消息
void Socket::parseData(QString str_msg)
{
	QStringList list = str_msg.split("|");

	if (list.at(0).toInt() == MATCH_SUCC)
	{
		isMatched = true;
	}

	if (!isMatched || list.at(0).toInt() == ROOM_LEAVE || list.at(0).toInt() == ROOM_CLOSE)
	{
		// 经主线程处理消息
		emit req_msg(list, this);
	}
	else
	{
		// 不经主线程处理直接给对手发送消息
		SendOppData(str_msg);
	}
}

// 服务器反馈信息
void Socket::ServerFeback(int msg)
{
	emit s_feback(msg);
}


