// account.cpp
#include "account.h"

Account::Account()				// 构造函数
{
}

Account::~Account()				// 析构函数
{
}

// 设置账号
void Account::SetAccount(int account)
{
	this->account = account;
}

// 设置昵称
void Account::SetNickname(QString nickname)
{
	this->nickname = nickname;
}

// 设置胜场数
void Account::SetWinningField(int winned_num)
{
	this->winned_num = winned_num;
}

// 设置负场数
void Account::SetNegativeField(int failed_num)
{
	this->failed_num = failed_num;
}

// 获取账号
int Account::GetAccount()
{
	return account;
}

// 获取昵称
QString Account::GetNickname()
{
	return nickname;
}

// 获取胜场数
int Account::GetWinningField()
{
	return winned_num;
}

// 负场数
int Account::GetNegativeFiled()
{
	return failed_num;
}

// 获取胜率
double Account::GetWinningRate()
{
	double rate = 0.00;

	rate = (double)(winned_num / (winned_num + failed_num)) * 100;

	return rate;
}

