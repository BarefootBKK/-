// Gobang.cpp
#include "help.h"

// 构造函数
help::help(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->initData();	// 初始化数据
}

void help::initData()
{
	// 固定窗口大小
	this->setConnection();
	this->setMinimumSize(1050, 900);	// 窗口最小尺寸
	this->setMaximumSize(1050, 900);	// 窗口最大尺寸
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);	//禁止最大化
}
void help::setConnection()
{
	// 主界面界面按钮的信号与槽
	connect(ui.return_Button, SIGNAL(clicked()), this, SLOT(back()));
	connect(ui.step_1_radioButton, SIGNAL(clicked()), this, SLOT(step_one()));
	connect(ui.step_2_radioButton, SIGNAL(clicked()), this, SLOT(step_two()));
	connect(ui.step_3_radioButton, SIGNAL(clicked()), this, SLOT(step_three()));
}

// 返回主菜单
void help::back() 
{
	emit back_to();
}

// 帮助1
void help::step_one()
{
	ui.help_label->setPixmap(QPixmap(":/Gobang/Image/help/1.JPG"));
	ui.hint_label->setText("点击任一未有棋子的落子点可下棋");
}

// 帮助2
void help::step_two()
{
	ui.help_label->setPixmap(QPixmap(":/Gobang/Image/help/2.JPG"));
	ui.hint_label->setText("黑棋和白棋轮流进行进攻或防守");
}

// 帮助3
void help::step_three()
{
	ui.help_label->setPixmap(QPixmap(":/Gobang/Image/help/3.JPG"));
	ui.hint_label->setText("当其中一色棋子形成五子连珠时，该方获胜");
}
