// socketthread.cpp
#include "socketthread.h"

SocketThread::SocketThread(QObject * parent, QString ip, int port) 
	: QThread(parent)
{
	this->ip = ip;
	this->port = port;
	this->isDisconnected = false;
	this->event_num = NONE;
}

void SocketThread::run()
{
	socket = new Socket(Q_NULLPTR, ip, port);
	QObject::connect(socket, SIGNAL(conn()), this, SLOT(connected()));
	QObject::connect(socket, SIGNAL(discon()), this, SLOT(disconnected()));

	while (true)
	{
		if (isDisconnected)	break;
		else if (event_num == SEND)
			socket->sendMsg(str_msg);

		event_num = NONE;
		msleep(10);
	}

	qDebug() << "end thread !";
}

void SocketThread::connected()
{
	emit soc_conn();
}

void SocketThread::disconnected()
{
	emit soc_discon();
	this->isDisconnected = true;
}

void SocketThread::on_recv(QString str_msg)
{
	qDebug() << "recieve : " << str_msg;
	this->str_msg = str_msg;
	event_num = SEND;
}
