#include "mainwindow.h"

Mainwindow::Mainwindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setMinimumSize(520, 630);
	this->setMaximumSize(520, 630);

	this->initData();
}

Mainwindow::~Mainwindow()
{
	if (serverState == 1)
		server->~Server();
}

void Mainwindow::initData()
{
	this->serverState = 0;
	ui.port_edit->setText("8080");
	connect(ui.openServer_button, SIGNAL(clicked()), this, SLOT(openServer()));
}

void Mainwindow::openServer()
{
	if (serverState == 0)
	{
		serverState = 1;
		this->server = new Server(this);
		this->server->listen(QHostAddress::Any, ui.port_edit->text().toInt());
		connect(server, SIGNAL(conn_new()), this, SLOT(newConn()));
		ui.openServer_button->setText("关闭服务器");
	}
	else
	{
		serverState = 0;
		server->closeServer();
		server->~Server();
		ui.info_edit->setText("");
		ui.openServer_button->setText("开启服务器");
	}
}

void Mainwindow::newConn()
{
	ui.info_edit->setText(ui.info_edit->toPlainText() + "新连接\n");
}