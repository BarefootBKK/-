/********************************************************************************
** Form generated from reading UI file 'help.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELP_H
#define UI_HELP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Formhelp
{
public:
    QLabel *background_label;
    QPushButton *return_Button;
    QLabel *developer_label;
    QLabel *version_label;
    QLabel *help_label;
    QRadioButton *step_1_radioButton;
    QRadioButton *step_2_radioButton;
    QRadioButton *step_3_radioButton;
    QLabel *hint_label;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Formhelp)
    {
        if (Formhelp->objectName().isEmpty())
            Formhelp->setObjectName(QStringLiteral("Formhelp"));
        Formhelp->resize(1050, 900);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Gobang/Image/Icon/\345\233\276\346\240\207.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        Formhelp->setWindowIcon(icon);
        background_label = new QLabel(Formhelp);
        background_label->setObjectName(QStringLiteral("background_label"));
        background_label->setGeometry(QRect(0, 0, 1050, 900));
        background_label->setStyleSheet(QStringLiteral("background-image: url(:/Gobang/Image/Background/Gme1.jpg);"));
        return_Button = new QPushButton(Formhelp);
        return_Button->setObjectName(QStringLiteral("return_Button"));
        return_Button->setGeometry(QRect(472, 820, 106, 45));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(14);
        return_Button->setFont(font);
        return_Button->setCursor(QCursor(Qt::PointingHandCursor));
        return_Button->setStyleSheet(QLatin1String("background-image: url(:/Gobang/Image/Button/100.40.jpg);\n"
"color: rgb(255, 255, 255);"));
        developer_label = new QLabel(Formhelp);
        developer_label->setObjectName(QStringLiteral("developer_label"));
        developer_label->setGeometry(QRect(320, 690, 461, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        developer_label->setFont(font1);
        developer_label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        developer_label->setAlignment(Qt::AlignCenter);
        version_label = new QLabel(Formhelp);
        version_label->setObjectName(QStringLiteral("version_label"));
        version_label->setGeometry(QRect(350, 750, 361, 41));
        version_label->setFont(font1);
        version_label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        version_label->setAlignment(Qt::AlignCenter);
        help_label = new QLabel(Formhelp);
        help_label->setObjectName(QStringLiteral("help_label"));
        help_label->setGeometry(QRect(210, 10, 630, 630));
        help_label->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-image: url(:/Gobang/Image/help/1.JPG);"));
        help_label->setAlignment(Qt::AlignCenter);
        step_1_radioButton = new QRadioButton(Formhelp);
        step_1_radioButton->setObjectName(QStringLiteral("step_1_radioButton"));
        step_1_radioButton->setGeometry(QRect(429, 660, 21, 20));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setBold(true);
        font2.setWeight(75);
        step_1_radioButton->setFont(font2);
        step_1_radioButton->setCursor(QCursor(Qt::PointingHandCursor));
        step_1_radioButton->setLayoutDirection(Qt::RightToLeft);
        step_1_radioButton->setStyleSheet(QStringLiteral(""));
        step_1_radioButton->setIconSize(QSize(30, 30));
        step_1_radioButton->setChecked(true);
        step_1_radioButton->setAutoRepeatDelay(300);
        step_1_radioButton->setAutoRepeatInterval(100);
        step_2_radioButton = new QRadioButton(Formhelp);
        step_2_radioButton->setObjectName(QStringLiteral("step_2_radioButton"));
        step_2_radioButton->setGeometry(QRect(520, 660, 21, 19));
        step_2_radioButton->setCursor(QCursor(Qt::PointingHandCursor));
        step_3_radioButton = new QRadioButton(Formhelp);
        step_3_radioButton->setObjectName(QStringLiteral("step_3_radioButton"));
        step_3_radioButton->setGeometry(QRect(610, 660, 16, 19));
        step_3_radioButton->setFont(font2);
        step_3_radioButton->setCursor(QCursor(Qt::PointingHandCursor));
        step_3_radioButton->setStyleSheet(QStringLiteral(""));
        hint_label = new QLabel(Formhelp);
        hint_label->setObjectName(QStringLiteral("hint_label"));
        hint_label->setGeometry(QRect(240, 500, 571, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        hint_label->setFont(font3);
        hint_label->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(85, 166, 160);"));
        hint_label->setAlignment(Qt::AlignCenter);
        label = new QLabel(Formhelp);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(231, 660, 201, 20));
        label->setFont(font2);
        label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(Formhelp);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(630, 660, 181, 16));
        label_2->setFont(font2);
        label_2->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        retranslateUi(Formhelp);

        QMetaObject::connectSlotsByName(Formhelp);
    } // setupUi

    void retranslateUi(QWidget *Formhelp)
    {
        Formhelp->setWindowTitle(QApplication::translate("Formhelp", "\345\270\256\345\212\251\350\257\264\346\230\216", Q_NULLPTR));
        background_label->setText(QString());
        return_Button->setText(QApplication::translate("Formhelp", "\350\277\224\345\233\236", Q_NULLPTR));
        developer_label->setText(QApplication::translate("Formhelp", "\345\274\200\345\217\221\344\272\272\345\221\230\357\274\232\344\275\225\346\237\217\345\235\244\357\274\214\350\203\241\346\235\250\357\274\214\351\203\235\346\205\247\345\263\260\357\274\214\346\234\261\345\255\220\346\275\207", Q_NULLPTR));
        version_label->setText(QApplication::translate("Formhelp", "\347\211\210\346\234\254\357\274\232\344\272\224\345\255\220\346\243\213(\346\230\237\347\251\272\344\270\273\351\242\230\347\211\210)V1.3", Q_NULLPTR));
        help_label->setText(QString());
        step_1_radioButton->setText(QString());
        step_2_radioButton->setText(QString());
        step_3_radioButton->setText(QString());
        hint_label->setText(QApplication::translate("Formhelp", "\347\202\271\345\207\273\344\273\273\344\270\200\346\234\252\346\234\211\346\243\213\345\255\220\347\232\204\350\220\275\345\255\220\347\202\271\345\217\257\344\270\213\346\243\213", Q_NULLPTR));
        label->setText(QApplication::translate("Formhelp", "> > > \347\202\271\345\207\273\345\210\207\346\215\242 > > >  ", Q_NULLPTR));
        label_2->setText(QApplication::translate("Formhelp", "  < < < \347\202\271\345\207\273\345\210\207\346\215\242 < < <", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Formhelp: public Ui_Formhelp {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELP_H
