// Gobang.cpp
#include "help.h"

// ���캯��
help::help(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->initData();	// ��ʼ������
}

void help::initData()
{
	// �̶����ڴ�С
	this->setConnection();
	this->setMinimumSize(1050, 900);	// ������С�ߴ�
	this->setMaximumSize(1050, 900);	// �������ߴ�
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);	//��ֹ���
}
void help::setConnection()
{
	// ��������水ť���ź����
	connect(ui.return_Button, SIGNAL(clicked()), this, SLOT(back()));
	connect(ui.step_1_radioButton, SIGNAL(clicked()), this, SLOT(step_one()));
	connect(ui.step_2_radioButton, SIGNAL(clicked()), this, SLOT(step_two()));
	connect(ui.step_3_radioButton, SIGNAL(clicked()), this, SLOT(step_three()));
}

// �������˵�
void help::back() 
{
	emit back_to();
}

// ����1
void help::step_one()
{
	ui.help_label->setPixmap(QPixmap(":/Gobang/Image/help/1.JPG"));
	ui.hint_label->setText("�����һδ�����ӵ����ӵ������");
}

// ����2
void help::step_two()
{
	ui.help_label->setPixmap(QPixmap(":/Gobang/Image/help/2.JPG"));
	ui.hint_label->setText("����Ͱ����������н��������");
}

// ����3
void help::step_three()
{
	ui.help_label->setPixmap(QPixmap(":/Gobang/Image/help/3.JPG"));
	ui.hint_label->setText("������һɫ�����γ���������ʱ���÷���ʤ");
}
