// account.cpp
#include "account.h"

Account::Account()				// ���캯��
{
}

Account::~Account()				// ��������
{
}

// �����˺�
void Account::SetAccount(int account)
{
	this->account = account;
}

// �����ǳ�
void Account::SetNickname(QString nickname)
{
	this->nickname = nickname;
}

// ����ʤ����
void Account::SetWinningField(int winned_num)
{
	this->winned_num = winned_num;
}

// ���ø�����
void Account::SetNegativeField(int failed_num)
{
	this->failed_num = failed_num;
}

// ��ȡ�˺�
int Account::GetAccount()
{
	return account;
}

// ��ȡ�ǳ�
QString Account::GetNickname()
{
	return nickname;
}

// ��ȡʤ����
int Account::GetWinningField()
{
	return winned_num;
}

// ������
int Account::GetNegativeFiled()
{
	return failed_num;
}

// ��ȡʤ��
double Account::GetWinningRate()
{
	double rate = 0.00;

	rate = (double)(winned_num / (winned_num + failed_num)) * 100;

	return rate;
}

