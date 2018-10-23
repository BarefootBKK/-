// socket.cpp
#include "socket.h"

// ���캯��
Socket::Socket(QObject * parent, QString ip, int port)
	: QTcpSocket(parent)
{
	this->ip = ip;
	this->port = port;
	this->isMatched = false;
}

// ���ӳɹ�
void Socket::on_connection()
{
	emit conn();
}

// ����
void Socket::on_disconnection()
{
	emit conn_state(false);
}

// ��ȡ��Ϣ
void Socket::on_read()
{
	QByteArray buffer = this->readAll();

	QString str_msg = QString::fromLocal8Bit(buffer);

	if (!buffer.isEmpty())
	{
		phraseMsg(str_msg);
	}
}

// ��������
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

// ����Ϣ
void Socket::sendMsg(QString str_msg)
{
	this->write(str_msg.toLocal8Bit());
	this->waitForBytesWritten();
	this->flush();
}

// ������Ϣ
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