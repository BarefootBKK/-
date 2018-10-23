/********************************************************************************
** Form generated from reading UI file 'Log.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_H
#define UI_LOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormLog
{
public:
    QLabel *label_3;
    QLabel *account_label;
    QLabel *password_label;
    QLineEdit *account_edit;
    QLineEdit *password_edit;
    QPushButton *login_button;
    QPushButton *signin_button;
    QPushButton *exit_button;
    QLabel *confirm_label;
    QLineEdit *confirm_edit;
    QLabel *nickname_label;
    QLineEdit *nickname_edit;
    QPushButton *back_button;
    QPushButton *register_button;
    QLabel *hint_label;

    void setupUi(QWidget *FormLog)
    {
        if (FormLog->objectName().isEmpty())
            FormLog->setObjectName(QStringLiteral("FormLog"));
        FormLog->resize(600, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Image/Icon/\345\233\276\346\240\207.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        FormLog->setWindowIcon(icon);
        FormLog->setStyleSheet(QStringLiteral(""));
        label_3 = new QLabel(FormLog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 0, 600, 600));
        label_3->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Background/Main2.jpg);"));
        account_label = new QLabel(FormLog);
        account_label->setObjectName(QStringLiteral("account_label"));
        account_label->setGeometry(QRect(80, 180, 101, 51));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(16);
        account_label->setFont(font);
        account_label->setCursor(QCursor(Qt::IBeamCursor));
        account_label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        account_label->setAlignment(Qt::AlignCenter);
        password_label = new QLabel(FormLog);
        password_label->setObjectName(QStringLiteral("password_label"));
        password_label->setGeometry(QRect(80, 250, 101, 51));
        password_label->setFont(font);
        password_label->setCursor(QCursor(Qt::IBeamCursor));
        password_label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        password_label->setAlignment(Qt::AlignCenter);
        account_edit = new QLineEdit(FormLog);
        account_edit->setObjectName(QStringLiteral("account_edit"));
        account_edit->setGeometry(QRect(190, 183, 281, 41));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(9);
        font1.setBold(true);
        font1.setWeight(75);
        account_edit->setFont(font1);
        account_edit->setStyleSheet(QStringLiteral("color: rgb(39, 54, 83);"));
        password_edit = new QLineEdit(FormLog);
        password_edit->setObjectName(QStringLiteral("password_edit"));
        password_edit->setGeometry(QRect(190, 255, 281, 41));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setBold(true);
        font2.setWeight(75);
        password_edit->setFont(font2);
        password_edit->setStyleSheet(QStringLiteral("color: rgb(39, 54, 83);"));
        login_button = new QPushButton(FormLog);
        login_button->setObjectName(QStringLiteral("login_button"));
        login_button->setGeometry(QRect(190, 407, 105, 45));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font3.setPointSize(14);
        login_button->setFont(font3);
        login_button->setCursor(QCursor(Qt::PointingHandCursor));
        login_button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/100.40.jpg);\n"
"color: rgb(255, 255, 255);"));
        signin_button = new QPushButton(FormLog);
        signin_button->setObjectName(QStringLiteral("signin_button"));
        signin_button->setGeometry(QRect(366, 407, 105, 45));
        signin_button->setFont(font3);
        signin_button->setCursor(QCursor(Qt::PointingHandCursor));
        signin_button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/100.40.jpg);\n"
"color: rgb(255, 255, 255);"));
        exit_button = new QPushButton(FormLog);
        exit_button->setObjectName(QStringLiteral("exit_button"));
        exit_button->setGeometry(QRect(548, 578, 50, 20));
        exit_button->setFont(font3);
        exit_button->setCursor(QCursor(Qt::PointingHandCursor));
        exit_button->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"background-color: rgb(0, 85, 127);"));
        confirm_label = new QLabel(FormLog);
        confirm_label->setObjectName(QStringLiteral("confirm_label"));
        confirm_label->setGeometry(QRect(60, 320, 101, 51));
        confirm_label->setFont(font);
        confirm_label->setCursor(QCursor(Qt::IBeamCursor));
        confirm_label->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
""));
        confirm_label->setAlignment(Qt::AlignCenter);
        confirm_edit = new QLineEdit(FormLog);
        confirm_edit->setObjectName(QStringLiteral("confirm_edit"));
        confirm_edit->setGeometry(QRect(190, 325, 281, 41));
        confirm_edit->setFont(font2);
        confirm_edit->setStyleSheet(QStringLiteral("color: rgb(39, 54, 83);"));
        nickname_label = new QLabel(FormLog);
        nickname_label->setObjectName(QStringLiteral("nickname_label"));
        nickname_label->setGeometry(QRect(80, 107, 101, 51));
        nickname_label->setFont(font);
        nickname_label->setCursor(QCursor(Qt::IBeamCursor));
        nickname_label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        nickname_label->setAlignment(Qt::AlignCenter);
        nickname_edit = new QLineEdit(FormLog);
        nickname_edit->setObjectName(QStringLiteral("nickname_edit"));
        nickname_edit->setGeometry(QRect(190, 110, 281, 41));
        nickname_edit->setFont(font2);
        nickname_edit->setStyleSheet(QStringLiteral("color: rgb(39, 54, 83);"));
        back_button = new QPushButton(FormLog);
        back_button->setObjectName(QStringLiteral("back_button"));
        back_button->setGeometry(QRect(190, 407, 105, 45));
        back_button->setFont(font3);
        back_button->setCursor(QCursor(Qt::PointingHandCursor));
        back_button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/100.40.jpg);\n"
"color: rgb(255, 255, 255);"));
        register_button = new QPushButton(FormLog);
        register_button->setObjectName(QStringLiteral("register_button"));
        register_button->setGeometry(QRect(366, 407, 105, 45));
        register_button->setFont(font3);
        register_button->setCursor(QCursor(Qt::PointingHandCursor));
        register_button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/100.40.jpg);\n"
"color: rgb(255, 255, 255);"));
        hint_label = new QLabel(FormLog);
        hint_label->setObjectName(QStringLiteral("hint_label"));
        hint_label->setGeometry(QRect(190, 20, 281, 71));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font4.setPointSize(28);
        hint_label->setFont(font4);
        hint_label->setStyleSheet(QStringLiteral("color: qlineargradient(spread:reflect, x1:0.418, y1:0.459818, x2:1, y2:0.023, stop:0.502488 rgba(68, 138, 255, 249), stop:1 rgba(255, 255, 255, 255));"));
        hint_label->setAlignment(Qt::AlignCenter);

        retranslateUi(FormLog);

        QMetaObject::connectSlotsByName(FormLog);
    } // setupUi

    void retranslateUi(QWidget *FormLog)
    {
        FormLog->setWindowTitle(QApplication::translate("FormLog", "\344\272\224\345\255\220\346\243\213\342\200\224\347\231\273\345\275\225\345\217\212\346\263\250\345\206\214", Q_NULLPTR));
        label_3->setText(QString());
        account_label->setText(QApplication::translate("FormLog", "\345\270\220\345\217\267", Q_NULLPTR));
        password_label->setText(QApplication::translate("FormLog", "\345\257\206\347\240\201", Q_NULLPTR));
        account_edit->setText(QString());
        login_button->setText(QApplication::translate("FormLog", "\347\231\273\345\275\225", Q_NULLPTR));
        signin_button->setText(QApplication::translate("FormLog", "\346\263\250\345\206\214", Q_NULLPTR));
        exit_button->setText(QApplication::translate("FormLog", "exit", Q_NULLPTR));
        confirm_label->setText(QApplication::translate("FormLog", "\347\241\256\350\256\244\345\257\206\347\240\201", Q_NULLPTR));
        nickname_label->setText(QApplication::translate("FormLog", "\346\230\265\347\247\260", Q_NULLPTR));
        back_button->setText(QApplication::translate("FormLog", "\350\277\224\345\233\236", Q_NULLPTR));
        register_button->setText(QApplication::translate("FormLog", "\346\263\250\345\206\214", Q_NULLPTR));
        hint_label->setText(QApplication::translate("FormLog", "\347\231\273\345\275\225", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormLog: public Ui_FormLog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_H
