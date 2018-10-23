// socketthread.h

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#ifndef _SOCKETTHREAD_H_
#define _SOCKETTHREAD_H_

#include <QThread>
#include <QtNetwork/QTcpSocket>
#include "socket.h"

#define NONE	0
#define DIS		2
#define OPP		3

class SocketThread : public QThread
{
	Q_OBJECT

signals:
	void soc_opponent(Socket *);

public:
	SocketThread(QObject * parent, qintptr ptr);

protected:
	virtual void run();

public slots:
	void finished();
	void closeSock();

public:
	void SetOpponent(Socket *);
	Socket * GetSocket();

private:
	qintptr ptr;
	bool isDisconnected;
	bool isFoundOpp;
	int event_num;
	Socket * currentSock;
	Socket * opponent;
};
#endif