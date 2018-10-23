/********************************************************************************
** Form generated from reading UI file 'MessageDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESSAGEDIALOG_H
#define UI_MESSAGEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_MessaDialog
{
public:
    QLabel *msg_label;
    QPushButton *ok_button;
    QLabel *backgroun_label;
    QPushButton *cancel_button;

    void setupUi(QDialog *MessaDialog)
    {
        if (MessaDialog->objectName().isEmpty())
            MessaDialog->setObjectName(QStringLiteral("MessaDialog"));
        MessaDialog->resize(330, 200);
        MessaDialog->setStyleSheet(QStringLiteral(""));
        msg_label = new QLabel(MessaDialog);
        msg_label->setObjectName(QStringLiteral("msg_label"));
        msg_label->setGeometry(QRect(0, 0, 330, 150));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\345\275\251\344\272\221"));
        font.setPointSize(24);
        font.setBold(false);
        font.setWeight(50);
        msg_label->setFont(font);
        msg_label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        msg_label->setAlignment(Qt::AlignCenter);
        ok_button = new QPushButton(MessaDialog);
        ok_button->setObjectName(QStringLiteral("ok_button"));
        ok_button->setGeometry(QRect(70, 150, 80, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(14);
        ok_button->setFont(font1);
        ok_button->setCursor(QCursor(Qt::PointingHandCursor));
        ok_button->setFocusPolicy(Qt::StrongFocus);
        ok_button->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:reflect, x1:0.418, y1:0.459818, x2:1, y2:0.023, stop:0.502488 rgba(68, 12, 175, 193), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);"));
        ok_button->setFlat(false);
        backgroun_label = new QLabel(MessaDialog);
        backgroun_label->setObjectName(QStringLiteral("backgroun_label"));
        backgroun_label->setGeometry(QRect(0, 0, 400, 200));
        backgroun_label->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/Image/Background/\346\266\210\346\201\257\346\217\220\347\244\272\350\203\214\346\231\257.jpg);"));
        cancel_button = new QPushButton(MessaDialog);
        cancel_button->setObjectName(QStringLiteral("cancel_button"));
        cancel_button->setGeometry(QRect(180, 150, 80, 30));
        cancel_button->setFont(font1);
        cancel_button->setCursor(QCursor(Qt::PointingHandCursor));
        cancel_button->setFocusPolicy(Qt::StrongFocus);
        cancel_button->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:reflect, x1:0.418, y1:0.459818, x2:1, y2:0.023, stop:0.502488 rgba(68, 12, 175, 193), stop:1 rgba(255, 255, 255, 255));\n"
"color: rgb(255, 255, 255);"));
        cancel_button->setFlat(false);
        backgroun_label->raise();
        msg_label->raise();
        ok_button->raise();
        cancel_button->raise();

        retranslateUi(MessaDialog);

        ok_button->setDefault(false);
        cancel_button->setDefault(false);


        QMetaObject::connectSlotsByName(MessaDialog);
    } // setupUi

    void retranslateUi(QDialog *MessaDialog)
    {
        MessaDialog->setWindowTitle(QApplication::translate("MessaDialog", "Dialog", Q_NULLPTR));
        msg_label->setText(QApplication::translate("MessaDialog", "TextLabel", Q_NULLPTR));
        ok_button->setText(QApplication::translate("MessaDialog", "\347\241\256\345\256\232", Q_NULLPTR));
        backgroun_label->setText(QString());
        cancel_button->setText(QApplication::translate("MessaDialog", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MessaDialog: public Ui_MessaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESSAGEDIALOG_H
