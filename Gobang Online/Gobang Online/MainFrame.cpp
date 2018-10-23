#include"MainFrame.h"
#include<windows.h>  

#include<mmsystem.h>  
#pragma comment(lib,"winmm.lib")  
#include"resource.h"

#include <QMessageBox>

// 构造函数
MainFrame::MainFrame(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->initData();	// 初始化数据
	this->startSocketThread();
	this->reconnThread();
}

// 初始化数据
void MainFrame::initData()
{
	gobang = new Gobang();
	log = new Log();
	room = new Room();
	rank = new Ranking();
	pvew = new Pve();
	replay = new Replay();
	pvponline = new Onlinepvp();
	isConnected = false;
	helpp = new help();

	// 固定窗口大小
	this->setMinimumSize(600, 600);	// 窗口最小尺寸
	this->setMaximumSize(600, 600);	// 窗口最大尺寸
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);	//禁止最大化
	this->setConnection();

	PlayMusic();
}

// 建立信号与槽的连接
void MainFrame::setConnection()
{
	// 主界面界面按钮的信号与槽
	connect(ui.pvp_Button, SIGNAL(clicked()), this, SLOT(pvp()));
	connect(ui.pve_Button, SIGNAL(clicked()), this, SLOT(pve()));
	connect(ui.Online_Button, SIGNAL(clicked()), this, SLOT(online()));
	connect(ui.Sign_Button, SIGNAL(clicked()), this, SLOT(Sign()));
	connect(ui.Exit_Button, SIGNAL(clicked()), this, SLOT(exit()));
	connect(ui.replay_Button, SIGNAL(clicked()), this, SLOT(replayBoard()));
	connect(ui.ranking_Button, SIGNAL(clicked()), this, SLOT(ranking()));
	connect(ui.music_button, SIGNAL(clicked()), this, SLOT(PlayMusic()));
	// 下一曲
	connect(ui.nextSong_Button, SIGNAL(clicked()), SLOT(nextSong()));
	// 棋盘界面
	connect(gobang, SIGNAL(back_to()), this, SLOT(menu()));
	// 登录界面
	connect(log, SIGNAL(back()), this, SLOT(reshow()));
	connect(log, SIGNAL(log_in(AccountInfo)), this, SLOT(loginState(AccountInfo)));
	// 人机
	connect(pvew, SIGNAL(back_to()), this, SLOT(menu()));
	// 房间
	connect(room, SIGNAL(back()), this, SLOT(reshow()));
	connect(room, SIGNAL(get_myname()), this, SLOT(setMyName()));
	connect(room, SIGNAL(start()), this, SLOT(ongame()));
	// 排名
	connect(rank, SIGNAL(back()), this, SLOT(reshow()));
	// 回放
	connect(replay, SIGNAL(back()), this, SLOT(reshow()));
	// 联机
	connect(pvponline, SIGNAL(back()), this, SLOT(reshow()));
	// 帮助
	connect(ui.help_button, SIGNAL(clicked()), this, SLOT(showHelp()));
	connect(helpp, SIGNAL(back_to()), this, SLOT(reshow()));
	
}

// 开始socket线程
void MainFrame::startSocketThread()
{
	// 新的线程
	QThread * thread = new QThread();
	// 新的socket 
	socket = new Socket(Q_NULLPTR, "127.0.0.1", 8080);

	// socket自身 的信号与槽
	connect(socket, SIGNAL(readyRead()), socket, SLOT(on_read()));
	connect(socket, SIGNAL(connected()), socket, SLOT(on_connection()));
	connect(socket, SIGNAL(disconnected()), socket, SLOT(on_disconnection()));

	// socket 和 mainframe 的信号与槽
	connect(socket, SIGNAL(serv_msg(QStringList)), this, SLOT(processReq(QStringList)));
	connect(socket, SIGNAL(conn_state(bool)), this, SLOT(setConnState(bool)));
	connect(this, SIGNAL(reconnect()), socket, SLOT(reconnectServer()));
	connect(this, SIGNAL(send_msg(QString)), socket, SLOT(sendMsg(QString)));

	// socket 和 room 的信号与槽
	connect(socket, SIGNAL(serv_msg(QStringList)), room, SLOT(processRoomInfo(QStringList)));
	connect(room, SIGNAL(room_msg(QString)), socket, SLOT(sendMsg(QString)));

	// socket 和 gobang 的信号与槽
	connect(socket, SIGNAL(oppChess(QString)), gobang, SLOT(readChessInfo(QString)));
	connect(gobang, SIGNAL(boardMsg(QString)), socket, SLOT(sendMsg(QString)));
	// socket 和 online_pvp 的信号与槽
	connect(socket, SIGNAL(oppChess(QString)), pvponline, SLOT(readChessInfo(QString)));
	connect(pvponline, SIGNAL(boardMsg(QString)), socket, SLOT(sendMsg(QString)));

	// socket 和 log 的信号与槽
	connect(socket, SIGNAL(serv_msg(QStringList)), log, SLOT(analyzeMsg(QStringList)));
	connect(log, SIGNAL(log_msg(QString)), socket, SLOT(sendMsg(QString)));

	// socket 和 thread 的信号与槽
	connect(thread, SIGNAL(started()), socket, SLOT(reconnectServer()));

	// 将socket移入线程
	socket->moveToThread(thread);
	thread->start();		// 开始线程
}

