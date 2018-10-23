// Pve.h
#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QtWidgets/QWidget>
#include "ui_Pve.h"
#include"cmanager.h"

class Pve : public QWidget
{
	Q_OBJECT

signals :
	void back_to();
signals:
	void boardMsg(QString);

public:
	Pve(QWidget *parent = Q_NULLPTR);	// ���캯��
	void initData();						// ��ʼ����������
	void setConnection();					// �����ź���۵�����

	public slots:
	// �ۺ���
	void drawChess();	// ������
	void undo();		// ����
	void restart();		// ���¿�ʼ
	void backToMenu();
	void save();
	void sendChessInfo();
	void readChessInfo(QString);

private:
	Ui::FormPve ui;
	CManager *manager;
};

