// Gobang.h
#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QtWidgets/QWidget>
#include <QTimer>
#include <QThread>
#include <QFileDialog>
#include "ui_Onlinepvp.h"
#include "MessageDialog.h"
#include "cmanager.h"

#define TIME_FORMAT_1 "00:"
#define TIME_FORMAT_2 "00:0"

class Onlinepvp : public QWidget
{
	Q_OBJECT

signals:
	void boardMsg(QString);
signals:
	void back();

public:
	Onlinepvp(QWidget *parent = Q_NULLPTR);	// 构造函数
	void initData();						// 初始化界面数据
	void setConnection();					// 建立信号与槽的连接

public slots:
	// 槽函数
	void drawChess();	// 画棋子
	void undo();		// 悔棋
	void defeat();		// 认输
	void save();
	void sendChessInfo();
	void readChessInfo(QString);
	void initBoard(int, int);

	void startTimeThread();
	void countTimeThread();
	void setTime();
	void getHint();

private:
	Ui::FormOnlinepvp ui;
	int time_count;
	QTimer * timer;
	QThread * time_thread;
	CManager * manager;
	int first;
	bool isMyTurn;
	MessageDialog messageDialog;
};
