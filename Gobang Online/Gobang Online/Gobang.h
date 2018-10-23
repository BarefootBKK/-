// Gobang.h
#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QtWidgets/QWidget>
#include <QFileDialog>
#include "ui_Gobang.h"

class Gobang : public QWidget
{
	Q_OBJECT

signals:
	void back_to();
signals:
	void boardMsg(QString);

public:
	Gobang(QWidget *parent = Q_NULLPTR);	// 构造函数
	void initData();						// 初始化界面数据

public slots:
	// 槽函数
	void drawChess();	// 画棋子
	void undo();		// 悔棋
	void restart();		// 重新开始
	void backToMenu();
	void save();
	void sendChessInfo();
	void readChessInfo(QString);
	void setLevel(int);
	void initBoard(int, int);

private:
	Ui::GobangClass ui;
	CManager * manager;
};

