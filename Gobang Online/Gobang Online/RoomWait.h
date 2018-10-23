#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QtWidgets/QWidget>
#include "ui_Room_Wait.h"
#include "globalVal.h"

class RoomWait : public QDialog
{
	Q_OBJECT

signals:
	void leave(QString);
signals:
	void start_game();

public:

	RoomWait(QWidget *parent = Q_NULLPTR);	// 构造函数

	void initData(); 						// 初始化界面数据
	void setConnection();					// 建立信号与槽的连接
	void setRoomName(QString);				// 显示房间名
	void setRoomNum(QString);				// 显示房间号
	void setRoomType(QString);				// 显示房间类型
	void setOpName(QString);				// 显示对手昵称
	void setMyName(QString);				// 显示我的昵称

public slots:
	void setRoomOwnner(bool);
	bool isRoomOwnner();
	void leaveRoom();						// 离开房间
	void startGame();						// 开始游戏

private:
	Ui::Room_wait ui;
	bool isMeOwnner;
	bool isSomeoneIn;
	QString room_num;
};