// Gobang.cpp
#include "Gobang.h"
#include"cmanager.h"

// ���캯��
Gobang::Gobang(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->initData();	// ��ʼ������
}

// ��ʼ����
void Gobang::initData()
{
	// �̶����ڴ�С
	this->setMinimumSize(1250, 900);	// ������С�ߴ�
	this->setMaximumSize(1250, 900);	// �������ߴ�
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);	//��ֹ���

	connect(ui.checkerboard_label, SIGNAL(clicked()), this, SLOT(drawChess()));
	connect(ui.checkerboard_label, SIGNAL(chessed()), this, SLOT(sendChessInfo()));
	connect(ui.undo_button, SIGNAL(clicked()), this, SLOT(undo()));
	connect(ui.restart_button, SIGNAL(clicked()), this, SLOT(restart()));
	connect(ui.mainMenu_button, SIGNAL(clicked()), this, SLOT(backToMenu()));
	connect(ui.save_button, SIGNAL(clicked()), this, SLOT(save()));

	manager = new CManager();
}

// ��ʼ������
void Gobang::initBoard(int pattern, int first)
{
	ui.checkerboard_label->InitChessBoard(pattern, first);

	if (pattern == PVE)
		connect(ui.mainMenu_button, SIGNAL(clicked()), ui.checkerboard_label, SLOT(Gameover()));
}

// ������
void Gobang::drawChess()
{
	ui.checkerboard_label->Draw();
}

// ����
void Gobang::undo()
{
	ui.checkerboard_label->Undo();
	ui.checkerboard_label->Undo();
}

// ���¿�ʼ
void Gobang::restart()
{
	ui.checkerboard_label->Restart();
}

// �������˵�
void Gobang::backToMenu()
{
	emit back_to();
}

// ����������Ϣ
void Gobang::sendChessInfo()
{
	emit boardMsg(manager->getEncryptInfo(ui.checkerboard_label->GetChessInfo()));
}

// ��ȡ������Ϣ
void Gobang::readChessInfo(QString chess)
{
	ui.checkerboard_label->DrawOpponent(manager->getParsedInfo(chess));
}

// �����˻��Ѷ�
void Gobang::setLevel(int level)
{
	ui.checkerboard_label->SetAILevel(level);
}

// �������
void Gobang::save() 
{
	QString filename = QFileDialog::getSaveFileName(this, 
								tr("�������"), "", tr("*.binfo")); //
	QFileInfo fileInfo(filename);

	if (!filename.isNull())
	{
		if (!fileInfo.exists())
		{
			manager->SaveBoard(ui.checkerboard_label->GetBoardInfo(), filename);
		}
		else
		{
			QString currentPath = ":/Gobang/Images/Hint/��ʾ.png";
			QMessageBox message(QMessageBox::NoIcon, "��ʾ��Ϣ", "�ļ��Ѵ���");
			message.setIconPixmap(QPixmap(currentPath));
			message.exec();
		}
	}
}