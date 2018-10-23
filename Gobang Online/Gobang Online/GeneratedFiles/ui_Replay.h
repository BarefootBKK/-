/********************************************************************************
** Form generated from reading UI file 'Replay.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REPLAY_H
#define UI_REPLAY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <chessboard.h>

QT_BEGIN_NAMESPACE

class Ui_FormReplay
{
public:
    QLabel *background_label;
    ChessBoard *checkerboard_label;
    QPushButton *next_Button;
    QPushButton *last_Button;
    QPushButton *return_Button;
    QPushButton *openboard_button;
    QComboBox *playPattern_combox;
    QPushButton *play_button;
    QDoubleSpinBox *speed_SpinBox;

    void setupUi(QWidget *FormReplay)
    {
        if (FormReplay->objectName().isEmpty())
            FormReplay->setObjectName(QStringLiteral("FormReplay"));
        FormReplay->resize(1250, 900);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Image/Chess/\345\233\276\346\240\207.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        FormReplay->setWindowIcon(icon);
        background_label = new QLabel(FormReplay);
        background_label->setObjectName(QStringLiteral("background_label"));
        background_label->setGeometry(QRect(0, 0, 1250, 900));
        background_label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Background/Gme1.jpg);"));
        checkerboard_label = new ChessBoard(FormReplay);
        checkerboard_label->setObjectName(QStringLiteral("checkerboard_label"));
        checkerboard_label->setGeometry(QRect(30, 20, 840, 840));
        checkerboard_label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Background/check.jpg);"));
        next_Button = new QPushButton(FormReplay);
        next_Button->setObjectName(QStringLiteral("next_Button"));
        next_Button->setGeometry(QRect(1100, 700, 105, 45));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(18);
        next_Button->setFont(font);
        next_Button->setCursor(QCursor(Qt::PointingHandCursor));
        next_Button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/100.40.jpg);\n"
"color: rgb(250, 250, 250);"));
        last_Button = new QPushButton(FormReplay);
        last_Button->setObjectName(QStringLiteral("last_Button"));
        last_Button->setGeometry(QRect(950, 700, 105, 45));
        last_Button->setFont(font);
        last_Button->setCursor(QCursor(Qt::PointingHandCursor));
        last_Button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/100.40.jpg);\n"
"color: rgb(250, 250, 250);"));
        return_Button = new QPushButton(FormReplay);
        return_Button->setObjectName(QStringLiteral("return_Button"));
        return_Button->setGeometry(QRect(1000, 800, 155, 55));
        return_Button->setFont(font);
        return_Button->setCursor(QCursor(Qt::PointingHandCursor));
        return_Button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/150.50.jpg);\n"
"color: rgb(250, 250, 250);"));
        openboard_button = new QPushButton(FormReplay);
        openboard_button->setObjectName(QStringLiteral("openboard_button"));
        openboard_button->setGeometry(QRect(1000, 200, 155, 55));
        openboard_button->setFont(font);
        openboard_button->setCursor(QCursor(Qt::PointingHandCursor));
        openboard_button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/150.50.jpg);\n"
"color: rgb(250, 250, 250);"));
        playPattern_combox = new QComboBox(FormReplay);
        playPattern_combox->setObjectName(QStringLiteral("playPattern_combox"));
        playPattern_combox->setGeometry(QRect(1000, 400, 155, 40));
        playPattern_combox->setFont(font);
        playPattern_combox->setCursor(QCursor(Qt::OpenHandCursor));
        playPattern_combox->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/Image/Button/150.50.jpg);\n"
"selection-background-color: rgb(41, 40, 100);\n"
"selection-color: rgb(255, 255, 255);\n"
"color: rgb(255, 85, 255);\n"
""));
        play_button = new QPushButton(FormReplay);
        play_button->setObjectName(QStringLiteral("play_button"));
        play_button->setGeometry(QRect(1000, 500, 155, 55));
        play_button->setFont(font);
        play_button->setCursor(QCursor(Qt::PointingHandCursor));
        play_button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/150.50.jpg);\n"
"color: rgb(250, 250, 250);"));
        speed_SpinBox = new QDoubleSpinBox(FormReplay);
        speed_SpinBox->setObjectName(QStringLiteral("speed_SpinBox"));
        speed_SpinBox->setGeometry(QRect(1000, 600, 155, 45));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\346\226\260\351\255\217"));
        font1.setPointSize(14);
        speed_SpinBox->setFont(font1);
        speed_SpinBox->setStyleSheet(QLatin1String("border-image: url(:/new/prefix1/Image/Button/100.40.jpg);\n"
"color: rgb(255, 170, 255);"));
        speed_SpinBox->setAlignment(Qt::AlignCenter);
        speed_SpinBox->setReadOnly(false);
        speed_SpinBox->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        speed_SpinBox->setDecimals(1);
        speed_SpinBox->setMinimum(0.5);
        speed_SpinBox->setMaximum(2);
        speed_SpinBox->setSingleStep(0.5);
        speed_SpinBox->setValue(1);

        retranslateUi(FormReplay);

        QMetaObject::connectSlotsByName(FormReplay);
    } // setupUi

    void retranslateUi(QWidget *FormReplay)
    {
        FormReplay->setWindowTitle(QApplication::translate("FormReplay", "\345\233\236\346\224\276", Q_NULLPTR));
        background_label->setText(QString());
        checkerboard_label->setText(QString());
        next_Button->setText(QApplication::translate("FormReplay", "\344\270\213\344\270\200\346\255\245", Q_NULLPTR));
        last_Button->setText(QApplication::translate("FormReplay", "\344\270\212\344\270\200\346\255\245", Q_NULLPTR));
        return_Button->setText(QApplication::translate("FormReplay", "\350\277\224\345\233\236", Q_NULLPTR));
        openboard_button->setText(QApplication::translate("FormReplay", "\346\211\223\345\274\200\346\243\213\345\261\200", Q_NULLPTR));
        playPattern_combox->clear();
        playPattern_combox->insertItems(0, QStringList()
         << QApplication::translate("FormReplay", "\350\207\252\345\212\250", Q_NULLPTR)
         << QApplication::translate("FormReplay", "\346\211\213\345\212\250", Q_NULLPTR)
        );
        play_button->setText(QApplication::translate("FormReplay", "\346\222\255\346\224\276", Q_NULLPTR));
        speed_SpinBox->setPrefix(QApplication::translate("FormReplay", "\351\200\237\345\272\246:", Q_NULLPTR));
        speed_SpinBox->setSuffix(QApplication::translate("FormReplay", "\345\200\215", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormReplay: public Ui_FormReplay {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REPLAY_H
