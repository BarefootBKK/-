// aithread.h
#pragma once

#ifndef _AITHREAD_H_
#define _AITHREAD_H_

#include <QThread>
#include "ai.h"

class AIThread : public QThread
{
	Q_OBJECT

signals:
	void result(int, int);
signals:
	void thread_stop();

public:
	AIThread(QObject * parent, int, int);

public slots:
	void AIUndo();
	void AIRestart(int);
	void GameOver();
	void setLevel(int);
	void StartThinking(int, int);

protected:
	virtual void run();

private:
	bool isMyTurn;
	bool isUndo;
	bool isRestart;
	bool isGameOver;
	int level;
	int x, y;
	int first;
	AI * ai;
	Position lastMove;
};
#endif // _AITHREAD_H_
