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

//λ�ýṹ�壬����x������y
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

//������ֵĹ�ϣ����Ŀ
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

	//�ڿ�ʼ֮ǰ��һЩ��ʼ������
	void beforeStart();

	//�ж��Ƿ���ĳһ��Ӯ��
	int isSomeOneWin();

	//����
	string takeBack();

	//���֮ǰ�ļ�¼�����¿���
	string reset(int role);

	//�������ò���
	void setLevel(int level);

	//ȡ�øղŵ����µ���һ�����ӵ�λ��
	Position getLastPosition();

	//�������壬�������̣���������
	string nextStep(int x, int y);

	//��ȡ����
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
	int winner;     //ʤ����
	int DEPTH = 7;
	stack<Position> moves;
	int scores[2][72];  //������ַ�����2����ɫ72�У���������Ʋ�ࣩ
	int allScore[2];    //���������֣�2����ɫ��
	//�洢�������������һ�����ӵ�λ��
	Position searchResult;
	ACSearcher acs;
};
#endif // _AI_H_
