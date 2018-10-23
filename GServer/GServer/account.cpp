// account.cpp
#include "account.h"

Account::Account()		// 构造函数
{
	this->player = new PlayerInfo();
	this->in_accounts.clear();
}

// 判断账号是否存在
bool Account::isAccExisted(QString path)
{
	QDir dir(path);

	if (dir.exists())		// 存在
		return true;
	else					// 不存在
		return false;
}
// 注册
void Account::Sign_in(PlayerInfo * in_player, Socket * in_socket)
{
	socket = in_socket;
	// 获取项目文件路径
	QString currentPath = QDir::currentPath();
	QString path = currentPath + "/Account/" + in_player->account;

	if (!isAccExisted(path))
	{
		QDir dir(path);
		dir.mkdir(path);			// 若不存在则创建
		path = path + "/" + in_player->account;
		// 保存账号信息
		saveFile(in_player, path);

		emit acc_msg(socket, QString::number(SIGN_IN_SUCC).toLocal8Bit());
	}
	else
		emit acc_msg(socket, QString::number(ACC_EXIST).toLocal8Bit());	// 发送“账号已存在”消息
}

void Account::Log_in(PlayerInfo * in_player, Socket * in_socket)
{
	socket = in_socket;
	// 获取项目文件路径
	QString currentPath = QDir::currentPath();
	QString path = currentPath + "/Account/" + in_player->account;

	// 若账号存在
	if (isAccExisted(path))
	{
		// 文件路径
		path = path + "/" + in_player->account;

		// 读取账号信息
		readFile(path);

		// 若读取失败，发送失败消息
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
				emit acc_msg(socket, QString::number(LOG_IN_FAILED_A).toLocal8Bit());		// 发送登录失败消息
		}
	}
	else
		emit acc_msg(socket, QString::number(ACC_NONE).toLocal8Bit());						// 发送账号不存在消息
}

// 返回玩家昵称
QString Account::GetNickname()
{
	return player->nickname;
}

// 保存文件
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

// 读取文件
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

// 判断该账号是否已登录
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

// 获取加密后的账号信息
QString Account::getEncryptedPlayerInfo()
{
	// 加密信息
	QString acc_info = QString::number(LOG_IN_SUCC) + "|" +
						player->account + "|" +
						player->nickname + "|" +
						player->winned_num + "|" +
						player->failed_num + "|" +
						player->scores;

	return acc_info.toLocal8Bit();
}

