//Wait.cpp
#include "RoomWait.h"


// ���캯��
RoomWait::RoomWait(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->initData();	// ��ʼ������
}

// ��ʼ������
void RoomWait::initData()
{
	this->isMeOwnner = false;
	this->isSomeoneIn = false;
	this->ui.start_Button->setEnabled(false);
	// �̶����ڴ�С
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);	//��ֹ���
	this->setModal(true);
	this->setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

	this->setConnection();
}

// �����ź���۵�����
void RoomWait::setConnection()
{
	connect(ui.start_Button, SIGNAL(clicked()), this, SLOT(startGame()));
	connect(ui.back_button, SIGNAL(clicked()), this, SLOT(leaveRoom()));
}

// ����(��ʾ)������
void RoomWait::setRoomName(QString name)
{
	ui.roomName_label->setText("��������" + name);
}

// ����(��ʾ)�����
void RoomWait::setRoomNum(QString room_num)
{
	this->room_num = room_num;
	ui.roomNum_label->setText("����ţ�" + room_num);
}

// ����(��ʾ)��������
void RoomWait::setRoomType(QString type)
{
	ui.roomType_label->setText("�������ͣ�" + type);
}

// ��ʾ�����ǳ�
void RoomWait::setOpName(QString opName)
{
	isSomeoneIn = true;
	this->ui.start_Button->setEnabled(true);
	ui.op_name_label->setText(opName);
	ui.waitFor_label->setText("�ȴ�������ʼ��Ϸ");
}

// ��ʾ�ҵ��ǳ�
void RoomWait::setMyName(QString myName)
{
	ui.my_name_label->setText(myName);
}

// �����Ƿ���
void RoomWait::setRoomOwnner(bool state)
{
	this->isMeOwnner = state;

	if (!isMeOwnner)
		ui.start_Button->hide();
	else
		ui.start_Button->show();
}

// ��ʼ��Ϸ
void RoomWait::startGame()
{
	if (isMeOwnner && isSomeoneIn)
		emit start_game();
}

// �����Ƿ�Ϊ������bool����
bool RoomWait::isRoomOwnner()
{
	return isMeOwnner;
}

// �뿪����
void RoomWait::leaveRoom()
{
	QString str_msg = "|" + room_num;

	if (isMeOwnner)
		emit leave(QString::number(ROOM_CLOSE) + str_msg);
	else
		emit leave(QString::number(ROOM_LEAVE) + str_msg);
}