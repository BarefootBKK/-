// Gobang.h
#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QtWidgets/QWidget>
#include <qDebug>
#include "ui_help.h"

class help : public QWidget
{
	Q_OBJECT

		signals :
	void back_to();
signals:
	void boardMsg(QString);

public slots:
	void back();
	void step_one();
	void step_two();
	void step_three();

public:
	help(QWidget *parent = Q_NULLPTR);	// 构造函数
	void initData();						// 初始化界面数据
	void setConnection();
	
	
	

private:
	Ui::Formhelp ui;
	
};

#pragma once
