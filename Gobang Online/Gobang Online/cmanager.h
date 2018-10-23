// cmanager.h
// 中文
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#ifndef _CMANAGER_H_
#define _CMANAGER_H_

#include <fstream>
#include <iostream>
#include <QVector>
#include<Qdir.h>
#include <QMessageBox>
#include <qDebug>
#include "globalVal.h"

using namespace std;

class CManager
{
public:
	CManager();
	~CManager();

public:
	int getWinner(int **, int, int, int);				// 判断胜负
	QString getEncryptInfo(ChessNode *);				// 获取加密的棋子信息
	ChessNode * getParsedInfo(QString);					// 获取解析后的棋子信息
	void SaveBoard(QVector<ChessNode>, QString);		// 保存棋局
	QVector<ChessNode> ReadBoard(QString fileName);		//读入棋局

private:
	ChessNode * chess;
	QStringList files;
};
#endif