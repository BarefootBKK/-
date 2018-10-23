// socket.h

#ifndef _SOCKET_H_
#define _SOCKET_H_

#include <QtNetwork/QTcpSocket>
#include "globalVal.h"

class Socket : public QTcpSocket
{
	Q_OBJECT

signals:
	void conn();
signals:
	void discon();
signals:
	void oppChess(QString);
signals:
	void serv_msg(QStringList);
signals:
	void conn_state(bool);

public:
	Socket(QObject *, QString, int);

public slots:
	void sendMsg(QString);
	void on_connection();
	void on_disconnection();
	void on_read();
	void reconnectServer();

private:
	void phraseMsg(QString);

private:
	bool isMatched;
	int port;
	QString ip;
};

#endif