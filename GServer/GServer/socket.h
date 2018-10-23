// socket.h
#pragma once
#ifndef _SOCKET_H_
#define _SOCKET_H_

#include <QtNetwork/QTcpSocket>
#include "globalVal.h"
#include <QStringList>

class Socket : public QTcpSocket
{
	Q_OBJECT

signals:
	void discon();
signals:
	void s_feback(int);
signals:
	void req_msg(QStringList, Socket *);

public:
	Socket(QObject *, qintptr);

public slots:
	void On_discon();
	void On_read();
	void SendStringData(QString);
	void SendIntData(int);
	void SendOppData(QString);
	void SetOpp(Socket *);
	void DeleteOpp();
	void ServerFeback(int);

private:
	void parseData(QString);		// 解析数据请求

private:
	Socket * soc_opponent;
	bool isMatched;
};

#endif