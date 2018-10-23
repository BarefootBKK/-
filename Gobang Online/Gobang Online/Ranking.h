#pragma once



#include <QtWidgets/QWidget>
#include "ui_Ranking.h"


class Ranking : public QWidget
{
	Q_OBJECT
		signals :
	void back();
public:
	Ranking(QWidget *parent = Q_NULLPTR);	// 构造函数
	void initData();						// 初始化界面数据
	void setConnection();					// 建立信号与槽的连接


	public slots:
	// 槽函数
	void look();
	void Return();
	

	//void sendsignal();

private:
	Ui::FormRanking ui;




};