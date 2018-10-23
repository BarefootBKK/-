//Wait.cpp
#include "RoomWait.h"


// 构造函数
RoomWait::RoomWait(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->initData();	// 初始化数据
}

// 初始化数据
void RoomWait::initData()
{
	this->isMeOwnner = false;
	this->isSomeoneIn = false;
	this->ui.start_Button->setEnabled(false);
	// 固定窗口大小
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);	//禁止最大化
	this->setModal(true);
	this->setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

	this->setConnection();
}

// 建立信号与槽的连接
void RoomWait::setConnection()
{
	connect(ui.start_Button, SIGNAL(clicked()), this, SLOT(startGame()));
	connect(ui.back_button, SIGNAL(clicked()), this, SLOT(leaveRoom()));
}

// 设置(显示)房间名
void RoomWait::setRoomName(QString name)
{
	ui.roomName_label->setText("房间名：" + name);
}

// 设置(显示)房间号
void RoomWait::setRoomNum(QString room_num)
{
	this->room_num = room_num;
	ui.roomNum_label->setText("房间号：" + room_num);
}

// 设置(显示)房间类型
void RoomWait::setRoomType(QString type)
{
	ui.roomType_label->setText("房间类型：" + type);
}

// 显示对手昵称
void RoomWait::setOpName(QString opName)
{
	isSomeoneIn = true;
	this->ui.start_Button->setEnabled(true);
	ui.op_name_label->setText(opName);
	ui.waitFor_label->setText("等待房主开始游戏");
}

// 显示我的昵称
void RoomWait::setMyName(QString myName)
{
	ui.my_name_label->setText(myName);
}

// 设置是否房主
void RoomWait::setRoomOwnner(bool state)
{
	this->isMeOwnner = state;

	if (!isMeOwnner)
		ui.start_Button->hide();
	else
		ui.start_Button->show();
}

// 开始游戏
void RoomWait::startGame()
{
	if (isMeOwnner && isSomeoneIn)
		emit start_game();
}

// 返回是否为房主的bool变量
bool RoomWait::isRoomOwnner()
{
	return isMeOwnner;
}

// 离开房间
void RoomWait::leaveRoom()
{
	QString str_msg = "|" + room_num;

	if (isMeOwnner)
		emit leave(QString::number(ROOM_CLOSE) + str_msg);
	else
		emit leave(QString::number(ROOM_LEAVE) + str_msg);
}