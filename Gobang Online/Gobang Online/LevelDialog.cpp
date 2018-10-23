// LevelDialog.cpp
#include "LevelDialog.h"

LevelDialog::LevelDialog(QWidget * parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	this->setMinimumSize(400, 410);	// 窗口最小尺寸
	this->setMaximumSize(400, 410);	// 窗口最大尺寸
	setConnection();
}

void LevelDialog::setConnection()
{
	connect(ui.easyAI_button, SIGNAL(clicked()), this, SLOT(setEasyLevel()));
	connect(ui.normalAI_button, SIGNAL(clicked()), this, SLOT(setNormalLevel()));
	connect(ui.middleAI_button, SIGNAL(clicked()), this, SLOT(setMiddleLevel()));
	connect(ui.difficultAI_button, SIGNAL(clicked()), this, SLOT(setDiffLevel()));
	connect(ui.nightmareAI_button, SIGNAL(clicked()), this, SLOT(setNightmareLevel()));
}

void LevelDialog::setEasyLevel()
{
	emit ai_level(EASY);
	this->hide();
}

void LevelDialog::setNormalLevel()
{
	emit ai_level(NORMAL);
	this->hide();
}

void LevelDialog::setMiddleLevel()
{
	emit ai_level(MIDDLE);
	this->hide();
}

void LevelDialog::setDiffLevel()
{
	emit ai_level(DIFFICULT);
	this->hide();
}

void LevelDialog::setNightmareLevel()
{
	emit ai_level(NIGHTMARE);
	this->hide();
}
