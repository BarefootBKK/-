// Onlinepvp.cpp
#include "Onlinepvp.h"

#include"chessboard.h"

// 构造函数
Onlinepvp::Onlinepvp(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->initData();	// 初始化数据
}

// 初始化数据
void Onlinepvp::initData()
{
	// 固定窗口大小
	this->setMinimumSize(1250, 900);	// 窗口最小尺寸
	this->setMaximumSize(1250, 900);	// 窗口最大尺寸
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);	//禁止最大化
	this->setConnection();
	this->isMyTurn = false;
	this->time_count = 25;
	ui.time_lcdNumber->display("00:25");

	manager = new CManager();
}

// 建立信号与槽的连接
void Onlinepvp::setConnection()
{
	connect(ui.checkerboard_label, SIGNAL(clicked()), this, SLOT(drawChess()));
	connect(ui.checkerboard_label, SIGNAL(chessed()), this, SLOT(sendChessInfo()));
	connect(ui.undo_Button, SIGNAL(clicked()), this, SLOT(undo()));
	connect(ui.defeat_Button, SIGNAL(clicked()), this, SLOT(defeat()));
	connect(ui.save_Button, SIGNAL(clicked()), this, SLOT(save()));
}

// 开始计时线程
void Onlinepvp::startTimeThread()
{
	countTimeThread();
}

// 计时器线程
void Onlinepvp::countTimeThread()
{
	time_thread = new QThread();
	timer = new QTimer();
	timer->moveToThread(time_thread);
	timer->setInterval(1000);
	connect(time_thread, SIGNAL(started()), timer, SLOT(start()));
	connect(timer, SIGNAL(timeout()), this, SLOT(setTime()));

	time_thread->start();
}

// 初始化棋盘
void Onlinepvp::initBoard(int pattern, int first)
{
	this->first = first;
	
	if (first == PLAYER_1)
		isMyTurn = true;

	getHint();

	ui.checkerboard_label->InitChessBoard(pattern, first);
}

// 设置时间
void Onlinepvp::setTime()
{
	time_count--;

	if (time_count < 0) {
		time_count = 25;
	}

	QString str_time;

	if (time_count >= 10) {
		str_time = TIME_FORMAT_1 + QString::number(time_count);
	}
	else {
		str_time = TIME_FORMAT_2 + QString::number(time_count);
	}

	ui.time_lcdNumber->display(str_time);
}

void Onlinepvp::getHint()
{
	if (isMyTurn)
		ui.whosturn_label->setText("你的回合");
	else 
		ui.whosturn_label->setText("对手回合");
}

// 画棋子
void Onlinepvp::drawChess()
{
	ui.checkerboard_label->Draw();
}

// 悔棋
void Onlinepvp::undo()
{
	ui.checkerboard_label->Undo();
	ui.checkerboard_label->Undo();
}

// 认输
void Onlinepvp::defeat() 
{
	messageDialog.SetMsgText("确定要认输吗?");

	if (messageDialog.IsOKPushed())
		emit back();
}

// 发送棋子信息
void Onlinepvp::sendChessInfo()
{
	time_count = 25;
	emit boardMsg(manager->getEncryptInfo(ui.checkerboard_label->GetChessInfo()));
}

// 读取棋子信息
void Onlinepvp::readChessInfo(QString chess)
{
	ui.checkerboard_label->DrawOpponent(manager->getParsedInfo(chess));
}

// 保存棋局
void Onlinepvp::save()
{
	QString filename = QFileDialog::getSaveFileName(this,
		tr("保存棋局"), "", tr("*.binfo")); //
	QFileInfo fileInfo(filename);

	if (!filename.isNull())
	{
		if (!fileInfo.exists())
		{
			manager->SaveBoard(ui.checkerboard_label->GetBoardInfo(), filename);
		}
		else
		{
			QString currentPath = ":/Gobang/Images/Hint/提示.png";
			QMessageBox message(QMessageBox::NoIcon, "提示信息", "文件已存在");
			message.setIconPixmap(QPixmap(currentPath));
			message.exec();
		}
	}
}