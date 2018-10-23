// Log.cpp
#include "Room.h"

#include <QMessageBox>
#include"qdebug.h"
//#include"MainFrame.h"

 // 构造函数
Room::Room(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	this->initData();	// 初始化数据
}

// 初始化数据
void Room::initData()
{
	this->setRoomDialog = new SetRoomDialog();		// 建立房间界面
	this->roomWaitDialog = new RoomWait();			// 房间等待界面

	// 固定窗口大小
	this->setMinimumSize(600, 600);	// 窗口最小尺寸
	this->setMaximumSize(600, 600);	// 窗口最大尺寸
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);		//禁止最大化
	this->setConnection();

	ui.tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);		//禁止编辑表格
	ui.tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);	//设置表格为选择整行
}

// 建立信号与槽的连接
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

// 匹配
void Room::matching()
{
	if (!isMatching)		// 等待匹配成功
	{
		isMatching = true;
		emit room_msg(QString::number(MATCH));
		ui.match_button->setText("取消匹配");
		ui.create_Button->setEnabled(false);
	}
	else					// 匹配成功
	{
		emit room_msg(QString::number(MATCH_CANCEL));
		ui.match_button->setText("匹配对手");
		ui.create_Button->setEnabled(true);
	}
}

// 返回主菜单
void Room::backTo()
{
	emit back();
}

// 创建房间
void Room::create()
{
	setRoomDialog->setModal(true);		// 设置为模态化窗口
	setRoomDialog->show();
	setRoomDialog->setGeometry(this->pos().x() + 100, this->pos().y() + 150, 400, 300);
}

// 设置
void Room::set(QString msg)
{
	qDebug() << "set........";
	roomInfo = setRoomDialog->GetRoomInfo();
	emit room_msg(msg);
}

// 处理房间信息
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

// 更新房间列表
void Room::updateRoomList(QStringList list)//设置列表项的文本
{
		// 更新行数
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

// 加入房间
void Room::joinRoom(int row, int column)
{
	int player_num = ui.tableWidget->item(row, 3)->text().toStdString()[0] - '0';

	// 只有房间人数少于2时才能申请加入
	if (player_num < 2)
	{
		QString room_num = ui.tableWidget->item(row, 1)->text();
		QString room_type = ui.tableWidget->item(row, 2)->text();
		QString room_key;

		// 若该房间为加密房间
		if (room_type == "加密")
		{
			bool ok;
			QInputDialog dialog;
			dialog.setWindowModality(Qt::WindowModal);
			QString temp_key = dialog.getText(this, tr("房间密码"), tr("请房间密码："),
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

		emit room_msg(roomMsg);			// 发送消息给服务器
	}
	else
	{
		QString currentPath = QDir::currentPath() + "/Images/Hint/提示.png";
		QMessageBox message(QMessageBox::NoIcon, "提示信息", "该房间人数已满！");
		message.setIconPixmap(QPixmap(currentPath));
		message.exec();
	}
}

// 界面重新显示
void Room::reshow()
{
	this->setWindowOpacity(1);
	roomWaitDialog->hide();
}

// 开始游戏
void Room::startGame()
{
	reshow();
	emit room_msg(QString::number(ROOM_START_GAME));
	emit start();
}

// 离开房间
void Room::leaveRoom(QString msg)
{
	reshow();
	emit room_msg(msg);
}

// 获取房间类型
QString Room::getRoomType(int room_int_type)
{
	if (room_int_type == ROOM_PU)
		return "公开";
	else
		return "加密";
}

// 显示我的昵称
void Room::setMyName(QString name)
{
	roomWaitDialog->setMyName(name);
}

// 显示对手昵称
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
