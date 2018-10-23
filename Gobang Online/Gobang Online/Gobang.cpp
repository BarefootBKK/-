// Gobang.cpp
#include "Gobang.h"
#include"cmanager.h"

// 构造函数
Gobang::Gobang(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->initData();	// 初始化数据
}

// 初始化数
void Gobang::initData()
{
	// 固定窗口大小
	this->setMinimumSize(1250, 900);	// 窗口最小尺寸
	this->setMaximumSize(1250, 900);	// 窗口最大尺寸
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);	//禁止最大化

	connect(ui.checkerboard_label, SIGNAL(clicked()), this, SLOT(drawChess()));
	connect(ui.checkerboard_label, SIGNAL(chessed()), this, SLOT(sendChessInfo()));
	connect(ui.undo_button, SIGNAL(clicked()), this, SLOT(undo()));
	connect(ui.restart_button, SIGNAL(clicked()), this, SLOT(restart()));
	connect(ui.mainMenu_button, SIGNAL(clicked()), this, SLOT(backToMenu()));
	connect(ui.save_button, SIGNAL(clicked()), this, SLOT(save()));

	manager = new CManager();
}

// 初始化棋盘
void Gobang::initBoard(int pattern, int first)
{
	ui.checkerboard_label->InitChessBoard(pattern, first);

	if (pattern == PVE)
		connect(ui.mainMenu_button, SIGNAL(clicked()), ui.checkerboard_label, SLOT(Gameover()));
}

// 画棋子
void Gobang::drawChess()
{
	ui.checkerboard_label->Draw();
}

// 悔棋
void Gobang::undo()
{
	ui.checkerboard_label->Undo();
	ui.checkerboard_label->Undo();
}

// 重新开始
void Gobang::restart()
{
	ui.checkerboard_label->Restart();
}

// 返回主菜单
void Gobang::backToMenu()
{
	emit back_to();
}

// 发送棋子信息
void Gobang::sendChessInfo()
{
	emit boardMsg(manager->getEncryptInfo(ui.checkerboard_label->GetChessInfo()));
}

// 读取棋子信息
void Gobang::readChessInfo(QString chess)
{
	ui.checkerboard_label->DrawOpponent(manager->getParsedInfo(chess));
}

// 设置人机难度
void Gobang::setLevel(int level)
{
	ui.checkerboard_label->SetAILevel(level);
}

// 保存棋局
void Gobang::save() 
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