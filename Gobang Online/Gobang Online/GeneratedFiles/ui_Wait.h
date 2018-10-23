/********************************************************************************
** Form generated from reading UI file 'Wait.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAIT_H
#define UI_WAIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormWait
{
public:
    QLabel *player1_label;
    QLabel *label;
    QPushButton *start_Button;
    QLabel *backgroun_label;
    QLabel *label_3;
    QLabel *gif_label;

    void setupUi(QWidget *FormWait)
    {
        if (FormWait->objectName().isEmpty())
            FormWait->setObjectName(QStringLiteral("FormWait"));
        FormWait->resize(370, 400);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Image/Icon/\345\233\276\346\240\207.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        FormWait->setWindowIcon(icon);
        FormWait->setStyleSheet(QStringLiteral(""));
        player1_label = new QLabel(FormWait);
        player1_label->setObjectName(QStringLiteral("player1_label"));
        player1_label->setGeometry(QRect(150, 200, 70, 70));
        player1_label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Icon/play1.jpg);"));
        label = new QLabel(FormWait);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(150, 30, 70, 70));
        label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Icon/play2.jpg);"));
        start_Button = new QPushButton(FormWait);
        start_Button->setObjectName(QStringLiteral("start_Button"));
        start_Button->setGeometry(QRect(107, 320, 155, 55));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(18);
        start_Button->setFont(font);
        start_Button->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-image: url(:/new/prefix1/Image/Button/150.50.jpg);"));
        backgroun_label = new QLabel(FormWait);
        backgroun_label->setObjectName(QStringLiteral("backgroun_label"));
        backgroun_label->setGeometry(QRect(0, 0, 370, 400));
        backgroun_label->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/Image/Background/wait_\345\211\257\346\234\254.jpg);"));
        label_3 = new QLabel(FormWait);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 130, 230, 45));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\347\220\245\347\217\200"));
        font1.setPointSize(16);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);
        gif_label = new QLabel(FormWait);
        gif_label->setObjectName(QStringLiteral("gif_label"));
        gif_label->setGeometry(QRect(230, 150, 54, 12));
        backgroun_label->raise();
        player1_label->raise();
        label->raise();
        start_Button->raise();
        label_3->raise();
        gif_label->raise();

        retranslateUi(FormWait);

        QMetaObject::connectSlotsByName(FormWait);
    } // setupUi

    void retranslateUi(QWidget *FormWait)
    {
        FormWait->setWindowTitle(QApplication::translate("FormWait", "\346\255\243\345\234\250\345\214\271\351\205\215", Q_NULLPTR));
        player1_label->setText(QString());
        label->setText(QString());
        start_Button->setText(QApplication::translate("FormWait", "\345\274\200\345\247\213\346\270\270\346\210\217", Q_NULLPTR));
        backgroun_label->setText(QString());
        label_3->setText(QApplication::translate("FormWait", "\347\255\211\345\276\205\345\257\271\346\226\271\345\212\240\345\205\245\346\210\277\351\227\264", Q_NULLPTR));
        gif_label->setText(QApplication::translate("FormWait", "12312", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormWait: public Ui_FormWait {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAIT_H
