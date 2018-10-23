// cmanager.h
// ����
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
	int getWinner(int **, int, int, int);				// �ж�ʤ��
	QString getEncryptInfo(ChessNode *);				// ��ȡ���ܵ�������Ϣ
	ChessNode * getParsedInfo(QString);					// ��ȡ�������������Ϣ
	void SaveBoard(QVector<ChessNode>, QString);		// �������
	QVector<ChessNode> ReadBoard(QString fileName);		//�������

private:
	ChessNode * chess;
	QStringList files;
};
#endif