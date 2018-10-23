// scoket.cpp
#include "socket.h"

// ���캯��
Socket::Socket(QObject *parent, qintptr q) : QTcpSocket(parent)
{
	this->setSocketDescriptor(q);		// socket��ʶ��
	this->isMatched = false;			// δƥ�䵽����

	// �����ź���۵�����
	QObject::connect(this, SIGNAL(readyRead()), this, SLOT(On_read()));
	QObject::connect(this, SIGNAL(disconnected()), this, SLOT(On_discon()));
}

// ��������Ͽ�����
void Socket::On_discon()
{
	emit discon();
	this->disconnectFromHost();
}

// ��ȡ����
void Socket::On_read()
{
	QByteArray buffer = this->readAll();

	if (!buffer.isEmpty())
	{
		parseData(tr(buffer));
	}
}

// ���ö���
void Socket::SetOpp(Socket * soc_opponent)
{
	this->isMatched = true;
	this->soc_opponent = soc_opponent;
}

// ɾ�����ֵ�����id
void Socket::DeleteOpp()
{
	this->isMatched = false;
}

// �������ݸ�����
void Socket::SendOppData(QString str_msg)
{
	soc_opponent->write(str_msg.toLocal8Bit());
	soc_opponent->waitForBytesWritten();
	soc_opponent->flush();
}

// �����ͻ���
void Socket::SendStringData(QString acc_msg)
{
	this->write(acc_msg.toLocal8Bit());
	this->waitForBytesWritten();
	this->flush();
}

// ����Int ���͵���Ϣ
void Socket::SendIntData(int int_msg)
{
	SendStringData(QString::number(int_msg));
}

// ������Ϣ
void Socket::parseData(QString str_msg)
{
	QStringList list = str_msg.split("|");

	if (list.at(0).toInt() == MATCH_SUCC)
	{
		isMatched = true;
	}

	if (!isMatched || list.at(0).toInt() == ROOM_LEAVE || list.at(0).toInt() == ROOM_CLOSE)
	{
		// �����̴߳�����Ϣ
		emit req_msg(list, this);
	}
	else
	{
		// �������̴߳���ֱ�Ӹ����ַ�����Ϣ
		SendOppData(str_msg);
	}
}

// ������������Ϣ
void Socket::ServerFeback(int msg)
{
	emit s_feback(msg);
}


