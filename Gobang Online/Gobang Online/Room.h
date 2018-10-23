#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QtWidgets/QWidget>
#include <QInputDialog>
#include <QDir>
#include "ui_Room.h"
#include "setroom.h"
#include "RoomWait.h"
#include "globalVal.h"

class Room : public QWidget
{
	Q_OBJECT

signals :
	void back();
signals:
	void room_msg(QString);
signals:
	void start();
signals:
	void get_myname();

public:
	Room(QWidget *parent = Q_NULLPTR);	// 构造函数
	void initData();						// 初始化界面数据
	void setConnection();					// 建立信号与槽的连接
	QString getRoomType(int);
	void setMyName(QString);
	void setOpName(QString);

public slots:
	// 槽函数
	void matching();
	void backTo();
	void create();
	void set(QString);
	void processRoomInfo(QStringList);
	void updateRoomList(QStringList);
	void joinRoom(int, int);
	void reshow();
	void startGame();
	void leaveRoom(QString);

private:
	Ui::FormRoom ui;
	SetRoomDialog * setRoomDialog;
	RoomWait * roomWaitDialog;
	bool isMatching = false;
	RoomInfo roomInfo;
};