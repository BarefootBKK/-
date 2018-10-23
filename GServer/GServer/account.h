// account.h
#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <fstream>
#include <QDir>
#include <string>
#include <QVector>
#include <qdebug.h>
#include "socket.h"
#include "globalVal.h"

class Account : public QObject
{
	Q_OBJECT

signals:
	void acc_msg(Socket *, QString);
signals:
	void acc_error(int);

public:
	Account();

public:
	void Sign_in(PlayerInfo *, Socket *);
	void Log_in(PlayerInfo *, Socket *);
	QString GetNickname();

private:
	void saveFile(PlayerInfo *, QString);
	void readFile(QString);
	bool checkIsLogined(QString);
	bool isAccExisted(QString);
	QString getEncryptedPlayerInfo();

private:
	PlayerInfo * player;
	Socket * socket;
	QString currentPath;
	QVector<QString> in_accounts;
};

#endif