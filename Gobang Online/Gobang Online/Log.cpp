// Log.cpp
#include "Log.h"

// 构造函数
Log::Log(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->initData();	// 初始化数据
}

// 初始化数据
void Log::initData()
{
	// 固定窗口大小
	this->setMinimumSize(600, 600);	// 窗口最小尺寸
	this->setMaximumSize(600, 600);	// 窗口最大尺寸
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);	//禁止最大化
	this->regHide();
	this->setConnection();
}

// 建立信号与槽的连接
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
		QMessageBox::information(this, "hint", "请输入帐号或密码！");
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
	ui.hint_label->setText("登录");

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
	ui.hint_label->setText("注册");

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
		QMessageBox::information(this, "hint", "两次密码不一致");
	}
	else if (ui.account_edit->text().length() < 1 ||
		ui.nickname_edit->text().length() < 1 ||
		ui.password_edit->text().length() < 1 ||
		ui.confirm_edit->text().length() < 1)
	{
		QMessageBox::information(this, "hint", "请填写完整信息");
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
		QMessageBox::information(this, "hint", "注册成功！");
		regHide();
	}
	else if (req == ACC_EXIST)
	{
		QMessageBox::information(this, "hint", "帐号已存在！");
	}
	else if (req == ACC_NONE)
	{
		QMessageBox::information(this, "hint", "帐号不存在！");
	}
	else if (req == LOG_IN_FAILED_A)
	{
		QMessageBox::information(this, "hint", "密码错误！");
	}
	else if (req == LOG_IN_FAILED_S)
	{
		QMessageBox::information(this, "hint", "服务器异常！");
	}
	else if (req == ACC_LOGINED)
	{
		QMessageBox::information(this, "hint", "该账号已在另一台设备上登录！");
	}
}
