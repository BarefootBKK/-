// MessageDialog.cpp
#include "MessageDialog.h"

// 构造函数
MessageDialog::MessageDialog(QWidget * parent)
{
	ui.setupUi(this);

	this->setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	this->setModal(true);
	connect(ui.ok_button, SIGNAL(clicked()), this, SLOT(okButtonCliked()));
	connect(ui.cancel_button, SIGNAL(clicked()), this, SLOT(cancelButtonCliked()));
}

// 设置文本
void MessageDialog::SetMsgText(QString text)
{
	ui.msg_label->setText(text);
	this->show();
	this->exec();
}

// 判断确定键是否按下
bool MessageDialog::IsOKPushed()
{
	return okState;
}

// 确定键按下
void MessageDialog::okButtonCliked()
{
	okState = true;
	this->hide();
}

// 取消键按下
void MessageDialog::cancelButtonCliked()
{
	okState = false;
	this->hide();
}
