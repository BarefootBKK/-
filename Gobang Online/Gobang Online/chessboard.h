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
	explicit ChessBoard(QWidget *parent = 0);	// 构造函数
	~ChessBoard();								// 析构函数

/*===========================信号函数=============================*/
signals:
	void clicked();		// 鼠标点击信号
signals:
	void chessed();		// 下棋信号
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
/*=======================重载函数=================================*/
	virtual void paintEvent(QPaintEvent* event);
	virtual void mousePressEvent(QMouseEvent* event);
/*================================================================*/

public:
/*======================public基本函数============================*/
	void InitChessBoard(int, int);			// 初始化棋盘
	void SetPattern(const int);				// 设置游戏模式
	void SetMyChess(const int);				// 设置"我"的棋子
	void SetLinePattern(QColor, int);		// 设置棋盘线条样式(颜色+大小)
	void SetPointPattern(QColor, int);		// 设置棋盘五个小圆点样式(颜色+大小)
	void SetAILevel(int);					// 设置人机难度
	void Draw();							// 绘图
	void Undo();							// 悔棋
	void Restart();							// 重新开始
	void DrawOpponent(ChessNode *);			// 画敌方棋子
	void DrawNextChess(ChessNode, int);		// 画下一颗棋子
	void LockMyChess();						// 锁住我方棋子
	void UnlockMyChess();					// 解锁我方棋子
	int GetChessColor();					// 获取当前棋子颜色
	int ** GetChessBoard();					// 获取当前棋盘状态
	int GetWinner();						// 获取胜者
	QVector<ChessNode> GetBoardInfo();		// 获取棋局信息
	ChessNode * GetChessInfo();				// 获取当前棋子信息
/*================================================================*/

public slots:
	void AI_Step(int, int);
	void aiThread(int);						// ai线程
	void threadStop();
	void Gameover();

private:
/*======================private基本函数===========================*/
	void loadMaps();						// 加载游戏贴图
	void setBoardPattern(int);				// 设置棋盘样式
	void drawCheckerboard(QPainter *);		// 画棋盘
	void drawChess(QPainter *);				// 画棋子
	void analysisGame();					// 分析棋局
	void getNextColor();					// 下个棋子
	QPixmap getChessPixmap(int);			// 获取棋子贴图
/*===============================================================*/

private:
/*========================私有成员变量===========================*/
	int pattern;				// 游戏模式
	int my_chess;				// "我"的棋子
	int flag;					// 判断是否还未下第一颗棋子
	int color;					// 当前棋子颜色
	int first;
	int level;
	bool isLocked;
	QColor line_color;			// 棋盘线条颜色
	int line_size;				// 棋盘线条大小
	QColor point_color;			// 棋盘五个小圆点颜色
	int point_size;				// 棋盘五个小圆点大小
	int winner;					// 胜者
	double pos_x, pos_y;		// 鼠标 x 和 y 坐标
	int board_offset;			// 棋盘坐标偏移量
	int chess_offset;			// 棋子坐标偏移量
	int ** chessboard;			// 15x15数组，保存每个位置棋子的状态，即有棋子或无棋子，"1"代表该位置有棋子，"0"表示没有
	QPixmap pix_BlackChess;		// 黑棋贴图
	QPixmap pix_WhiteChess;		// 白棋贴图
	QPixmap pix_Mark;			// 标记贴图
	QPixmap pix_CurrentChess;	// 当前棋子贴图
	ChessNode chessInfo;		// 当前棋子信息
	QVector<ChessNode> chesses;	// 保存棋子信息
	CManager * c_Manager;		// 棋局管理器
	LevelDialog * levelDialog;
	AIThread * ai_thread;
	MessageDialog messageDialog;
/*===============================================================*/
};
#endif	// _CHESSBOARD_H_