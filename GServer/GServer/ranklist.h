// ranklist.h
#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#ifndef _RANKLIST_H_
#define _RANKLIST_H_

#include <QtWidgets/QApplication>
#include <QString>
#include <QDir>
#include <qDebug>

class RankList
{
public:
	RankList();

public:
	QString GetRankList();
	void ReadRankList();

};

#endif