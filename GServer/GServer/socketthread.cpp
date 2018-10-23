// socketthread.cpp
#include "socketthread.h"

// 构造函数
SocketThread::SocketThread(QObject * parent, qintptr ptr) : QThread(parent)
{
	this->ptr = ptr;
	this->event_num = NONE;
	this->isDisconnected = false;
	this->isFoundOpp = false;
}

// 线程开始
void SocketThread::run()
{
	Socket * socket = new Socket(Q_NULLPTR, ptr);		// 新的socket
	this->currentSock = socket;
	QObject::connect(socket, SIGNAL(discon()), this, SLOT(finished()));		// 建立连接
	QObject::connect(this, SIGNAL(soc_opponent(Socket *)), socket, SLOT(SetOpp(Socket *)));

	exec();
}

// 设置对手
void SocketThread::SetOpponent(Socket * opponent)
{
	emit soc_opponent(opponent);
}

// 返回一个Socket变量
Socket * SocketThread::GetSocket()
{
	return currentSock;
}

// 线程结束
void SocketThread::finished()
{
	//isDisconnected = true;
	event_num = OPP;
}

// 关闭socket
void SocketThread::closeSock()
{
	currentSock->disconnectFromHost();
}