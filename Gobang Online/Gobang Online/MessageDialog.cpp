// MessageDialog.cpp
#include "MessageDialog.h"

// ���캯��
MessageDialog::MessageDialog(QWidget * parent)
{
	ui.setupUi(this);

	this->setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
	this->setModal(true);
	connect(ui.ok_button, SIGNAL(clicked()), this, SLOT(okButtonCliked()));
	connect(ui.cancel_button, SIGNAL(clicked()), this, SLOT(cancelButtonCliked()));
}

// �����ı�
void MessageDialog::SetMsgText(QString text)
{
	ui.msg_label->setText(text);
	this->show();
	this->exec();
}

// �ж�ȷ�����Ƿ���
bool MessageDialog::IsOKPushed()
{
	return okState;
}

// ȷ��������
void MessageDialog::okButtonCliked()
{
	okState = true;
	this->hide();
}

// ȡ��������
void MessageDialog::cancelButtonCliked()
{
	okState = false;
	this->hide();
}
