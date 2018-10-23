/********************************************************************************
** Form generated from reading UI file 'Pve.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PVE_H
#define UI_PVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <chessboard.h>

QT_BEGIN_NAMESPACE

class Ui_FormPve
{
public:
    QLabel *background_label;
    ChessBoard *checkerboard_label;
    QPushButton *mainMenu_Button;
    QPushButton *save_Button;
    QPushButton *undo_Button;
    QPushButton *restart_Button;
    QComboBox *comboBox;

    void setupUi(QWidget *FormPve)
    {
        if (FormPve->objectName().isEmpty())
            FormPve->setObjectName(QStringLiteral("FormPve"));
        FormPve->resize(1250, 900);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Image/Icon/\345\233\276\346\240\207.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        FormPve->setWindowIcon(icon);
        background_label = new QLabel(FormPve);
        background_label->setObjectName(QStringLiteral("background_label"));
        background_label->setGeometry(QRect(0, 0, 1250, 900));
        background_label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Background/Gme1.jpg);"));
        checkerboard_label = new ChessBoard(FormPve);
        checkerboard_label->setObjectName(QStringLiteral("checkerboard_label"));
        checkerboard_label->setGeometry(QRect(70, 30, 840, 840));
        checkerboard_label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Background/check.jpg);"));
        mainMenu_Button = new QPushButton(FormPve);
        mainMenu_Button->setObjectName(QStringLiteral("mainMenu_Button"));
        mainMenu_Button->setGeometry(QRect(1000, 500, 155, 55));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(18);
        mainMenu_Button->setFont(font);
        mainMenu_Button->setCursor(QCursor(Qt::PointingHandCursor));
        mainMenu_Button->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Button/150.50.jpg);"));
        save_Button = new QPushButton(FormPve);
        save_Button->setObjectName(QStringLiteral("save_Button"));
        save_Button->setGeometry(QRect(1000, 600, 155, 55));
        save_Button->setFont(font);
        save_Button->setCursor(QCursor(Qt::PointingHandCursor));
        save_Button->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Button/150.50.jpg);"));
        undo_Button = new QPushButton(FormPve);
        undo_Button->setObjectName(QStringLiteral("undo_Button"));
        undo_Button->setGeometry(QRect(1000, 700, 155, 55));
        undo_Button->setFont(font);
        undo_Button->setCursor(QCursor(Qt::PointingHandCursor));
        undo_Button->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Button/150.50.jpg);"));
        restart_Button = new QPushButton(FormPve);
        restart_Button->setObjectName(QStringLiteral("restart_Button"));
        restart_Button->setGeometry(QRect(1000, 800, 155, 55));
        restart_Button->setFont(font);
        restart_Button->setCursor(QCursor(Qt::PointingHandCursor));
        restart_Button->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Button/150.50.jpg);"));
        comboBox = new QComboBox(FormPve);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(1000, 400, 151, 31));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        comboBox->setFont(font1);
        comboBox->setCursor(QCursor(Qt::OpenHandCursor));
        comboBox->setStyleSheet(QStringLiteral(""));

        retranslateUi(FormPve);

        QMetaObject::connectSlotsByName(FormPve);
    } // setupUi

    void retranslateUi(QWidget *FormPve)
    {
        FormPve->setWindowTitle(QApplication::translate("FormPve", "\344\272\224\345\255\220\346\243\213\342\200\224\342\200\224\344\272\272\346\234\272\345\257\271\346\210\230", Q_NULLPTR));
        background_label->setText(QString());
        checkerboard_label->setText(QString());
        mainMenu_Button->setText(QApplication::translate("FormPve", "\350\277\224\345\233\236\344\270\273\350\217\234\345\215\225", Q_NULLPTR));
        save_Button->setText(QApplication::translate("FormPve", "\344\277\235\345\255\230\346\243\213\345\261\200", Q_NULLPTR));
        undo_Button->setText(QApplication::translate("FormPve", "\346\202\224\346\243\213", Q_NULLPTR));
        restart_Button->setText(QApplication::translate("FormPve", "\351\207\215\346\226\260\345\274\200\345\247\213", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("FormPve", "\347\256\200\345\215\225\344\272\272\346\234\272", Q_NULLPTR)
         << QApplication::translate("FormPve", "\344\270\255\347\255\211\344\272\272\346\234\272", Q_NULLPTR)
         << QApplication::translate("FormPve", "\345\233\260\351\232\276\344\272\272\346\234\272", Q_NULLPTR)
         << QApplication::translate("FormPve", "\345\231\251\346\242\246\344\272\272\346\234\272", Q_NULLPTR)
        );
    } // retranslateUi

};

namespace Ui {
    class FormPve: public Ui_FormPve {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PVE_H
