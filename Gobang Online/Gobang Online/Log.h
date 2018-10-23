
#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
#include <QtWidgets/QWidget>
#include <QThread>
#include <QMessageBox>
#include "ui_Log.h"
#include"Room.h"
#include "socketthread.h"
#include "socket.h"
#include "globalVal.h"

class Log : public QWidget
{
	Q_OBJECT

signals:
	void back();
signals:
	void log_msg(QString);
signals:
	void log_in(AccountInfo);
signals:
	void regist();

public:
	Log(QWidget *parent = Q_NULLPTR);		// 构造函数
	void initData();						// 初始化界面数据
	void setConnection();					// 建立信号与槽的连接


public slots:
	// 槽函数
	void logIn();
	void backTo();
	void regHide();
	void regShow();
	void sign_in();
	void clearText();
	void makeRoom(QString);
	void analyzeMsg(QStringList);

	//void sendsignal();

private:
	Ui::FormLog ui;
};