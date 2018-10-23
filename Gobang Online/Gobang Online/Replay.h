// Relay.h
#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QtWidgets/QWidget>
#include <QFileDialog>
#include "ui_Replay.h"
#include "cmanager.h"
#include "ReplayThread.h"

class Replay : public QWidget
{
	Q_OBJECT

signals :
	void back();
signals:
	void play_state(bool);
signals:
	void play_stop();
signals:
	void speed(int);

public:
	Replay(QWidget *parent = Q_NULLPTR);	// 构造函数

private:
	void initData();						// 初始化界面数据
	void setConnection();					// 建立信号与槽的连接
	void autoPlayStarted();
	void exitThread();
	void clearBoard();

public slots:
	// 槽函数
	void Next();
	void Last();
	void Play();
	void Pause();
	void SetSpeed();
	void PlaybackMode();
	void AutoPlay();
	void ManualPlay();
	void Return();
	void drawChess(int, int);
	void ReadBoardInfo();
	void PlayState();
	
private:
	Ui::FormReplay ui;
	CManager * manager;
	int chess_pos;
	int play_speed;
	int play_mode;
	bool isThreadRunning;
	bool isReadFile;
	bool isPlaused;
	QVector<ChessNode> boardInfo;
	ReplayThread * replay_thread;
};