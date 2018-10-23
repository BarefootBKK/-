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
	Onlinepvp(QWidget *parent = Q_NULLPTR);	// ���캯��
	void initData();						// ��ʼ����������
	void setConnection();					// �����ź���۵�����

public slots:
	// �ۺ���
	void drawChess();	// ������
	void undo();		// ����
	void defeat();		// ����
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
