/********************************************************************************
** Form generated from reading UI file 'Room_wait.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOM_WAIT_H
#define UI_ROOM_WAIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Room_wait
{
public:
    QPushButton *start_Button;
    QLabel *waitFor_label;
    QLabel *backgroun_label;
    QLabel *player1_label;
    QLabel *player2_label;
    QLabel *roomName_label;
    QLabel *roomNum_label;
    QPushButton *back_button;
    QLabel *roomType_label;
    QLabel *my_name_label;
    QLabel *op_name_label;

    void setupUi(QDialog *Room_wait)
    {
        if (Room_wait->objectName().isEmpty())
            Room_wait->setObjectName(QStringLiteral("Room_wait"));
        Room_wait->resize(370, 400);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Image/Icon/\345\233\276\346\240\207.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Room_wait->setWindowIcon(icon);
        start_Button = new QPushButton(Room_wait);
        start_Button->setObjectName(QStringLiteral("start_Button"));
        start_Button->setGeometry(QRect(107, 320, 155, 55));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(18);
        start_Button->setFont(font);
        start_Button->setCursor(QCursor(Qt::PointingHandCursor));
        start_Button->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-image: url(:/new/prefix1/Image/Button/150.50.jpg);"));
        waitFor_label = new QLabel(Room_wait);
        waitFor_label->setObjectName(QStringLiteral("waitFor_label"));
        waitFor_label->setGeometry(QRect(70, 150, 230, 45));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\347\220\245\347\217\200"));
        font1.setPointSize(16);
        waitFor_label->setFont(font1);
        waitFor_label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        waitFor_label->setAlignment(Qt::AlignCenter);
        backgroun_label = new QLabel(Room_wait);
        backgroun_label->setObjectName(QStringLiteral("backgroun_label"));
        backgroun_label->setGeometry(QRect(0, 0, 370, 400));
        backgroun_label->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/Image/Background/wait_\345\211\257\346\234\254.jpg);"));
        player1_label = new QLabel(Room_wait);
        player1_label->setObjectName(QStringLiteral("player1_label"));
        player1_label->setGeometry(QRect(155, 210, 60, 60));
        player1_label->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/Images/Hint/\346\217\220\347\244\272_\345\260\217.png);"));
        player2_label = new QLabel(Room_wait);
        player2_label->setObjectName(QStringLiteral("player2_label"));
        player2_label->setGeometry(QRect(155, 60, 60, 60));
        player2_label->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/Images/Hint/\346\217\220\347\244\272_\345\260\217.png);"));
        roomName_label = new QLabel(Room_wait);
        roomName_label->setObjectName(QStringLiteral("roomName_label"));
        roomName_label->setGeometry(QRect(100, 10, 121, 21));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        roomName_label->setFont(font2);
        roomName_label->setStyleSheet(QStringLiteral("color: rgb(0, 85, 127);"));
        roomNum_label = new QLabel(Room_wait);
        roomNum_label->setObjectName(QStringLiteral("roomNum_label"));
        roomNum_label->setGeometry(QRect(230, 10, 121, 21));
        roomNum_label->setFont(font2);
        roomNum_label->setStyleSheet(QStringLiteral("color: rgb(0, 85, 127);"));
        back_button = new QPushButton(Room_wait);
        back_button->setObjectName(QStringLiteral("back_button"));
        back_button->setGeometry(QRect(10, 10, 71, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        back_button->setFont(font3);
        back_button->setCursor(QCursor(Qt::PointingHandCursor));
        back_button->setStyleSheet(QLatin1String("color: rgb(254, 255, 175);\n"
"background-color: rgb(219, 197, 158);"));
        back_button->setFlat(false);
        roomType_label = new QLabel(Room_wait);
        roomType_label->setObjectName(QStringLiteral("roomType_label"));
        roomType_label->setGeometry(QRect(10, 50, 111, 16));
        roomType_label->setFont(font2);
        roomType_label->setStyleSheet(QStringLiteral("color: rgb(0, 85, 127);"));
        my_name_label = new QLabel(Room_wait);
        my_name_label->setObjectName(QStringLiteral("my_name_label"));
        my_name_label->setGeometry(QRect(150, 290, 70, 20));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(10);
        my_name_label->setFont(font4);
        my_name_label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        my_name_label->setAlignment(Qt::AlignCenter);
        op_name_label = new QLabel(Room_wait);
        op_name_label->setObjectName(QStringLiteral("op_name_label"));
        op_name_label->setGeometry(QRect(150, 130, 70, 20));
        op_name_label->setFont(font4);
        op_name_label->setStyleSheet(QStringLiteral("color: rgb(0, 85, 0);"));
        op_name_label->setAlignment(Qt::AlignCenter);
        backgroun_label->raise();
        start_Button->raise();
        waitFor_label->raise();
        player1_label->raise();
        player2_label->raise();
        roomName_label->raise();
        roomNum_label->raise();
        back_button->raise();
        roomType_label->raise();
        my_name_label->raise();
        op_name_label->raise();

        retranslateUi(Room_wait);

        QMetaObject::connectSlotsByName(Room_wait);
    } // setupUi

    void retranslateUi(QDialog *Room_wait)
    {
        Room_wait->setWindowTitle(QApplication::translate("Room_wait", "\347\255\211\345\276\205\344\270\255", Q_NULLPTR));
        start_Button->setText(QApplication::translate("Room_wait", "\345\274\200\345\247\213\346\270\270\346\210\217", Q_NULLPTR));
        waitFor_label->setText(QApplication::translate("Room_wait", "\347\255\211\345\276\205\345\257\271\346\226\271\345\212\240\345\205\245\346\210\277\351\227\264", Q_NULLPTR));
        backgroun_label->setText(QString());
        player1_label->setText(QString());
        player2_label->setText(QString());
        roomName_label->setText(QApplication::translate("Room_wait", "\346\210\277\351\227\264\345\220\215", Q_NULLPTR));
        roomNum_label->setText(QApplication::translate("Room_wait", "\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        back_button->setText(QApplication::translate("Room_wait", "\347\246\273\345\274\200\346\210\277\351\227\264", Q_NULLPTR));
        roomType_label->setText(QApplication::translate("Room_wait", "\346\210\277\351\227\264\347\261\273\345\236\213", Q_NULLPTR));
        my_name_label->setText(QString());
        op_name_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Room_wait: public Ui_Room_wait {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOM_WAIT_H
