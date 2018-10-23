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
	void regist(QString);			// ע��
signals:
	void reconnect();				// ����
signals:
	void send_msg(QString);			// 

public:
	MainFrame(QWidget *parent = Q_NULLPTR);	//��������

	void startSocketThread();
	void initData();						// ��ʼ����������
	void setConnection();					// �����ź���۵�����

public slots:
	// �ۺ���
	void online();					// ������ս
	void exit();					// �˳�����
	void pvp();						// ����
	void pve();						// �˻�
	void menu();					// ���˵�
	void Sign();					// ��¼
	void PlayMusic();					// ����
	void replayBoard();				// �ط�
	void ranking();					// ���а�
	void showHelp();
	void reshow();					// 
	void processReq(QStringList);	// ������Ϣ
	void loginState(AccountInfo);	// ��½״̬
	void reconnThread();			// �����߳�
	void startReconn();				// ��ʼ����
	void setConnState(bool);		// ��������״̬
	void setMyName();				// ��ʾ�ҵ��ǳ�
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
	
	// ����
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
	// �˺�
	AccountInfo my_accInfo;
	AccountInfo op_accInfo;
	Music music;
	int music_state = 0;
	int first;
	int last_req;
};