// 打开人人对战界面
void MainFrame::pvp()
{
	this->hide();
	gobang->initBoard(PVP_LOCAL, PLAYER_1);
	gobang->show();
}

// 打开人机对战界面
void MainFrame::pve() 
{
	this->hide();
	gobang->initBoard(PVE, PLAYER_1);
	gobang->show();
}

// 退出程序
void MainFrame::exit()	
{
	qApp->quit();		//退出程序
}

// 开启背景音乐
void MainFrame::PlayMusic()
{
	if (music_state == 0)
	{
		music_state = -1;
		music.PlayMenuMusic();
		ui.music_button->setText("停止播放");
		ui.nextSong_Button->setEnabled(true);
		ui.nextSong_Button->show();
	}
	else
	{
		music_state = 0;
		music.PlayPause();
		ui.music_button->setText("播放音乐");
		ui.nextSong_Button->setEnabled(false);
		ui.nextSong_Button->hide();
	}
}

//通过调用联网/登录界面
void MainFrame::online()
{
	if (isLogIn)
	{
		this->hide();//隐藏登录对话框  
		room->show();
	}
	else
		Sign();
}

// 跳转登陆界面
void MainFrame::Sign()	// 通过登录按钮直接登录界面
{
	this->hide();		// 隐藏登录对话框 
	log->show();		
}

// 打开回放界面
void MainFrame::replayBoard()
{
	this->hide();//隐藏登录对话框 
	replay->show();//emit quit();//发射退出信号
}

// 排行榜界面
void MainFrame::ranking()//通过登录按钮直接登录界面
{
	this->hide();//隐藏登录对话框 
	rank->show();//emit quit();//发射退出信号
}

void MainFrame::showHelp()
{
	this->hide();
	helpp->show();
}

//重新打开主界面
void MainFrame::reshow()	
{
	log->hide();
	room->hide();
	replay->hide();
	rank->hide();
	pvew->hide();
	helpp->hide();
	pvponline->hide();
	this->show();
}

// 处理消息
void MainFrame::processReq(QStringList list)
{
	int req = list.at(0).toInt();

	if (req == MATCH_SUCC || req == ROOM_ADD_SUCC) 
	{
		last_req = req;

		if (req == MATCH_SUCC)
			first = list.at(1).toInt();

		QString str_acc_msg = QString::number(ACCINFO) + "|" +
							my_accInfo.account + "|" +
							my_accInfo.nickname + "|" +
							my_accInfo.winned_num + "|" +
							my_accInfo.failed_num + "|" +
							my_accInfo.scores;

		emit send_msg(str_acc_msg);
	}
	else if (req == ROOM_KEY_ERROR)
	{
		QMessageBox::information(NULL, "hint", "房间密码错误！");
	}
	else if (req == ACCINFO)
	{
		op_accInfo.account = list.at(1);
		op_accInfo.nickname = list.at(2);
		op_accInfo.winned_num = list.at(3);
		op_accInfo.failed_num = list.at(4);
		op_accInfo.scores = list.at(5);

		if (last_req == MATCH_SUCC)
		{
			room->hide();
			this->hide();
			pvponline->initBoard(PVP_ONLINE, first);
			pvponline->show();
			pvponline->startTimeThread();
		}
		else
		{
			room->setOpName(op_accInfo.nickname);
		}

	}
	else if (req == ROOM_START_GAME)
	{
		room->hide();
		room->reshow();
		this->hide();/*
		gobang->initBoard(PVP_ONLINE, PLAYER_2);
		gobang->show();*/
		pvponline->initBoard(PVP_ONLINE, PLAYER_2);
		pvponline->show();
		pvponline->startTimeThread();
	}
}

// 登录状态
void MainFrame::loginState(AccountInfo accInfo)
{
	this->my_accInfo = accInfo;
	isLogIn = true;
	ui.log_state_label->setText("已登录");
}

// 重连线程
void MainFrame::reconnThread()
{
	reconn_thread = new QThread();
	c_timer = new QTimer();
	c_timer->moveToThread(reconn_thread);
	c_timer->setInterval(3000);
	connect(reconn_thread, SIGNAL(started()), c_timer, SLOT(start()));
	connect(c_timer, SIGNAL(timeout()), this, SLOT(startReconn()));

	reconn_thread->start();
}

// 开始重连
void MainFrame::startReconn()
{
	if (!isConnected)
		emit reconnect();
}

// 设置连接状态
void MainFrame::setConnState(bool net_state)
{
	isConnected = net_state;

	if (isConnected)
		ui.conn_state_label->setText("已连接服务器");
	else
	{
		ui.conn_state_label->setText("未连接服务器");
		ui.log_state_label->setText("未登录");
		isLogIn = false;
	}
}

// 显示我的昵称
void MainFrame::setMyName()
{
	room->setMyName(my_accInfo.nickname);
}

void MainFrame::nextSong()
{
	music.NextSong();
}

// 主菜单
void MainFrame::menu()
{
	pvew->hide();
	gobang->hide();
	this->show();
}
