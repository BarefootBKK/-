#include"MainFrame.h"
#include<windows.h>  

#include<mmsystem.h>  
#pragma comment(lib,"winmm.lib")  
#include"resource.h"

#include <QMessageBox>

// ���캯��
MainFrame::MainFrame(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->initData();	// ��ʼ������
	this->startSocketThread();
	this->reconnThread();
}

// ��ʼ������
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

	// �̶����ڴ�С
	this->setMinimumSize(600, 600);	// ������С�ߴ�
	this->setMaximumSize(600, 600);	// �������ߴ�
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);	//��ֹ���
	this->setConnection();

	PlayMusic();
}

// �����ź���۵�����
void MainFrame::setConnection()
{
	// ��������水ť���ź����
	connect(ui.pvp_Button, SIGNAL(clicked()), this, SLOT(pvp()));
	connect(ui.pve_Button, SIGNAL(clicked()), this, SLOT(pve()));
	connect(ui.Online_Button, SIGNAL(clicked()), this, SLOT(online()));
	connect(ui.Sign_Button, SIGNAL(clicked()), this, SLOT(Sign()));
	connect(ui.Exit_Button, SIGNAL(clicked()), this, SLOT(exit()));
	connect(ui.replay_Button, SIGNAL(clicked()), this, SLOT(replayBoard()));
	connect(ui.ranking_Button, SIGNAL(clicked()), this, SLOT(ranking()));
	connect(ui.music_button, SIGNAL(clicked()), this, SLOT(PlayMusic()));
	// ��һ��
	connect(ui.nextSong_Button, SIGNAL(clicked()), SLOT(nextSong()));
	// ���̽���
	connect(gobang, SIGNAL(back_to()), this, SLOT(menu()));
	// ��¼����
	connect(log, SIGNAL(back()), this, SLOT(reshow()));
	connect(log, SIGNAL(log_in(AccountInfo)), this, SLOT(loginState(AccountInfo)));
	// �˻�
	connect(pvew, SIGNAL(back_to()), this, SLOT(menu()));
	// ����
	connect(room, SIGNAL(back()), this, SLOT(reshow()));
	connect(room, SIGNAL(get_myname()), this, SLOT(setMyName()));
	connect(room, SIGNAL(start()), this, SLOT(ongame()));
	// ����
	connect(rank, SIGNAL(back()), this, SLOT(reshow()));
	// �ط�
	connect(replay, SIGNAL(back()), this, SLOT(reshow()));
	// ����
	connect(pvponline, SIGNAL(back()), this, SLOT(reshow()));
	// ����
	connect(ui.help_button, SIGNAL(clicked()), this, SLOT(showHelp()));
	connect(helpp, SIGNAL(back_to()), this, SLOT(reshow()));
	
}

// ��ʼsocket�߳�
void MainFrame::startSocketThread()
{
	// �µ��߳�
	QThread * thread = new QThread();
	// �µ�socket 
	socket = new Socket(Q_NULLPTR, "127.0.0.1", 8080);

	// socket���� ���ź����
	connect(socket, SIGNAL(readyRead()), socket, SLOT(on_read()));
	connect(socket, SIGNAL(connected()), socket, SLOT(on_connection()));
	connect(socket, SIGNAL(disconnected()), socket, SLOT(on_disconnection()));

	// socket �� mainframe ���ź����
	connect(socket, SIGNAL(serv_msg(QStringList)), this, SLOT(processReq(QStringList)));
	connect(socket, SIGNAL(conn_state(bool)), this, SLOT(setConnState(bool)));
	connect(this, SIGNAL(reconnect()), socket, SLOT(reconnectServer()));
	connect(this, SIGNAL(send_msg(QString)), socket, SLOT(sendMsg(QString)));

	// socket �� room ���ź����
	connect(socket, SIGNAL(serv_msg(QStringList)), room, SLOT(processRoomInfo(QStringList)));
	connect(room, SIGNAL(room_msg(QString)), socket, SLOT(sendMsg(QString)));

	// socket �� gobang ���ź����
	connect(socket, SIGNAL(oppChess(QString)), gobang, SLOT(readChessInfo(QString)));
	connect(gobang, SIGNAL(boardMsg(QString)), socket, SLOT(sendMsg(QString)));
	// socket �� online_pvp ���ź����
	connect(socket, SIGNAL(oppChess(QString)), pvponline, SLOT(readChessInfo(QString)));
	connect(pvponline, SIGNAL(boardMsg(QString)), socket, SLOT(sendMsg(QString)));

	// socket �� log ���ź����
	connect(socket, SIGNAL(serv_msg(QStringList)), log, SLOT(analyzeMsg(QStringList)));
	connect(log, SIGNAL(log_msg(QString)), socket, SLOT(sendMsg(QString)));

	// socket �� thread ���ź����
	connect(thread, SIGNAL(started()), socket, SLOT(reconnectServer()));

	// ��socket�����߳�
	socket->moveToThread(thread);
	thread->start();		// ��ʼ�߳�
}

