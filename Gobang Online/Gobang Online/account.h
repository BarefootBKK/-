// account.h
#pragma once

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <QtWidgets/QApplication>

class Account : public QObject
{
	Q_OBJECT

public:

	Account();						// 构造函数
	~Account();						// 析构函数

public:

	void SetAccount(int);			// 设置帐号
	void SetNickname(QString);		// 设置昵称
	void SetWinningField(int);		// 设置胜场数
	void SetNegativeField(int);		// 设置负场数
	int GetAccount();				// 获取账号
	int GetWinningField();			// 获取胜场数
	int GetNegativeFiled();			// 获取负场数
	double GetWinningRate();		// 获取胜率
	QString GetNickname();			// 获取昵称

private:

	int account;					// 账号
	int winned_num;					// 胜场数
	int failed_num;					// 负场数
	double win_rate;				// 胜率
	QString nickname;				// 昵称
};

#endif	//_ACCOUNT_H_
