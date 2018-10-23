// socket.cpp
#include "socket.h"

// 构造函数
Socket::Socket(QObject * parent, QString ip, int port)
	: QTcpSocket(parent)
{
	this->ip = ip;
	this->port = port;
	this->isMatched = false;
}

// 连接成功
void Socket::on_connection()
{
	emit conn();
}

// 断线
void Socket::on_disconnection()
{
	emit conn_state(false);
}

// 读取消息
void Socket::on_read()
{
	QByteArray buffer = this->readAll();

	QString str_msg = QString::fromLocal8Bit(buffer);

	if (!buffer.isEmpty())
	{
		phraseMsg(str_msg);
	}
}

// 断线重连
void Socket::reconnectServer()
{
	this->abort();
	this->connectToHost(ip, port);

	if (!this->waitForConnected(3000))
	{
		this->disconnectFromHost();
		emit conn_state(false);
	}
	else
		emit conn_state(true);
}

// 发消息
void Socket::sendMsg(QString str_msg)
{
	this->write(str_msg.toLocal8Bit());
	this->waitForBytesWritten();
	this->flush();
}

// 解析消息
void Socket::phraseMsg(QString msg)
{
	QStringList list = msg.split("|");
	int req = list.at(0).toInt();

	if (req == CHESSED)
	{
		emit oppChess(msg);
	}
	else
	{
		emit serv_msg(list);
	}

}