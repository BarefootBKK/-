// account.h
#pragma once

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include <QtWidgets/QApplication>

class Account : public QObject
{
	Q_OBJECT

public:

	Account();						// ���캯��
	~Account();						// ��������

public:

	void SetAccount(int);			// �����ʺ�
	void SetNickname(QString);		// �����ǳ�
	void SetWinningField(int);		// ����ʤ����
	void SetNegativeField(int);		// ���ø�����
	int GetAccount();				// ��ȡ�˺�
	int GetWinningField();			// ��ȡʤ����
	int GetNegativeFiled();			// ��ȡ������
	double GetWinningRate();		// ��ȡʤ��
	QString GetNickname();			// ��ȡ�ǳ�

private:

	int account;					// �˺�
	int winned_num;					// ʤ����
	int failed_num;					// ������
	double win_rate;				// ʤ��
	QString nickname;				// �ǳ�
};

#endif	//_ACCOUNT_H_
