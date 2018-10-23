// cmanager.cpp
#include "cmanager.h"

// ���캯��
CManager::CManager()
{
	this->chess = new ChessNode();
}

// ��������
CManager::~CManager()
{
}

// �ж�ʤ��
int CManager::getWinner(int ** checkerboard, int pos_x, int pos_y, int color)
{
	int count = 1;	// ����������¼��������ͬ������
	int x = pos_x;	// ��ǰ����x����
	int y = pos_y;	// ��ǰ����y����

/*============================����===========================*/
	// ������
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
	// ���Ҽ��
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
	// �ж��Ƿ���ʤ��
	if (count >= 5)
		return color;
/*============================================================*/


/*============================����============================*/
	// ����
	// ���ϼ��
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
	// ���Ҽ��
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


/*==========================���ϵ�����========================*/
	// �����ϼ��
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
	// ���¼��
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


/*==========================���ϵ�����========================*/
// �����ϼ��
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
	// �����¼��
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

// ������� 
void CManager::SaveBoard(QVector<ChessNode> chesses, QString filename)
{
	QString currentPath = ":/Gobang/Images/Hint/��ʾ.png";

	//д������  
	ofstream out_file(filename.toLocal8Bit(), ios::binary);

	if (!out_file)
	{
		QMessageBox message(QMessageBox::NoIcon, "�ҵ���ѽ", "����ʧ����......");
		message.setIconPixmap(QPixmap(currentPath));
		message.exec();
	}
	else
	{
		int size = chesses.size();
		out_file.write((const char *)&size, 4);
		out_file.write((const char *)&chesses[0], size * sizeof(ChessNode));

		// ��ʾ��Ϣ��
		QMessageBox message(QMessageBox::NoIcon, "������", "����ɹ�����");
		message.setIconPixmap(QPixmap(currentPath));
		message.exec();
	}

	out_file.close();
}

// ��ȡ���
QVector<ChessNode> CManager::ReadBoard(QString fileName)
{
	QVector<ChessNode> temp_chessboard;
	ifstream in(fileName.toLocal8Bit(), ios::binary);

	if (!in) {
		qDebug() << "�쳣����ȡʧ��";
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

// ������Ϣ
QString CManager::getEncryptInfo(ChessNode * chessInfo)
{
	QString str = QString::number(CHESSED) + "|" +
				QString::number(chessInfo->color) + "|" +
				QString::number(chessInfo->i) + "|" +
				QString::number(chessInfo->j);

	return str;
}

// ��ȡ�������������Ϣ
ChessNode * CManager::getParsedInfo(QString str_msg)
{
	ChessNode * chessInfo = new ChessNode();

	QStringList list = str_msg.split("|");

	chessInfo->color = list.at(1).toInt();
	chessInfo->i = list.at(2).toInt();
	chessInfo->j = list.at(3).toInt();

	return chessInfo;
}