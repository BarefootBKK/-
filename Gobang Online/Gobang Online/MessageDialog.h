// MessageDialog.h
#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QtWidgets/QWidget>
#include "ui_MessageDialog.h"

class MessageDialog : public QDialog
{
	Q_OBJECT

		signals :
	void ai_level(int);

public:
	MessageDialog(QWidget *parent = Q_NULLPTR);	// ¹¹Ôìº¯Êý

	void SetMsgText(QString);
	bool IsOKPushed();

private slots:
	void okButtonCliked();
	void cancelButtonCliked();

private:
	Ui::MessaDialog ui;
	bool okState = false;
};

