// server.h.
/*链接器->输入->附加依赖项：添加"Qt5Networkd.lib"*/
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#ifndef _SERVER_H_
#define _SERVER_H_

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QVector>
#include "socketthread.h"
#include "socket.h"
#include "room.h"
#include "account.h"

class Server : public QTcpServer
{
	Q_OBJECT

signals:
	void closeServ();
signals:
	void conn_new();
signals:
	void serv_msg(QString);
signals:
	void opponent(Socket *);

public:
	Server(QObject * parent = Q_NULLPTR);
	~Server();

public slots:
	void ProcessMsg(QStringList, Socket *);
	void sendRoomInfo();
	void clientDiscon();
	void closeServer();
	void sendToClient(Socket *, QString);

protected:
	virtual void incomingConnection(qintptr socketDescriptor);

private:

	void log_in(QStringList, Socket *);
	void sign_in(QStringList, Socket *);
	void createRoom(QStringList, Socket *);
	void joinRoom(QStringList, Socket *);
	void match(QStringList, Socket *);
	void leaveRoom(QStringList, Socket *);
	void closeRoom(QStringList, Socket *);

private:
	int matchedPlayer;
	int socket_num;
	int room_num;
	Socket * socket;
	Socket * last_socket;
	SocketThread * socketThread;
	PlayerInfo * player;
	Account * account;
	QVector<Room *> * roomList;
};

#endif