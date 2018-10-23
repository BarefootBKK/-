// Log.cpp
#include "Log.h"

// ���캯��
Log::Log(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->initData();	// ��ʼ������
}

// ��ʼ������
void Log::initData()
{
	// �̶����ڴ�С
	this->setMinimumSize(600, 600);	// ������С�ߴ�
	this->setMaximumSize(600, 600);	// �������ߴ�
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);	//��ֹ���
	this->regHide();
	this->setConnection();
}

// �����ź���۵�����
void Log::setConnection()
{
	connect(ui.login_button, SIGNAL(clicked()), this, SLOT(logIn()));
	connect(ui.exit_button, SIGNAL(clicked()), this, SLOT(backTo()));
	connect(ui.signin_button, SIGNAL(clicked()), this, SLOT(regShow()));
	connect(ui.back_button, SIGNAL(clicked()), this, SLOT(regHide()));
	connect(ui.register_button, SIGNAL(clicked()), this, SLOT(sign_in()));
}

void Log::logIn()
{
	QString str_msg = QString::number(LOG_IN) + "|" +
						ui.account_edit->text() + "|" +
						ui.password_edit->text();

	if (ui.account_edit->text().length() < 1 ||
		ui.password_edit->text().length() < 1)
		QMessageBox::information(this, "hint", "�������ʺŻ����룡");
	else
	{
		emit log_msg(str_msg);
	}
}

void Log::backTo()
{
	emit back();
}

void Log::regHide()
{
	ui.nickname_label->hide();
	ui.nickname_edit->hide();
	ui.confirm_edit->hide();
	ui.confirm_label->hide();
	ui.back_button->hide();
	ui.register_button->hide();

	ui.login_button->show();
	ui.signin_button->show();
	ui.exit_button->show();
	ui.hint_label->setText("��¼");

	clearText();
}

void Log::regShow()
{
	ui.nickname_label->show();
	ui.nickname_edit->show();
	ui.confirm_edit->show();
	ui.confirm_label->show();
	ui.back_button->show();
	ui.register_button->show();
	ui.hint_label->setText("ע��");

	ui.login_button->hide();
	ui.signin_button->hide();
	ui.exit_button->hide();

	clearText();
}

void Log::sign_in()
{
	QString str_msg  =	QString::number(SIGN_IN) + "|" +
						ui.account_edit->text() + "|" +
						ui.password_edit->text() + "|" +
						ui.nickname_edit->text();

	if (ui.password_edit->text() != ui.confirm_edit->text())
	{
		QMessageBox::information(this, "hint", "�������벻һ��");
	}
	else if (ui.account_edit->text().length() < 1 ||
		ui.nickname_edit->text().length() < 1 ||
		ui.password_edit->text().length() < 1 ||
		ui.confirm_edit->text().length() < 1)
	{
		QMessageBox::information(this, "hint", "����д������Ϣ");
	}
	else
	{
		emit log_msg(str_msg);
	}
}

void Log::clearText()
{
	ui.account_edit->setText("");
	ui.nickname_edit->setText("");
	ui.confirm_edit->setText("");
	ui.password_edit->setText("");
}

void Log::makeRoom(QString msg)
{
	emit log_msg(msg);
}

void Log::analyzeMsg(QStringList list)
{
	int req = list.at(0).toInt();

	if (req == LOG_IN_SUCC)
	{
		AccountInfo accInfo;
		accInfo.account = list.at(1);
		accInfo.nickname = list.at(2);
		accInfo.winned_num = list.at(3);
		accInfo.failed_num = list.at(4);
		accInfo.scores = list.at(5);

		emit log_in(accInfo);

		clearText();
		backTo();
	}
	else if (req == SIGN_IN_SUCC)
	{
		QMessageBox::information(this, "hint", "ע��ɹ���");
		regHide();
	}
	else if (req == ACC_EXIST)
	{
		QMessageBox::information(this, "hint", "�ʺ��Ѵ��ڣ�");
	}
	else if (req == ACC_NONE)
	{
		QMessageBox::information(this, "hint", "�ʺŲ����ڣ�");
	}
	else if (req == LOG_IN_FAILED_A)
	{
		QMessageBox::information(this, "hint", "�������");
	}
	else if (req == LOG_IN_FAILED_S)
	{
		QMessageBox::information(this, "hint", "�������쳣��");
	}
	else if (req == ACC_LOGINED)
	{
		QMessageBox::information(this, "hint", "���˺�������һ̨�豸�ϵ�¼��");
	}
}
