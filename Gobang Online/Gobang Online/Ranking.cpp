// Log.cpp
#include "Ranking.h"

#include <QMessageBox>
#include"qdebug.h"
#include"QStringListModel.h"
//#include"MainFrame.h"

// 构造函数
Ranking::Ranking(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->initData();	// 初始化数据
}

// 初始化数据
void Ranking::initData()
{
	// 固定窗口大小
	this->setMinimumSize(600, 600);	// 窗口最小尺寸
	this->setMaximumSize(600, 600);	// 窗口最大尺寸
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);	//禁止最大化
	this->setConnection();
}

// 建立信号与槽的连接
void Ranking::setConnection()
{
	//connect(ui.look_Button, SIGNAL(clicked()), this, SLOT(look()));
	
	connect(ui.return_Button, SIGNAL(clicked()), this, SLOT(Return()));
}


void Ranking::look()//通过此函数获得排名/可修改
{
	QStringList num;
	num << QString("1") << QString("2") << QString("3") << QString("4");
	QStringListModel *model = new QStringListModel(num);
	//ui.listView->setModel(model);
}

void Ranking::Return()
{
	emit back();
}

