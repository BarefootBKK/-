// Onlinepvp.cpp
#include "Onlinepvp.h"

#include"chessboard.h"

// ���캯��
Onlinepvp::Onlinepvp(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->initData();	// ��ʼ������
}

// ��ʼ������
void Onlinepvp::initData()
{
	// �̶����ڴ�С
	this->setMinimumSize(1250, 900);	// ������С�ߴ�
	this->setMaximumSize(1250, 900);	// �������ߴ�
	this->setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);	//��ֹ���
	this->setConnection();
	this->isMyTurn = false;
	this->time_count = 25;
	ui.time_lcdNumber->display("00:25");

	manager = new CManager();
}

// �����ź���۵�����
void Onlinepvp::setConnection()
{
	connect(ui.checkerboard_label, SIGNAL(clicked()), this, SLOT(drawChess()));
	connect(ui.checkerboard_label, SIGNAL(chessed()), this, SLOT(sendChessInfo()));
	connect(ui.undo_Button, SIGNAL(clicked()), this, SLOT(undo()));
	connect(ui.defeat_Button, SIGNAL(clicked()), this, SLOT(defeat()));
	connect(ui.save_Button, SIGNAL(clicked()), this, SLOT(save()));
}

// ��ʼ��ʱ�߳�
void Onlinepvp::startTimeThread()
{
	countTimeThread();
}

// ��ʱ���߳�
void Onlinepvp::countTimeThread()
{
	time_thread = new QThread();
	timer = new QTimer();
	timer->moveToThread(time_thread);
	timer->setInterval(1000);
	connect(time_thread, SIGNAL(started()), timer, SLOT(start()));
	connect(timer, SIGNAL(timeout()), this, SLOT(setTime()));

	time_thread->start();
}

// ��ʼ������
void Onlinepvp::initBoard(int pattern, int first)
{
	this->first = first;
	
	if (first == PLAYER_1)
		isMyTurn = true;

	getHint();

	ui.checkerboard_label->InitChessBoard(pattern, first);
}

// ����ʱ��
void Onlinepvp::setTime()
{
	time_count--;

	if (time_count < 0) {
		time_count = 25;
	}

	QString str_time;

	if (time_count >= 10) {
		str_time = TIME_FORMAT_1 + QString::number(time_count);
	}
	else {
		str_time = TIME_FORMAT_2 + QString::number(time_count);
	}

	ui.time_lcdNumber->display(str_time);
}

void Onlinepvp::getHint()
{
	if (isMyTurn)
		ui.whosturn_label->setText("��Ļغ�");
	else 
		ui.whosturn_label->setText("���ֻغ�");
}

// ������
void Onlinepvp::drawChess()
{
	ui.checkerboard_label->Draw();
}

// ����
void Onlinepvp::undo()
{
	ui.checkerboard_label->Undo();
	ui.checkerboard_label->Undo();
}

// ����
void Onlinepvp::defeat() 
{
	messageDialog.SetMsgText("ȷ��Ҫ������?");

	if (messageDialog.IsOKPushed())
		emit back();
}

// ����������Ϣ
void Onlinepvp::sendChessInfo()
{
	time_count = 25;
	emit boardMsg(manager->getEncryptInfo(ui.checkerboard_label->GetChessInfo()));
}

// ��ȡ������Ϣ
void Onlinepvp::readChessInfo(QString chess)
{
	ui.checkerboard_label->DrawOpponent(manager->getParsedInfo(chess));
}

// �������
void Onlinepvp::save()
{
	QString filename = QFileDialog::getSaveFileName(this,
		tr("�������"), "", tr("*.binfo")); //
	QFileInfo fileInfo(filename);

	if (!filename.isNull())
	{
		if (!fileInfo.exists())
		{
			manager->SaveBoard(ui.checkerboard_label->GetBoardInfo(), filename);
		}
		else
		{
			QString currentPath = ":/Gobang/Images/Hint/��ʾ.png";
			QMessageBox message(QMessageBox::NoIcon, "��ʾ��Ϣ", "�ļ��Ѵ���");
			message.setIconPixmap(QPixmap(currentPath));
			message.exec();
		}
	}
}