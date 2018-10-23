// account.cpp
#include "account.h"

Account::Account()		// ���캯��
{
	this->player = new PlayerInfo();
	this->in_accounts.clear();
}

// �ж��˺��Ƿ����
bool Account::isAccExisted(QString path)
{
	QDir dir(path);

	if (dir.exists())		// ����
		return true;
	else					// ������
		return false;
}
// ע��
void Account::Sign_in(PlayerInfo * in_player, Socket * in_socket)
{
	socket = in_socket;
	// ��ȡ��Ŀ�ļ�·��
	QString currentPath = QDir::currentPath();
	QString path = currentPath + "/Account/" + in_player->account;

	if (!isAccExisted(path))
	{
		QDir dir(path);
		dir.mkdir(path);			// ���������򴴽�
		path = path + "/" + in_player->account;
		// �����˺���Ϣ
		saveFile(in_player, path);

		emit acc_msg(socket, QString::number(SIGN_IN_SUCC).toLocal8Bit());
	}
	else
		emit acc_msg(socket, QString::number(ACC_EXIST).toLocal8Bit());	// ���͡��˺��Ѵ��ڡ���Ϣ
}

void Account::Log_in(PlayerInfo * in_player, Socket * in_socket)
{
	socket = in_socket;
	// ��ȡ��Ŀ�ļ�·��
	QString currentPath = QDir::currentPath();
	QString path = currentPath + "/Account/" + in_player->account;

	// ���˺Ŵ���
	if (isAccExisted(path))
	{
		// �ļ�·��
		path = path + "/" + in_player->account;

		// ��ȡ�˺���Ϣ
		readFile(path);

		// ����ȡʧ�ܣ�����ʧ����Ϣ
		if (!player)
			emit acc_msg(socket, QString::number(LOG_IN_FAILED_S).toLocal8Bit());
		else
		{
			if (in_player->account == player->account &&
				in_player->password == player->password)
			{
				if (checkIsLogined(in_player->account))
				{
					emit acc_msg(socket, getEncryptedPlayerInfo());
				}
				else
					emit acc_msg(socket, QString::number(ACC_LOGINED).toLocal8Bit());
			}
			else
				emit acc_msg(socket, QString::number(LOG_IN_FAILED_A).toLocal8Bit());		// ���͵�¼ʧ����Ϣ
		}
	}
	else
		emit acc_msg(socket, QString::number(ACC_NONE).toLocal8Bit());						// �����˺Ų�������Ϣ
}

// ��������ǳ�
QString Account::GetNickname()
{
	return player->nickname;
}

// �����ļ�
void Account::saveFile(PlayerInfo * in_player, QString path)
{
	std::ofstream out_acc(path.toStdString() + ".player");
	std::ofstream out_rank(path.toStdString() + ".rank");

	if (!out_acc || !out_rank)
		emit acc_msg(socket, QString::number(LOG_IN_FAILED_S).toLocal8Bit());
	else
	{
		out_acc << in_player->account.toStdString() << "|"
				<< in_player->nickname.toStdString() << "|"
				<< in_player->password.toStdString();

		out_rank << "0|" << "0|" << "0";
	}
		
	out_acc.close();
	out_rank.close();
}

// ��ȡ�ļ�
void Account::readFile(QString path)
{
	std::ifstream in_acc(path.toStdString() + ".player");
	std::ifstream in_rank(path.toStdString() + ".rank");
	
	if (!in_acc || !in_rank)
		emit acc_msg(socket, QString::number(LOG_IN_FAILED_S).toLocal8Bit());
	else
	{
		std::string accInfo;
		std::string rankInfo;

		in_acc >> accInfo;
		in_rank >> rankInfo;

		QStringList accInfoList = QString::fromStdString(accInfo).split("|");
		QStringList rankInfoList = QString::fromStdString(rankInfo).split("|");

		player->account = accInfoList.at(0);
		player->nickname = accInfoList.at(1);
		player->password = accInfoList.at(2);

		player->winned_num = rankInfoList.at(0);
		player->failed_num = rankInfoList.at(1);
		player->scores = rankInfoList.at(2);
	}
	
	in_acc.close();
	in_rank.close();
}

// �жϸ��˺��Ƿ��ѵ�¼
bool Account::checkIsLogined(QString acc)
{
	for (int i = 0; i < in_accounts.size(); i++)
	{
		if (acc == in_accounts[i])	
			return false;
	}
	in_accounts.push_back(acc);

	return true;
}

// ��ȡ���ܺ���˺���Ϣ
QString Account::getEncryptedPlayerInfo()
{
	// ������Ϣ
	QString acc_info = QString::number(LOG_IN_SUCC) + "|" +
						player->account + "|" +
						player->nickname + "|" +
						player->winned_num + "|" +
						player->failed_num + "|" +
						player->scores;

	return acc_info.toLocal8Bit();
}

