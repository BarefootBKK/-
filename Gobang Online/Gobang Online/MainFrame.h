#pragma once
#include <QtWidgets/QWidget>
#include <QTimer>
#include <QThread>
#include "ui_MainFrame.h"
#include "socket.h"
#include"Gobang.h"
#include"Log.h"
#include"Ranking.h"
#include"Replay.h"
#include"Onlinepvp.h"
#include"Pve.h"
#include "help.h"
#include "music.h"

class MainFrame : public QWidget
{
	Q_OBJECT

signals:
	void regist(QString);			// 注册
signals:
	void reconnect();				// 重连
signals:
	void send_msg(QString);			// 

public:
	MainFrame(QWidget *parent = Q_NULLPTR);	//析构函数

	void startSocketThread();
	void initData();						// 初始化界面数据
	void setConnection();					// 建立信号与槽的连接

public slots:
	// 槽函数
	void online();					// 联网对战
	void exit();					// 退出程序
	void pvp();						// 人人
	void pve();						// 人机
	void menu();					// 主菜单
	void Sign();					// 登录
	void PlayMusic();					// 音乐
	void replayBoard();				// 回放
	void ranking();					// 排行榜
	void showHelp();
	void reshow();					// 
	void processReq(QStringList);	// 处理消息
	void loginState(AccountInfo);	// 登陆状态
	void reconnThread();			// 重连线程
	void startReconn();				// 开始重连
	void setConnState(bool);		// 设置连接状态
	void setMyName();				// 显示我的昵称
	void nextSong();
	void ongame()
	{
		room->hide();
		this->hide();
		//pvponline->show();
		pvponline->initBoard(PVP_ONLINE, PLAYER_1);
		pvponline->startTimeThread();
		pvponline->show();
	}

private:
	Ui::FormMain ui;
	
	// 界面
	Gobang *gobang;
	Log *log;
	Room * room;
	Ranking	*rank;
	Replay *replay;
	Onlinepvp*pvponline;
	Pve* pvew;
	help * helpp;
	// socket
	Socket * socket;
	QThread * reconn_thread;
	QTimer * c_timer;
	bool isLogIn = false;
	bool isConnected;
	// 账号
	AccountInfo my_accInfo;
	AccountInfo op_accInfo;
	Music music;
	int music_state = 0;
	int first;
	int last_req;
};
