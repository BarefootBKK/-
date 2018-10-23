// Log.cpp
#include "Room.h"

#include <QMessageBox>
#include"qdebug.h"
//#include"MainFrame.h"

 // ���캯��
Room::Room(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	this->initData();	// ��ʼ������
}

// ��ʼ������
void Room::initData()
{
	this->setRoomDialog = new SetRoomDialog();		// �����������
	this->roomWaitDialog = new RoomWait();			// ����ȴ�����

	// �̶����ڴ�С
	this->setMinimumSize(600, 600);	// ������С�ߴ�
	this->setMaximumSize(600, 600);	// �������ߴ�
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);		//��ֹ���
	this->setConnection();

	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);		//��ֹ�༭���
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);	//���ñ��Ϊѡ������
}

// �����ź���۵�����
void Room::setConnection()
{
	connect(ui.match_button, SIGNAL(clicked()), this, SLOT(matching()));
	connect(ui.create_Button, SIGNAL(clicked()), this, SLOT(create()));
	connect(ui.return_Button, SIGNAL(clicked()), this, SLOT(backTo()));
	connect(ui.tableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(joinRoom(int,int)));
	// setRoomDialog
	connect(setRoomDialog, SIGNAL(room_info_msg(QString)), this, SLOT(set(QString)));
	// roomWaitDialog
	//connect(roomWaitDialog, SIGNAL(leave()), this, SLOT(reshow()));
	connect(roomWaitDialog, SIGNAL(start_game()), this, SLOT(startGame()));
	connect(roomWaitDialog, SIGNAL(leave(QString)), this, SLOT(leaveRoom(QString)));
}

// ƥ��
void Room::matching()
{
	if (!isMatching)		// �ȴ�ƥ��ɹ�
	{
		isMatching = true;
		emit room_msg(QString::number(MATCH));
		ui.match_button->setText("ȡ��ƥ��");
		ui.create_Button->setEnabled(false);
	}
	else					// ƥ��ɹ�
	{
		emit room_msg(QString::number(MATCH_CANCEL));
		ui.match_button->setText("ƥ�����");
		ui.create_Button->setEnabled(true);
	}
}

// �������˵�
void Room::backTo()
{
	emit back();
}

// ��������
void Room::create()
{
	setRoomDialog->setModal(true);		// ����Ϊģ̬������
	setRoomDialog->show();
	setRoomDialog->setGeometry(this->pos().x() + 100, this->pos().y() + 150, 400, 300);
}

// ����
void Room::set(QString msg)
{
	qDebug() << "set........";
	roomInfo = setRoomDialog->GetRoomInfo();
	emit room_msg(msg);
}

// ��������Ϣ
void Room::processRoomInfo(QStringList list)
{
	int req = list.at(0).toInt();

	if (req == ROOM_NEW)
	{
		roomInfo.room_num = list.at(1);
		roomWaitDialog->setRoomName(roomInfo.room_name);
		roomWaitDialog->setRoomNum(roomInfo.room_num);
		roomWaitDialog->setRoomType(getRoomType(roomInfo.room_type));
		emit get_myname();

		this->setWindowOpacity(0.8);
		roomWaitDialog->setRoomOwnner(true);
		roomWaitDialog->show();
		roomWaitDialog->setGeometry(this->pos().x() + 115, this->pos().y() + 100, 370, 400);
	}
	else if (req == ROOM_INFO_LIST)
	{
		updateRoomList(list);
	}

}

// ���·����б�
void Room::updateRoomList(QStringList list)//�����б�����ı�
{
		// ��������
		ui.tableWidget->setRowCount(list.length() - 1);

		for (int i = 1; i < list.length(); i++)
		{
			QStringList item_list = list.at(i).split("#");
				
			ui.tableWidget->setItem(i - 1, 0, new QTableWidgetItem(item_list.at(0)));
			ui.tableWidget->setItem(i - 1, 1, new QTableWidgetItem(item_list.at(1)));
			ui.tableWidget->setItem(i - 1, 2, new QTableWidgetItem(getRoomType(item_list.at(2).toInt())));
			ui.tableWidget->setItem(i - 1, 3, new QTableWidgetItem(QString(item_list.at(3)) + "/2"));

			for (int j = 0; j < 4; j++)
				ui.tableWidget->item(i - 1, j)->setTextAlignment(Qt::AlignCenter);
		}
}

// ���뷿��
void Room::joinRoom(int row, int column)
{
	int player_num = ui.tableWidget->item(row, 3)->text().toStdString()[0] - '0';

	// ֻ�з�����������2ʱ�����������
	if (player_num < 2)
	{
		QString room_num = ui.tableWidget->item(row, 1)->text();
		QString room_type = ui.tableWidget->item(row, 2)->text();
		QString room_key;

		// ���÷���Ϊ���ܷ���
		if (room_type == "����")
		{
			bool ok;
			QInputDialog dialog;
			dialog.setWindowModality(Qt::WindowModal);
			QString temp_key = dialog.getText(this, tr("��������"), tr("�뷿�����룺"),
				QLineEdit::Normal, NULL, &ok);

			if (ok && !temp_key.isEmpty())
				room_key = temp_key;
		}
		else
			room_key = QString::number(-1001);

		QString roomMsg = QString::number(ROOM_ADD) + "|" +
							room_num + "|" + room_key;

		roomWaitDialog->setRoomName(ui.tableWidget->item(row, 0)->text());
		roomWaitDialog->setRoomNum(room_num);
		roomWaitDialog->setRoomType(room_type);

		emit room_msg(roomMsg);			// ������Ϣ��������
	}
	else
	{
		QString currentPath = QDir::currentPath() + "/Images/Hint/��ʾ.png";
		QMessageBox message(QMessageBox::NoIcon, "��ʾ��Ϣ", "�÷�������������");
		message.setIconPixmap(QPixmap(currentPath));
		message.exec();
	}
}

// ����������ʾ
void Room::reshow()
{
	this->setWindowOpacity(1);
	roomWaitDialog->hide();
}

// ��ʼ��Ϸ
void Room::startGame()
{
	reshow();
	emit room_msg(QString::number(ROOM_START_GAME));
	emit start();
}

// �뿪����
void Room::leaveRoom(QString msg)
{
	reshow();
	emit room_msg(msg);
}

// ��ȡ��������
QString Room::getRoomType(int room_int_type)
{
	if (room_int_type == ROOM_PU)
		return "����";
	else
		return "����";
}

// ��ʾ�ҵ��ǳ�
void Room::setMyName(QString name)
{
	roomWaitDialog->setMyName(name);
}

// ��ʾ�����ǳ�
void Room::setOpName(QString name)
{
	roomWaitDialog->setOpName(name);

	if (!roomWaitDialog->isRoomOwnner())
	{
		emit get_myname();
		this->setWindowOpacity(0.8);
		roomWaitDialog->setRoomOwnner(false);
		roomWaitDialog->show();
		roomWaitDialog->setGeometry(this->pos().x() + 115, this->pos().y() + 100, 370, 400);
	}
}
