// pve.cpp
#include "Pve.h"


// ���캯��
Pve::Pve(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->initData();	// ��ʼ������
}

// ��ʼ������
void Pve::initData()
{
	// �̶����ڴ�С
	this->setMinimumSize(1250, 900);	// ������С�ߴ�
	this->setMaximumSize(1250, 900);	// �������ߴ�
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);	//��ֹ���
	this->setConnection();
	manager = new CManager();
}

// �����ź���۵�����
void Pve::setConnection()
{
	connect(ui.checkerboard_label, SIGNAL(clicked()), this, SLOT(drawChess()));
	connect(ui.checkerboard_label, SIGNAL(chessed()), this, SLOT(sendChessInfo()));
	connect(ui.undo_Button, SIGNAL(clicked()), this, SLOT(undo()));
	connect(ui.restart_Button, SIGNAL(clicked()), this, SLOT(restart()));
	connect(ui.mainMenu_Button, SIGNAL(clicked()), this, SLOT(backToMenu()));
	connect(ui.save_Button, SIGNAL(clicked()), this, SLOT(save()));
}

// ������
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