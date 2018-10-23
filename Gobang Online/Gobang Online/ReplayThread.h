// ReplayThread.h
#pragma once

#ifndef _REPLAYTHREAD_H_
#define _REPLAYTHREAD_H_

#include <QThread>

class ReplayThread : public QThread
{
	Q_OBJECT

signals:
	void next_step(int, int);

public:

	ReplayThread(QObject * parent) : QThread(parent)
	{
		this->steps = 0;
		this->isStopped = false;
		this->isPaused = false;
		this->time = 1000;
	}

public slots:

	void SetSpeed(int speed)
	{
		this->time = speed;
	}

	void PauseReplay(bool play_state)
	{
		this->isPaused = play_state;
	}

	void StopReplay()
	{
		this->isStopped = true;
	}

protected:

	virtual void run()
	{
		while (true)
		{
			if (isStopped)
			{
				break;
			}

			if (!isPaused)
			{
				emit next_step(steps++, 1);
			}

			msleep(time);
		}
	}

private:
	int steps;
	int time;
	bool isStopped;
	bool isPaused;
};

#endif
