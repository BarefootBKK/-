#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QtWidgets/QWidget>
#include <QDir>
#include "ui_Mainwindow.h"
#include "server.h"

class Mainwindow : public QWidget
{
	Q_OBJECT

public:
	Mainwindow(QWidget *parent = Q_NULLPTR);
	~Mainwindow();

private slots:
	void openServer();
	void newConn();

private:
	void initData();

private:
	Ui::MainwindowClass ui;
	Server * server;
	int serverState;
};
