// LevelDialog.h
#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#include <QtWidgets/QWidget>
#include "ui_level.h"

#define EASY		2
#define NORMAL		3
#define MIDDLE		4
#define DIFFICULT	5
#define NIGHTMARE	6

class LevelDialog : public QDialog
{
	Q_OBJECT

signals :
	void ai_level(int);

public:
	LevelDialog(QWidget *parent = Q_NULLPTR);	// ¹¹Ôìº¯Êý

private slots:
	void setConnection();
	void setEasyLevel();
	void setNormalLevel();
	void setMiddleLevel();
	void setDiffLevel();
	void setNightmareLevel();

private:
	Ui::LevelDialog ui;
	int level;
};
