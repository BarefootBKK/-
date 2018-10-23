// cmanager.cpp
#include "cmanager.h"

// 构造函数
CManager::CManager()
{
	this->chess = new ChessNode();
}

// 析构函数
CManager::~CManager()
{
}

// 判断胜负
int CManager::getWinner(int ** checkerboard, int pos_x, int pos_y, int color)
{
	int count = 1;	// 计数器，记录连续的相同棋子数
	int x = pos_x;	// 当前棋子x坐标
	int y = pos_y;	// 当前棋子y坐标

/*============================横向===========================*/
	// 向左检查
	while (true)
	{
		x--;
		if (x < 0 || y < 0 || x > 14 || y > 14)
		{
			x = pos_x;
			y = pos_y;
			break;
		}
		else if (checkerboard[x][y] != color)
		{
			x = pos_x;
			y = pos_y;
			break;
		}
		count++;
	}
	// 向右检查
	while (true)
	{
		x++;
		if (x < 0 || y < 0 || x > 14 || y > 14)
		{
			x = pos_x;
			y = pos_y;
			break;
		}
		else if (checkerboard[x][y] != color)
		{
			x = pos_x;
			y = pos_y;
			break;
		}
		count++;
	}
	// 判断是否有胜者
	if (count >= 5)
		return color;
/*============================================================*/


/*============================纵向============================*/
	// 纵向
	// 向上检查
	count = 1;
	while (true)
	{
		y--;
		if (x < 0 || y < 0 || x > 14 || y > 14)
		{
			x = pos_x;
			y = pos_y;
			break;
		}
		else if (checkerboard[x][y] != color)
		{
			x = pos_x;
			y = pos_y;
			break;
		}
		count++;
	}
	// 向右检查
	while (true)
	{
		y++;
		if (x < 0 || y < 0 || x > 14 || y > 14)
		{
			x = pos_x;
			y = pos_y;
			break;
		}
		else if (checkerboard[x][y] != color)
		{
			x = pos_x;
			y = pos_y;
			break;
		}
		count++;
	}

	if (count >= 5)
		return color;
/*============================================================*/


/*==========================左上到右下========================*/
	// 向左上检查
	count = 1;
	while (true)
	{
		x--;
		y--;
		if (x < 0 || y < 0 || x > 14 || y > 14)
		{
			x = pos_x;
			y = pos_y;
			break;
		}
		else if (checkerboard[x][y] != color)
		{
			x = pos_x;
			y = pos_y;
			break;
		}
		count++;
	}
	// 向下检查
	while (true)
	{
		x++;
		y++;
		if (x < 0 || y < 0 || x > 14 || y > 14)
		{
			x = pos_x;
			y = pos_y;
			break;
		}
		else if (checkerboard[x][y] != color)
		{
			x = pos_x;
			y = pos_y;
			break;
		}
		count++;
	}
	if (count >= 5)
		return color;
/*============================================================*/


/*==========================右上到左下========================*/
// 向右上检查
	count = 1;
	while (true)
	{
		x++;
		y--;
		if (x < 0 || y < 0 || x > 14 || y > 14)
		{
			x = pos_x;
			y = pos_y;
			break;
		}
		else if (checkerboard[x][y] != color)
		{
			x = pos_x;
			y = pos_y;
			break;
		}
		count++;
	}
	// 向左下检查
	while (true)
	{
		x--;
		y++;
		if (x < 0 || y < 0 || x > 14 || y > 14)
		{
			x = pos_x;
			y = pos_y;
			break;
		}
		else if (checkerboard[x][y] != color)
		{
			x = pos_x;
			y = pos_y;
			break;
		}
		count++;
	}
	if (count >= 5)
		return color;
/*============================================================*/

	return 0;
}

// 保存棋局 
void CManager::SaveBoard(QVector<ChessNode> chesses, QString filename)
{
	QString currentPath = ":/Gobang/Images/Hint/提示.png";

	//写出数据  
	ofstream out_file(filename.toLocal8Bit(), ios::binary);

	if (!out_file)
	{
		QMessageBox message(QMessageBox::NoIcon, "我的嘛呀", "保存失败了......");
		message.setIconPixmap(QPixmap(currentPath));
		message.exec();
	}
	else
	{
		int size = chesses.size();
		out_file.write((const char *)&size, 4);
		out_file.write((const char *)&chesses[0], size * sizeof(ChessNode));

		// 提示消息框
		QMessageBox message(QMessageBox::NoIcon, "哈哈哈", "保存成功啦！");
		message.setIconPixmap(QPixmap(currentPath));
		message.exec();
	}

	out_file.close();
}

// 读取棋局
QVector<ChessNode> CManager::ReadBoard(QString fileName)
{
	QVector<ChessNode> temp_chessboard;
	ifstream in(fileName.toLocal8Bit(), ios::binary);

	if (!in) {
		qDebug() << "异常，读取失败";
	}
	else
	{
		int size;
		in.read((char*)&size, 4);
		qDebug() << size;
		temp_chessboard.resize(size);
		in.read((char*)&temp_chessboard[0], sizeof(ChessNode) * size);
	}

	in.close();

	return temp_chessboard;
}

// 加密信息
QString CManager::getEncryptInfo(ChessNode * chessInfo)
{
	QString str = QString::number(CHESSED) + "|" +
				QString::number(chessInfo->color) + "|" +
				QString::number(chessInfo->i) + "|" +
				QString::number(chessInfo->j);

	return str;
}

// 获取解析后的棋子信息
ChessNode * CManager::getParsedInfo(QString str_msg)
{
	ChessNode * chessInfo = new ChessNode();

	QStringList list = str_msg.split("|");

	chessInfo->color = list.at(1).toInt();
	chessInfo->i = list.at(2).toInt();
	chessInfo->j = list.at(3).toInt();

	return chessInfo;
}