#pragma once



#include <QtWidgets/QWidget>
#include "ui_Ranking.h"


class Ranking : public QWidget
{
	Q_OBJECT
		signals :
	void back();
public:
	Ranking(QWidget *parent = Q_NULLPTR);	// ���캯��
	void initData();						// ��ʼ����������
	void setConnection();					// �����ź���۵�����


	public slots:
	// �ۺ���
	void look();
	void Return();
	

	//void sendsignal();

private:
	Ui::FormRanking ui;




};