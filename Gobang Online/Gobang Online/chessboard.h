// chessboard.h
#pragma once
#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#ifndef _CHESSBOARD_H_
#define _CHESSBOARD_H_

#include <QLabel>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>
#include <QMessageBox>
#include <qDebug>
#include <QPoint>
#include <QVector>
#include "MessageDialog.h"
#include "LevelDialog.h"
#include "aithread.h"
#include "cmanager.h"
#include "globalVal.h"

#define DEFAULT_PATTERN		0

class ChessBoard : public QLabel
{
	Q_OBJECT

public:
	explicit ChessBoard(QWidget *parent = 0);	// ���캯��
	~ChessBoard();								// ��������

/*===========================�źź���=============================*/
signals:
	void clicked();		// ������ź�
signals:
	void chessed();		// �����ź�
signals:
	void ai_step(int, int);
signals:
	void ai_undo();
signals:
	void ai_restart(int);
signals:
	void ai_gameover();
/*================================================================*/

protected:
/*=======================���غ���=================================*/
	virtual void paintEvent(QPaintEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
/*================================================================*/

public:
/*======================public��������============================*/
	void InitChessBoard(int, int);			// ��ʼ������
	void SetPattern(const int);				// ������Ϸģʽ
	void SetMyChess(const int);				// ����"��"������
	void SetLinePattern(QColor, int);		// ��������������ʽ(��ɫ+��С)
	void SetPointPattern(QColor, int);		// �����������СԲ����ʽ(��ɫ+��С)
	void SetAILevel(int);					// �����˻��Ѷ�
	void Draw();							// ��ͼ
	void Undo();							// ����
	void Restart();							// ���¿�ʼ
	void DrawOpponent(ChessNode *);			// ���з�����
	void DrawNextChess(ChessNode, int);		// ����һ������
	void LockMyChess();						// ��ס�ҷ�����
	void UnlockMyChess();					// �����ҷ�����
	int GetChessColor();					// ��ȡ��ǰ������ɫ
	int ** GetChessBoard();					// ��ȡ��ǰ����״̬
	int GetWinner();						// ��ȡʤ��
	QVector<ChessNode> GetBoardInfo();		// ��ȡ�����Ϣ
	ChessNode * GetChessInfo();				// ��ȡ��ǰ������Ϣ
/*================================================================*/

public slots:
	void AI_Step(int, int);
	void aiThread(int);						// ai�߳�
	void threadStop();
	void Gameover();

private:
/*======================private��������===========================*/
	void loadMaps();						// ������Ϸ��ͼ
	void setBoardPattern(int);				// ����������ʽ
	void drawCheckerboard(QPainter *);		// ������
	void drawChess(QPainter *);				// ������
	void analysisGame();					// �������
	void getNextColor();					// �¸�����
	QPixmap getChessPixmap(int);			// ��ȡ������ͼ
/*===============================================================*/

private:
/*========================˽�г�Ա����===========================*/
	int pattern;				// ��Ϸģʽ
	int my_chess;				// "��"������
	int flag;					// �ж��Ƿ�δ�µ�һ������
	int color;					// ��ǰ������ɫ
	int first;
	int level;
	bool isLocked;
	QColor line_color;			// ����������ɫ
	int line_size;				// ����������С
	QColor point_color;			// �������СԲ����ɫ
	int point_size;				// �������СԲ���С
	int winner;					// ʤ��
	double pos_x, pos_y;		// ��� x �� y ����
	int board_offset;			// ��������ƫ����
	int chess_offset;			// ��������ƫ����
	int ** chessboard;			// 15x15���飬����ÿ��λ�����ӵ�״̬���������ӻ������ӣ�"1"�����λ�������ӣ�"0"��ʾû��
	QPixmap pix_BlackChess;		// ������ͼ
	QPixmap pix_WhiteChess;		// ������ͼ
	QPixmap pix_Mark;			// �����ͼ
	QPixmap pix_CurrentChess;	// ��ǰ������ͼ
	ChessNode chessInfo;		// ��ǰ������Ϣ
	QVector<ChessNode> chesses;	// ����������Ϣ
	CManager * c_Manager;		// ��ֹ�����
	LevelDialog * levelDialog;
	AIThread * ai_thread;
	MessageDialog messageDialog;
/*===============================================================*/
};
#endif	// _CHESSBOARD_H_