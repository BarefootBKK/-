// pve.cpp
#include "Pve.h"


// 构造函数
Pve::Pve(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->initData();	// 初始化数据
}

// 初始化数据
void Pve::initData()
{
	// 固定窗口大小
	this->setMinimumSize(1250, 900);	// 窗口最小尺寸
	this->setMaximumSize(1250, 900);	// 窗口最大尺寸
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);	//禁止最大化
	this->setConnection();
	manager = new CManager();
}

// 建立信号与槽的连接
void Pve::setConnection()
{
	connect(ui.checkerboard_label, SIGNAL(clicked()), this, SLOT(drawChess()));
	connect(ui.checkerboard_label, SIGNAL(chessed()), this, SLOT(sendChessInfo()));
	connect(ui.undo_Button, SIGNAL(clicked()), this, SLOT(undo()));
	connect(ui.restart_Button, SIGNAL(clicked()), this, SLOT(restart()));
	connect(ui.mainMenu_Button, SIGNAL(clicked()), this, SLOT(backToMenu()));
	connect(ui.save_Button, SIGNAL(clicked()), this, SLOT(save()));
}

// 画棋子
void Pve::drawChess()
{
	//ui.checkerboard_label->Draw();
}

void Pve::undo()
{
	ui.checkerboard_label->Undo();
}

void Pve::restart()
{
	ui.checkerboard_label->Restart();
}

void Pve::backToMenu()
{
	emit back_to();
}

void Pve::sendChessInfo()
{
	//emit boardMsg(manager->getEncryptInfo(ui.checkerboard_label->GetChessInfo()));
}

void Pve::readChessInfo(QString chess)
{
	//ui.checkerboard_label->DrawOpponent(manager->getParsedInfo(chess));
}

void Pve::save()
{
	//manager->SaveBoard(ui.checkerboard_label->GetBoardInfo());
}