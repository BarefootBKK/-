// socketthread.cpp
#include "socketthread.h"

// ���캯��
SocketThread::SocketThread(QObject * parent, qintptr ptr) : QThread(parent)
{
	this->ptr = ptr;
	this->event_num = NONE;
	this->isDisconnected = false;
	this->isFoundOpp = false;
}

// �߳̿�ʼ
void SocketThread::run()
{
	Socket * socket = new Socket(Q_NULLPTR, ptr);		// �µ�socket
	this->currentSock = socket;
	QObject::connect(socket, SIGNAL(discon()), this, SLOT(finished()));		// ��������
	QObject::connect(this, SIGNAL(soc_opponent(Socket *)), socket, SLOT(SetOpp(Socket *)));

	exec();
}

// ���ö���
void SocketThread::SetOpponent(Socket * opponent)
{
	emit soc_opponent(opponent);
}

// ����һ��Socket����
Socket * SocketThread::GetSocket()
{
	return currentSock;
}

// �߳̽���
void SocketThread::finished()
{
	//isDisconnected = true;
	event_num = OPP;
}

// �ر�socket
void SocketThread::closeSock()
{
	currentSock->disconnectFromHost();
}