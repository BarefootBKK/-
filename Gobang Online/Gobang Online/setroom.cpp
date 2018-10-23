// setroom.cpp
#include "setroom.h"

SetRoomDialog::SetRoomDialog(QWidget * parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	InitData();
}

void SetRoomDialog::InitData()
{
	roomInfo.room_type = ROOM_PU;
	ui.setKey_label->hide();
	ui.key_edit->hide();
	this->setWindowFlags(windowFlags() | Qt::FramelessWindowHint);

	connect(ui.okButton, SIGNAL(clicked()), this, SLOT(finishSet()));
	connect(ui.type_checkBox, SIGNAL(stateChanged(int)), this, SLOT(setKey(int)));
}

RoomInfo SetRoomDialog::GetRoomInfo()
{
	return roomInfo;
}

void SetRoomDialog::setKey(int state)
{
	if (state == Qt::Checked)
	{
		roomInfo.room_type = ROOM_PR;
		ui.setKey_label->show();
		ui.key_edit->show();
	}
	else if (state == Qt::Unchecked)
	{
		roomInfo.room_type = ROOM_PU;
		ui.setKey_label->hide();
		ui.key_edit->hide();
	}
}

void SetRoomDialog::finishSet()
{
	if (ui.roomname_edit->text().length() < 1)
	{
		this->show();
		QMessageBox::information(NULL, "Hint", "请输入房间名！");
	}
	else
	{
		QString str_msg = QString::number(roomInfo.room_type) + "|" +
							ui.roomname_edit->text();
		roomInfo.room_name = ui.roomname_edit->text();

		if (roomInfo.room_type == ROOM_PR)
			str_msg = str_msg + "|" + ui.key_edit->text();
		else
			str_msg = str_msg + "|" + "-1001";

		emit room_info_msg(str_msg);

		ui.roomname_edit->setText("");
		ui.key_edit->setText("");
		ui.type_checkBox->setCheckState(Qt::Unchecked);

	}
}
