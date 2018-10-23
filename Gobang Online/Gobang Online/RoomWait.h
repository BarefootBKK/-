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

	RoomWait(QWidget *parent = Q_NULLPTR);	// ���캯��

	void initData(); 						// ��ʼ����������
	void setConnection();					// �����ź���۵�����
	void setRoomName(QString);				// ��ʾ������
	void setRoomNum(QString);				// ��ʾ�����
	void setRoomType(QString);				// ��ʾ��������
	void setOpName(QString);				// ��ʾ�����ǳ�
	void setMyName(QString);				// ��ʾ�ҵ��ǳ�

public slots:
	void setRoomOwnner(bool);
	bool isRoomOwnner();
	void leaveRoom();						// �뿪����
	void startGame();						// ��ʼ��Ϸ

private:
	Ui::Room_wait ui;
	bool isMeOwnner;
	bool isSomeoneIn;
	QString room_num;
};