// �����˶�ս����
void MainFrame::pvp()
{
	this->hide();
	gobang->initBoard(PVP_LOCAL, PLAYER_1);
	gobang->show();
}

// ���˻���ս����
void MainFrame::pve() 
{
	this->hide();
	gobang->initBoard(PVE, PLAYER_1);
	gobang->show();
}

// �˳�����
void MainFrame::exit()	
{
	qApp->quit();		//�˳�����
}

// ������������
void MainFrame::PlayMusic()
{
	if (music_state == 0)
	{
		music_state = -1;
		music.PlayMenuMusic();
		ui.music_button->setText("ֹͣ����");
		ui.nextSong_Button->setEnabled(true);
		ui.nextSong_Button->show();
	}
	else
	{
		music_state = 0;
		music.PlayPause();
		ui.music_button->setText("��������");
		ui.nextSong_Button->setEnabled(false);
		ui.nextSong_Button->hide();
	}
}

//ͨ����������/��¼����
void MainFrame::online()
{
	if (isLogIn)
	{
		this->hide();//���ص�¼�Ի���  
		room->show();
	}
	else
		Sign();
}

// ��ת��½����
void MainFrame::Sign()	// ͨ����¼��ťֱ�ӵ�¼����
{
	this->hide();		// ���ص�¼�Ի��� 
	log->show();		
}

// �򿪻طŽ���
void MainFrame::replayBoard()
{
	this->hide();//���ص�¼�Ի��� 
	replay->show();//emit quit();//�����˳��ź�
}

// ���а����
void MainFrame::ranking()//ͨ����¼��ťֱ�ӵ�¼����
{
	this->hide();//���ص�¼�Ի��� 
	rank->show();//emit quit();//�����˳��ź�
}

void MainFrame::showHelp()
{
	this->hide();
	helpp->show();
}

//���´�������
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

// ������Ϣ
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
		QMessageBox::information(NULL, "hint", "�����������");
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

// ��¼״̬
void MainFrame::loginState(AccountInfo accInfo)
{
	this->my_accInfo = accInfo;
	isLogIn = true;
	ui.log_state_label->setText("�ѵ�¼");
}

// �����߳�
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

// ��ʼ����
void MainFrame::startReconn()
{
	if (!isConnected)
		emit reconnect();
}

// ��������״̬
void MainFrame::setConnState(bool net_state)
{
	isConnected = net_state;

	if (isConnected)
		ui.conn_state_label->setText("�����ӷ�����");
	else
	{
		ui.conn_state_label->setText("δ���ӷ�����");
		ui.log_state_label->setText("δ��¼");
		isLogIn = false;
	}
}

// ��ʾ�ҵ��ǳ�
void MainFrame::setMyName()
{
	room->setMyName(my_accInfo.nickname);
}

void MainFrame::nextSong()
{
	music.NextSong();
}

// ���˵�
void MainFrame::menu()
{
	pvew->hide();
	gobang->hide();
	this->show();
}
