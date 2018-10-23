/********************************************************************************
** Form generated from reading UI file 'Onlinepvp.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ONLINEPVP_H
#define UI_ONLINEPVP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <chessboard.h>

QT_BEGIN_NAMESPACE

class Ui_FormOnlinepvp
{
public:
    QLabel *background_label;
    ChessBoard *checkerboard_label;
    QLabel *player2;
    QLabel *player1;
    QPushButton *undo_Button;
    QPushButton *save_Button;
    QPushButton *defeat_Button;
    QLCDNumber *time_lcdNumber;
    QLabel *player_1_label;
    QLabel *player_2_label;
    QLabel *whosturn_label;
    QLabel *player2_name_label;
    QLabel *player1_name_label;

    void setupUi(QWidget *FormOnlinepvp)
    {
        if (FormOnlinepvp->objectName().isEmpty())
            FormOnlinepvp->setObjectName(QStringLiteral("FormOnlinepvp"));
        FormOnlinepvp->resize(1250, 900);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Image/Icon/\345\233\276\346\240\207.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        FormOnlinepvp->setWindowIcon(icon);
        background_label = new QLabel(FormOnlinepvp);
        background_label->setObjectName(QStringLiteral("background_label"));
        background_label->setGeometry(QRect(0, 0, 1400, 900));
        background_label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Background/Gme1.jpg);"));
        checkerboard_label = new ChessBoard(FormOnlinepvp);
        checkerboard_label->setObjectName(QStringLiteral("checkerboard_label"));
        checkerboard_label->setGeometry(QRect(70, 30, 840, 840));
        checkerboard_label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Background/check.jpg);"));
        player2 = new QLabel(FormOnlinepvp);
        player2->setObjectName(QStringLiteral("player2"));
        player2->setGeometry(QRect(1000, 170, 70, 70));
        player2->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Chess/play2.jpg);"));
        player1 = new QLabel(FormOnlinepvp);
        player1->setObjectName(QStringLiteral("player1"));
        player1->setGeometry(QRect(1000, 370, 70, 70));
        player1->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Chess/play1.jpg);"));
        undo_Button = new QPushButton(FormOnlinepvp);
        undo_Button->setObjectName(QStringLiteral("undo_Button"));
        undo_Button->setGeometry(QRect(1000, 710, 155, 55));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(18);
        undo_Button->setFont(font);
        undo_Button->setCursor(QCursor(Qt::PointingHandCursor));
        undo_Button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/150.50.jpg);\n"
"color: rgb(255, 255, 255);"));
        save_Button = new QPushButton(FormOnlinepvp);
        save_Button->setObjectName(QStringLiteral("save_Button"));
        save_Button->setGeometry(QRect(1000, 800, 155, 55));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(18);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        save_Button->setFont(font1);
        save_Button->setCursor(QCursor(Qt::PointingHandCursor));
        save_Button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/150.50.jpg);\n"
"color: rgb(255, 255, 255);"));
        defeat_Button = new QPushButton(FormOnlinepvp);
        defeat_Button->setObjectName(QStringLiteral("defeat_Button"));
        defeat_Button->setGeometry(QRect(1000, 610, 155, 55));
        defeat_Button->setFont(font1);
        defeat_Button->setCursor(QCursor(Qt::PointingHandCursor));
        defeat_Button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/150.50.jpg);\n"
"color: rgb(255, 255, 255);"));
        time_lcdNumber = new QLCDNumber(FormOnlinepvp);
        time_lcdNumber->setObjectName(QStringLiteral("time_lcdNumber"));
        time_lcdNumber->setGeometry(QRect(980, 220, 221, 171));
        time_lcdNumber->setFrameShape(QFrame::NoFrame);
        time_lcdNumber->setFrameShadow(QFrame::Raised);
        time_lcdNumber->setLineWidth(0);
        time_lcdNumber->setSmallDecimalPoint(false);
        time_lcdNumber->setDigitCount(5);
        time_lcdNumber->setMode(QLCDNumber::Dec);
        time_lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        time_lcdNumber->setProperty("value", QVariant(0));
        time_lcdNumber->setProperty("intValue", QVariant(0));
        player_1_label = new QLabel(FormOnlinepvp);
        player_1_label->setObjectName(QStringLiteral("player_1_label"));
        player_1_label->setGeometry(QRect(1030, 80, 100, 100));
        player_1_label->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/Images/Hint/\346\217\220\347\244\272.png);"));
        player_2_label = new QLabel(FormOnlinepvp);
        player_2_label->setObjectName(QStringLiteral("player_2_label"));
        player_2_label->setGeometry(QRect(1030, 400, 100, 100));
        player_2_label->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/Images/Hint/\346\217\220\347\244\272.png);"));
        whosturn_label = new QLabel(FormOnlinepvp);
        whosturn_label->setObjectName(QStringLiteral("whosturn_label"));
        whosturn_label->setGeometry(QRect(980, 20, 211, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font2.setPointSize(16);
        whosturn_label->setFont(font2);
        whosturn_label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        whosturn_label->setAlignment(Qt::AlignCenter);
        player2_name_label = new QLabel(FormOnlinepvp);
        player2_name_label->setObjectName(QStringLiteral("player2_name_label"));
        player2_name_label->setGeometry(QRect(1030, 190, 100, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(14);
        player2_name_label->setFont(font3);
        player2_name_label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        player2_name_label->setAlignment(Qt::AlignCenter);
        player1_name_label = new QLabel(FormOnlinepvp);
        player1_name_label->setObjectName(QStringLiteral("player1_name_label"));
        player1_name_label->setGeometry(QRect(1030, 510, 100, 30));
        player1_name_label->setFont(font3);
        player1_name_label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        player1_name_label->setAlignment(Qt::AlignCenter);

        retranslateUi(FormOnlinepvp);

        QMetaObject::connectSlotsByName(FormOnlinepvp);
    } // setupUi

    void retranslateUi(QWidget *FormOnlinepvp)
    {
        FormOnlinepvp->setWindowTitle(QApplication::translate("FormOnlinepvp", "\344\272\224\345\255\220\346\243\213\342\200\224\342\200\224\345\234\250\347\272\277\345\257\271\346\210\230", Q_NULLPTR));
        background_label->setText(QString());
        checkerboard_label->setText(QString());
        player2->setText(QString());
        player1->setText(QString());
        undo_Button->setText(QApplication::translate("FormOnlinepvp", "\346\202\224\346\243\213", Q_NULLPTR));
        save_Button->setText(QApplication::translate("FormOnlinepvp", "\344\277\235\345\255\230\346\243\213\345\261\200", Q_NULLPTR));
        defeat_Button->setText(QApplication::translate("FormOnlinepvp", "\350\256\244\350\276\223", Q_NULLPTR));
        player_1_label->setText(QString());
        player_2_label->setText(QString());
        whosturn_label->setText(QApplication::translate("FormOnlinepvp", "\345\257\271\346\226\271\345\233\236\345\220\210", Q_NULLPTR));
        player2_name_label->setText(QApplication::translate("FormOnlinepvp", "P1", Q_NULLPTR));
        player1_name_label->setText(QApplication::translate("FormOnlinepvp", "P2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormOnlinepvp: public Ui_FormOnlinepvp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ONLINEPVP_H
