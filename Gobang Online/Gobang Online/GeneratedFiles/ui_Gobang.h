/********************************************************************************
** Form generated from reading UI file 'Gobang.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOBANG_H
#define UI_GOBANG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <chessboard.h>

QT_BEGIN_NAMESPACE

class Ui_GobangClass
{
public:
    ChessBoard *checkerboard_label;
    QPushButton *undo_button;
    QPushButton *restart_button;
    QPushButton *mainMenu_button;
    QLabel *background_label;
    QPushButton *save_button;

    void setupUi(QWidget *GobangClass)
    {
        if (GobangClass->objectName().isEmpty())
            GobangClass->setObjectName(QStringLiteral("GobangClass"));
        GobangClass->resize(1250, 900);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Gobang/Image/Icon/\345\233\276\346\240\207.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        GobangClass->setWindowIcon(icon);
        GobangClass->setStyleSheet(QStringLiteral(""));
        checkerboard_label = new ChessBoard(GobangClass);
        checkerboard_label->setObjectName(QStringLiteral("checkerboard_label"));
        checkerboard_label->setGeometry(QRect(70, 30, 840, 840));
        checkerboard_label->setStyleSheet(QStringLiteral("background-image: url(:/Gobang/Image/Background/check.jpg);"));
        checkerboard_label->setAlignment(Qt::AlignCenter);
        undo_button = new QPushButton(GobangClass);
        undo_button->setObjectName(QStringLiteral("undo_button"));
        undo_button->setGeometry(QRect(1000, 700, 155, 55));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(18);
        undo_button->setFont(font);
        undo_button->setCursor(QCursor(Qt::PointingHandCursor));
        undo_button->setStyleSheet(QStringLiteral("background-image: url(:/Gobang/Image/Button/150.50.jpg);color: rgb(250, 250, 250);"));
        restart_button = new QPushButton(GobangClass);
        restart_button->setObjectName(QStringLiteral("restart_button"));
        restart_button->setGeometry(QRect(1000, 800, 155, 55));
        restart_button->setFont(font);
        restart_button->setCursor(QCursor(Qt::PointingHandCursor));
        restart_button->setStyleSheet(QStringLiteral("background-image: url(:/Gobang/Image/Button/150.50.jpg);color: rgb(250, 250, 250);"));
        mainMenu_button = new QPushButton(GobangClass);
        mainMenu_button->setObjectName(QStringLiteral("mainMenu_button"));
        mainMenu_button->setGeometry(QRect(1000, 90, 155, 55));
        mainMenu_button->setFont(font);
        mainMenu_button->setCursor(QCursor(Qt::PointingHandCursor));
        mainMenu_button->setStyleSheet(QLatin1String("color: rgb(250, 250, 250);\n"
"background-image: url(:/Gobang/Image/Button/150.50.jpg);"));
        background_label = new QLabel(GobangClass);
        background_label->setObjectName(QStringLiteral("background_label"));
        background_label->setGeometry(QRect(0, 0, 1250, 900));
        background_label->setStyleSheet(QLatin1String("\n"
"background-image: url(:/Gobang/Image/Background/Gme1.jpg);"));
        save_button = new QPushButton(GobangClass);
        save_button->setObjectName(QStringLiteral("save_button"));
        save_button->setGeometry(QRect(1000, 190, 155, 55));
        save_button->setFont(font);
        save_button->setCursor(QCursor(Qt::PointingHandCursor));
        save_button->setStyleSheet(QLatin1String("background-image: url(:/Gobang/Image/Button/150.50.jpg);\n"
"color: rgb(250, 250, 250);"));
        background_label->raise();
        checkerboard_label->raise();
        undo_button->raise();
        restart_button->raise();
        mainMenu_button->raise();
        save_button->raise();

        retranslateUi(GobangClass);

        QMetaObject::connectSlotsByName(GobangClass);
    } // setupUi

    void retranslateUi(QWidget *GobangClass)
    {
        GobangClass->setWindowTitle(QApplication::translate("GobangClass", "\344\272\224\345\255\220\346\243\213\342\200\224\346\234\254\345\234\260\344\272\272\344\272\272\345\257\271\346\210\230", Q_NULLPTR));
        checkerboard_label->setText(QString());
        undo_button->setText(QApplication::translate("GobangClass", "\346\202\224\346\243\213", Q_NULLPTR));
        restart_button->setText(QApplication::translate("GobangClass", "\351\207\215\346\226\260\345\274\200\345\247\213", Q_NULLPTR));
        mainMenu_button->setText(QApplication::translate("GobangClass", "\344\270\273\350\217\234\345\215\225", Q_NULLPTR));
        background_label->setText(QString());
        save_button->setText(QApplication::translate("GobangClass", "\344\277\235\345\255\230\346\243\213\345\261\200", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GobangClass: public Ui_GobangClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOBANG_H
