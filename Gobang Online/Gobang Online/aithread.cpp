// aithread.cpp
#include "aithread.h"

AIThread::AIThread(QObject * parent, int first, int level)
	: QThread(parent)
{
	this->first = first;
	this->level = level;
	this->isMyTurn = false;
	this->isUndo = false;
	this->isRestart = false;
	this->isGameOver = false;
}

void AIThread::run()
{
	lastMove = Position(-1, -1);
	ai = new AI();
	ai->beforeStart();
	ai->setLevel(level);

	while (true)
	{
		if (isMyTurn)
		{
			isMyTurn = false;
			ai->nextStep(x, y);
			lastMove = ai->getLastPosition();

			emit result(lastMove.x, lastMove.y);
		}
		else if (isUndo)
		{
			isUndo = false;
			ai->takeBack();
		}
		else if (isRestart)
		{
			isRestart = false;
			lastMove = Position(-1, -1);
			ai->reset(first);
		}

		if (isGameOver)
		{
			break;
		}

		msleep(10);
	}

	emit thread_stop();
}

void AIThread::StartThinking(int x, int y)
{
	this->x = x;
	this->y = y;
	this->isMyTurn = true;
}

void AIThread::AIUndo()
{
	this->isUndo = true;
}

void AIThread::AIRestart(int first)
{
	this->isRestart = true;
	this->first = first;
}

void AIThread::GameOver()
{
	this->isGameOver = true;
}

void AIThread::setLevel(int level)
{
	this->level = level;
}

