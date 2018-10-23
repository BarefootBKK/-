// ai.h
#pragma once

#ifndef _AI_H_
#define _AI_H_

#include <string>
#include <iostream>
#include <cstdlib>
#include <set>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include <cassert>
#include <QtWidgets/QApplication>
#include <qDebug>
#include "acsearcher.h"

#define BOARD_WIDTH 15
#define UNKNOWN_SCORE (10000001)
#define HASH_ITEM_INDEX_MASK (0xffff)
#define MAX_SCORE (10000000)
#define MIN_SCORE (-10000000)

using namespace std;

//位置结构体，行是x，列是y
struct Position {
	int x;
	int y;
	int score;
	Position() {}
	Position(int x, int y) {
		this->x = x;
		this->y = y;
		score = 0;
	}
	Position(int x, int y, int score) {
		this->x = x;
		this->y = y;
		this->score = score;
	}
	bool operator <(const Position &pos) const {
		if (score != pos.score) {
			return score > pos.score;
		}
		if (x != pos.x) {
			return x < pos.x;
		}
		else {
			return y < pos.y;
		}
	}
};

//保存棋局的哈希表条目
struct HashItem {
	long long checksum;
	int depth;
	int score;
	enum Flag { ALPHA = 0, BETA = 1, EXACT = 2, EMPTY = 3 } flag;
};

enum Role { HUMAN = 1, COMPUTOR = 2, EMPTY = 0 };

class AI : public QObject
{
	Q_OBJECT

public:
	AI();

	//在开始之前，一些初始化工作
	void beforeStart();

	//判断是否是某一方赢了
	int isSomeOneWin();

	//悔棋
	string takeBack();

	//清除之前的记录，重新开局
	string reset(int role);

	//重新设置层数
	void setLevel(int level);

	//取得刚才电脑下得那一步棋子的位置
	Position getLastPosition();

	//人类下棋，返回棋盘，传给界面
	string nextStep(int x, int y);

	//获取棋谱
	vector<Position> getChessManual();

private:
	void init();
	Position getAGoodMove(char board[BOARD_WIDTH][BOARD_WIDTH]);
	void recordHashItem(int, int, HashItem::Flag flag);
	int getHashItemScore(int, int, int);
	void randomBoardZobristValue();
	void initCurrentZobristValue();
	int evaluatePoint(char board[BOARD_WIDTH][BOARD_WIDTH], Position);
	int evaluate(char board[BOARD_WIDTH][BOARD_WIDTH], Role);
	void updateScore(char board[BOARD_WIDTH][BOARD_WIDTH], Position);
	set<Position> createPossiblePosition(char board[BOARD_WIDTH][BOARD_WIDTH]);
	int abSearch(char board[BOARD_WIDTH][BOARD_WIDTH], int, int, int, Role);

private:
	long long boardZobristValue[2][BOARD_WIDTH][BOARD_WIDTH];
	long long currentZobristValue;
	HashItem hashItems[HASH_ITEM_INDEX_MASK + 1];
	char board[BOARD_WIDTH][BOARD_WIDTH];
	int winner;     //胜出者
	int DEPTH = 7;
	stack<Position> moves;
	int scores[2][72];  //保存棋局分数（2个角色72行，包括横竖撇捺）
	int allScore[2];    //局面总评分（2个角色）
	//存储搜索结果，即下一步棋子的位置
	Position searchResult;
	ACSearcher acs;
};
#endif // _AI_H_
