// Log.cpp
#include "Ranking.h"

#include <QMessageBox>
#include"qdebug.h"
#include"QStringListModel.h"
//#include"MainFrame.h"

// ���캯��
Ranking::Ranking(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	this->initData();	// ��ʼ������
}

// ��ʼ������
void Ranking::initData()
{
	// �̶����ڴ�С
	this->setMinimumSize(600, 600);	// ������С�ߴ�
	this->setMaximumSize(600, 600);	// �������ߴ�
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);	//��ֹ���
	this->setConnection();
}

// �����ź���۵�����
void Ranking::setConnection()
{
	//connect(ui.look_Button, SIGNAL(clicked()), this, SLOT(look()));
	
	connect(ui.return_Button, SIGNAL(clicked()), this, SLOT(Return()));
}


void Ranking::look()//ͨ���˺����������/���޸�
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

