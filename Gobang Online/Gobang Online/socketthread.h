// socketthread.h

#ifndef _SOCKETTHREAD_H_
#define _SOCKETTHREAD_H_

#include <QtNetwork/QTcpSocket>
#include <QThread>
#include "socket.h"

#define NONE	100
#define SEND	101

class SocketThread : public QThread
{
	Q_OBJECT

signals:
	void soc_conn();
signals:
	void soc_discon();
signals:
	void soc_sendMsg(QString);

public:
	SocketThread(QObject * parent, QString ip, int port);

protected:
	virtual void run();

public slots:
	void connected();
	void disconnected();
	void on_recv(QString);

private:
	QString ip;
	int port;
	int event_num;
	QString str_msg;
	bool isDisconnected;
	bool isFoundOpp;
	Socket * socket;
};

#endif