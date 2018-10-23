#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QtWidgets/QWidget>
#include "ui_createroom.h"
#include <globalVal.h>
#include <QMessageBox>

typedef struct RoomInfo
{
	int room_type;
	QString room_name;
	QString room_num;
}RoomInfo;

class SetRoomDialog : public QDialog
{
	Q_OBJECT

signals:
	void room_info_msg(QString);

public:
	SetRoomDialog(QWidget *parent = Q_NULLPTR);	// ¹¹Ôìº¯Êý

	void InitData();
	RoomInfo GetRoomInfo();

private slots:
	void setKey(int);
	void finishSet();

private:
	Ui::SetRoomDialog ui;
	RoomInfo roomInfo;
};