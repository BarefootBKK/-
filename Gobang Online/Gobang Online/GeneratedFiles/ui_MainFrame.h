/********************************************************************************
** Form generated from reading UI file 'MainFrame.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINFRAME_H
#define UI_MAINFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormMain
{
public:
    QPushButton *pve_Button;
    QPushButton *pvp_Button;
    QPushButton *Online_Button;
    QPushButton *Sign_Button;
    QPushButton *Exit_Button;
    QLabel *label;
    QPushButton *music_button;
    QPushButton *pushButton;
    QPushButton *replay_Button;
    QPushButton *ranking_Button;
    QLabel *log_state_label;
    QLabel *conn_state_label;
    QPushButton *help_button;
    QPushButton *nextSong_Button;

    void setupUi(QWidget *FormMain)
    {
        if (FormMain->objectName().isEmpty())
            FormMain->setObjectName(QStringLiteral("FormMain"));
        FormMain->resize(600, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Image/Icon/\345\233\276\346\240\207.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        FormMain->setWindowIcon(icon);
        FormMain->setStyleSheet(QStringLiteral(""));
        pve_Button = new QPushButton(FormMain);
        pve_Button->setObjectName(QStringLiteral("pve_Button"));
        pve_Button->setGeometry(QRect(200, 110, 205, 55));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(18);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        pve_Button->setFont(font);
        pve_Button->setCursor(QCursor(Qt::PointingHandCursor));
        pve_Button->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/Image/Button/200.50.4\343\200\202\345\211\257\346\234\254.jpg);\n"
"color: rgb(250, 250, 250);\n"
"\n"
";"));
        pvp_Button = new QPushButton(FormMain);
        pvp_Button->setObjectName(QStringLiteral("pvp_Button"));
        pvp_Button->setGeometry(QRect(200, 210, 205, 55));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(18);
        pvp_Button->setFont(font1);
        pvp_Button->setCursor(QCursor(Qt::PointingHandCursor));
        pvp_Button->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/Image/Button/200.50.4\343\200\202\345\211\257\346\234\254.jpg);\n"
"color: rgb(250, 250, 250);"));
        Online_Button = new QPushButton(FormMain);
        Online_Button->setObjectName(QStringLiteral("Online_Button"));
        Online_Button->setGeometry(QRect(200, 310, 205, 55));
        Online_Button->setFont(font1);
        Online_Button->setCursor(QCursor(Qt::PointingHandCursor));
        Online_Button->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/Image/Button/200.50.4\343\200\202\345\211\257\346\234\254.jpg);\n"
"color: rgb(250, 250, 250);\n"
"\n"
";"));
        Sign_Button = new QPushButton(FormMain);
        Sign_Button->setObjectName(QStringLiteral("Sign_Button"));
        Sign_Button->setGeometry(QRect(510, 10, 75, 23));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font2.setPointSize(11);
        Sign_Button->setFont(font2);
        Sign_Button->setCursor(QCursor(Qt::PointingHandCursor));
        Sign_Button->setStyleSheet(QLatin1String("background-color: rgb(0, 85, 127);\n"
"color: rgb(255, 255, 255);"));
        Exit_Button = new QPushButton(FormMain);
        Exit_Button->setObjectName(QStringLiteral("Exit_Button"));
        Exit_Button->setEnabled(true);
        Exit_Button->setGeometry(QRect(510, 130, 75, 23));
        Exit_Button->setFont(font2);
        Exit_Button->setCursor(QCursor(Qt::PointingHandCursor));
        Exit_Button->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 85, 127);"));
        label = new QLabel(FormMain);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 600, 600));
        label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Background/Main2.jpg);"));
        music_button = new QPushButton(FormMain);
        music_button->setObjectName(QStringLiteral("music_button"));
        music_button->setGeometry(QRect(510, 210, 75, 23));
        music_button->setFont(font2);
        music_button->setCursor(QCursor(Qt::PointingHandCursor));
        music_button->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 85, 127);"));
        pushButton = new QPushButton(FormMain);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setEnabled(true);
        pushButton->setGeometry(QRect(0, 570, 94, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font3.setPointSize(10);
        pushButton->setFont(font3);
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        pushButton->setFlat(true);
        replay_Button = new QPushButton(FormMain);
        replay_Button->setObjectName(QStringLiteral("replay_Button"));
        replay_Button->setGeometry(QRect(200, 410, 205, 55));
        replay_Button->setFont(font1);
        replay_Button->setCursor(QCursor(Qt::PointingHandCursor));
        replay_Button->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/Image/Button/200.50.4\343\200\202\345\211\257\346\234\254.jpg);\n"
"color: rgb(250, 250, 250);\n"
"\n"
"\n"
""));
        ranking_Button = new QPushButton(FormMain);
        ranking_Button->setObjectName(QStringLiteral("ranking_Button"));
        ranking_Button->setGeometry(QRect(510, 50, 75, 23));
        ranking_Button->setFont(font2);
        ranking_Button->setCursor(QCursor(Qt::PointingHandCursor));
        ranking_Button->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 85, 127);"));
        log_state_label = new QLabel(FormMain);
        log_state_label->setObjectName(QStringLiteral("log_state_label"));
        log_state_label->setGeometry(QRect(0, 5, 81, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font4.setPointSize(9);
        font4.setBold(true);
        font4.setWeight(75);
        log_state_label->setFont(font4);
        log_state_label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        log_state_label->setAlignment(Qt::AlignCenter);
        conn_state_label = new QLabel(FormMain);
        conn_state_label->setObjectName(QStringLiteral("conn_state_label"));
        conn_state_label->setGeometry(QRect(500, 570, 121, 30));
        conn_state_label->setFont(font4);
        conn_state_label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        conn_state_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        help_button = new QPushButton(FormMain);
        help_button->setObjectName(QStringLiteral("help_button"));
        help_button->setGeometry(QRect(510, 90, 75, 23));
        help_button->setFont(font2);
        help_button->setCursor(QCursor(Qt::PointingHandCursor));
        help_button->setStyleSheet(QLatin1String("background-color: rgb(0, 85, 127);\n"
"color: rgb(255, 255, 255);"));
        nextSong_Button = new QPushButton(FormMain);
        nextSong_Button->setObjectName(QStringLiteral("nextSong_Button"));
        nextSong_Button->setGeometry(QRect(510, 250, 75, 23));
        nextSong_Button->setFont(font2);
        nextSong_Button->setCursor(QCursor(Qt::PointingHandCursor));
        nextSong_Button->setStyleSheet(QLatin1String("background-color: rgb(0, 85, 127);\n"
"color: rgb(255, 255, 255);"));
        label->raise();
        pve_Button->raise();
        pvp_Button->raise();
        Online_Button->raise();
        Sign_Button->raise();
        Exit_Button->raise();
        music_button->raise();
        pushButton->raise();
        replay_Button->raise();
        ranking_Button->raise();
        log_state_label->raise();
        conn_state_label->raise();
        help_button->raise();
        nextSong_Button->raise();

        retranslateUi(FormMain);

        pushButton->setDefault(false);


        QMetaObject::connectSlotsByName(FormMain);
    } // setupUi

    void retranslateUi(QWidget *FormMain)
    {
        FormMain->setWindowTitle(QApplication::translate("FormMain", "\344\272\224\345\255\220\346\243\213", Q_NULLPTR));
        pve_Button->setText(QApplication::translate("FormMain", "\346\234\254\345\234\260\344\272\272\346\234\272\345\257\271\346\210\230", Q_NULLPTR));
        pvp_Button->setText(QApplication::translate("FormMain", "\346\234\254\345\234\260\344\272\272\344\272\272\345\257\271\346\210\230", Q_NULLPTR));
        Online_Button->setText(QApplication::translate("FormMain", "\350\201\224\347\275\221\345\257\271\346\210\230", Q_NULLPTR));
        Sign_Button->setText(QApplication::translate("FormMain", "\347\231\273\345\275\225", Q_NULLPTR));
        Exit_Button->setText(QApplication::translate("FormMain", "\351\200\200\345\207\272", Q_NULLPTR));
        label->setText(QString());
        music_button->setText(QApplication::translate("FormMain", "\351\237\263\344\271\220", Q_NULLPTR));
        pushButton->setText(QApplication::translate("FormMain", "\350\277\236\346\216\245\350\256\276\347\275\256", Q_NULLPTR));
        replay_Button->setText(QApplication::translate("FormMain", "\346\243\213\345\261\200\345\233\236\346\224\276", Q_NULLPTR));
        ranking_Button->setText(QApplication::translate("FormMain", "\346\216\222\350\241\214\346\246\234", Q_NULLPTR));
        log_state_label->setText(QApplication::translate("FormMain", "\346\234\252\347\231\273\345\275\225", Q_NULLPTR));
        conn_state_label->setText(QApplication::translate("FormMain", "\346\234\252\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", Q_NULLPTR));
        help_button->setText(QApplication::translate("FormMain", "\345\270\256\345\212\251", Q_NULLPTR));
        nextSong_Button->setText(QApplication::translate("FormMain", "\344\270\213\344\270\200\351\246\226", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormMain: public Ui_FormMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINFRAME_H
