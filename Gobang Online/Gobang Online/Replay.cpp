// Replay.cpp
#include "Replay.h"

// 构造函数
Replay::Replay(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->initData();	// 初始化数据
}

// 初始化数据
void Replay::initData()
{
	manager = new CManager();
	// 固定窗口大小
	this->setMinimumSize(1250, 900);	// 窗口最小尺寸
	this->setMaximumSize(1250, 900);	// 窗口最大尺寸
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);	//禁止最大化
	this->setConnection();

	this->chess_pos = 0;
	this->play_speed = 1000;
	this->isThreadRunning = false;
	this->isPlaused = false;
	this->isReadFile = false;
	PlaybackMode();
	ui.checkerboard_label->InitChessBoard(REPLAY, PLAYER_1);
}

// 建立信号与槽的连接
void Replay::setConnection()
{
	connect(ui.next_Button, SIGNAL(clicked()), this, SLOT(Next()));
	connect(ui.last_Button, SIGNAL(clicked()), this, SLOT(Last()));
	connect(ui.return_Button, SIGNAL(clicked()), this, SLOT(Return()));
	connect(ui.openboard_button, SIGNAL(clicked()), this, SLOT(ReadBoardInfo()));
	connect(ui.play_button, SIGNAL(clicked()), this, SLOT(PlayState()));
	connect(ui.playPattern_combox, SIGNAL(currentIndexChanged(int)), this, SLOT(PlaybackMode()));
	connect(ui.speed_SpinBox, SIGNAL(valueChanged(double)), this, SLOT(SetSpeed()));
}

void Replay::drawChess(int pos, int step_state)
{
	if (pos >= 0 && pos < (int)boardInfo.size())
	{
		ui.checkerboard_label->DrawNextChess(boardInfo[pos], step_state);

		if (play_mode == AUTO_PLAY)
			chess_pos++;
	}
	else if (pos == (int)boardInfo.size() && play_mode == AUTO_PLAY)
	{
		exitThread();
		ui.play_button->setText("播放");
	}
}

void Replay::autoPlayStarted()
{
	isThreadRunning = true;
	
	replay_thread = new ReplayThread(0);
	replay_thread->SetSpeed(play_speed);
	connect(replay_thread, SIGNAL(next_step(int, int)), this, SLOT(drawChess(int, int)));
	connect(this, SIGNAL(play_state(bool)), replay_thread, SLOT(PauseReplay(bool)));
	connect(this, SIGNAL(play_stop()), replay_thread, SLOT(StopReplay()));
	connect(this, SIGNAL(speed(int)), replay_thread, SLOT(SetSpeed(int)));

	replay_thread->start();
}

void Replay::exitThread()
{
	emit play_stop();
	isPlaused = true;
	isThreadRunning = false;
	replay_thread->quit();
}

void Replay::clearBoard()
{
	ui.checkerboard_label->InitChessBoard(REPLAY, PLAYER_1);
	ui.checkerboard_label->Draw();
}

void Replay::Next()
{
	if (chess_pos < (int)boardInfo.size() )
	{
		drawChess(chess_pos++, NEXT_CHESS);
	}
	else if (chess_pos == (int)boardInfo.size())
	{
		QString currentPath = QDir::currentPath() + "/Images/Hint/提示.png";
		QMessageBox message(QMessageBox::NoIcon, "诶诶", "这是最后一步了！");
		message.setIconPixmap(QPixmap(currentPath));
		message.exec();
	}
}

void Replay::Last()
{
	if (chess_pos > 0 && boardInfo.size() > 0)
	{
		drawChess(chess_pos--, LAST_CHESS);
	}
	else if (chess_pos == 0)
	{
		QString currentPath = QDir::currentPath() + "/Images/Hint/提示.png";
		QMessageBox message(QMessageBox::NoIcon, "诶诶", "没有上一步了！");
		message.setIconPixmap(QPixmap(currentPath));
		message.exec();
	}
}

void Replay::Play()
{
	if (isReadFile)
	{
		if (isThreadRunning)
		{
			emit play_state(GO_PLAY);
		}
		else
		{
			clearBoard();
			autoPlayStarted();
		}
		isPlaused = false;
		ui.play_button->setText("暂停");
	}
}

void Replay::Pause()
{
	if (isReadFile)
	{
		if (isThreadRunning)
		{
			emit play_state(PLAY_PAUSE);
		}
		isPlaused = true;
		ui.play_button->setText("播放");
	}
}

void Replay::SetSpeed()
{
	double value = ui.speed_SpinBox->value();
	double temp_speed;
	
	if (value == 0.5)
	{
		temp_speed = 2000;
	}
	else if (value == 1.5)
	{
		temp_speed = 750;
	}
	else if (value == 2)
	{
		temp_speed = 500;
	}
	else
	{
		temp_speed = 1000;
	}

	play_speed = temp_speed;

	emit speed(play_speed);
}

void Replay::PlaybackMode()
{
	this->chess_pos = 0;

	if (ui.playPattern_combox->currentIndex() == 0)
	{
		clearBoard();
		play_mode = AUTO_PLAY;
		AutoPlay();
	}
	else
	{
		clearBoard();
		play_mode = MANUAL_PALY;
		if (isThreadRunning)
		{
			exitThread();
		}
			
		ManualPlay();
	}
}

void Replay::AutoPlay()
{
	ui.play_button->show();
	ui.speed_SpinBox->show();
	ui.last_Button->hide();
	ui.next_Button->hide();
}

void Replay::ManualPlay()
{
	ui.play_button->hide();
	ui.speed_SpinBox->hide();
	ui.last_Button->show();
	ui.next_Button->show();
}

void Replay::Return()
{
	clearBoard();
	emit back();
}

void Replay::ReadBoardInfo()
{
	QString filename = QFileDialog::getOpenFileName(this, tr("打开棋局文件"), ".",
													tr("棋局文件(*.binfo)"));
	
	if (!filename.isNull())
	{
		if (isThreadRunning)
		{
			exitThread();
		}

		if (isReadFile)
		{
			clearBoard();
		}

		boardInfo = manager->ReadBoard(filename);

		if (!boardInfo.empty())
		{
			chess_pos = 0;
			isReadFile = true;

			if (play_mode == AUTO_PLAY)
			{
				autoPlayStarted();
				ui.play_button->setText("暂停");
			}
			else
				Next();
		}
		else
		{
			QString currentPath = QDir::currentPath() + ":/Gobang/Images/Hint/提示.png";
			QMessageBox message(QMessageBox::NoIcon, "emmmm", "这是无效或者空的棋局文件...");
			message.setIconPixmap(QPixmap(currentPath));
			message.exec();
		}
	}
}

void Replay::PlayState()
{
	if (isPlaused)
		Play();
	else
		Pause();
}

