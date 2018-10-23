
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
	Log(QWidget *parent = Q_NULLPTR);		// ���캯��
	void initData();						// ��ʼ����������
	void setConnection();					// �����ź���۵�����


public slots:
	// �ۺ���
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