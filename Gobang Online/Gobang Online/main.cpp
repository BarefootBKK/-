// main.cpp
#include "Gobang.h"
#include"MainFrame.h"
#include <QtWidgets/QApplication>
#include <QStyleFactory>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QPixmap pixmap(":/Gobang/Images/SplashScreen/startIcon.png");
	QSplashScreen splash(pixmap);
	splash.setDisabled(true);
	splash.show();

	MainFrame w;
	QApplication::setStyle(QStyleFactory::create("fusion"));	//设置窗口风格														//Gobang w;
	w.show();

	splash.finish(&w);

	return a.exec();
}