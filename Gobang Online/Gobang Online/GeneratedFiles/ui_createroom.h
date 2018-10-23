/********************************************************************************
** Form generated from reading UI file 'createroom.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CREATEROOM_H
#define UI_CREATEROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SetRoomDialog
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *hboxLayout;
    QPushButton *okButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QLineEdit *roomname_edit;
    QLabel *roomname_label;
    QCheckBox *type_checkBox;
    QLineEdit *key_edit;
    QLabel *setKey_label;
    QLabel *label;

    void setupUi(QDialog *SetRoomDialog)
    {
        if (SetRoomDialog->objectName().isEmpty())
            SetRoomDialog->setObjectName(QStringLiteral("SetRoomDialog"));
        SetRoomDialog->resize(400, 300);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Image/Icon/\345\233\276\346\240\207.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        SetRoomDialog->setWindowIcon(icon);
        layoutWidget = new QWidget(SetRoomDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 250, 241, 33));
        hboxLayout = new QHBoxLayout(layoutWidget);
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QStringLiteral("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        okButton = new QPushButton(layoutWidget);
        okButton->setObjectName(QStringLiteral("okButton"));

        hboxLayout->addWidget(okButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        hboxLayout->addItem(horizontalSpacer);

        cancelButton = new QPushButton(layoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        hboxLayout->addWidget(cancelButton);

        roomname_edit = new QLineEdit(SetRoomDialog);
        roomname_edit->setObjectName(QStringLiteral("roomname_edit"));
        roomname_edit->setGeometry(QRect(130, 60, 181, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font.setPointSize(10);
        roomname_edit->setFont(font);
        roomname_label = new QLabel(SetRoomDialog);
        roomname_label->setObjectName(QStringLiteral("roomname_label"));
        roomname_label->setGeometry(QRect(19, 60, 101, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(14);
        roomname_label->setFont(font1);
        roomname_label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        roomname_label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        type_checkBox = new QCheckBox(SetRoomDialog);
        type_checkBox->setObjectName(QStringLiteral("type_checkBox"));
        type_checkBox->setGeometry(QRect(170, 130, 91, 19));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(10);
        type_checkBox->setFont(font2);
        type_checkBox->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        key_edit = new QLineEdit(SetRoomDialog);
        key_edit->setObjectName(QStringLiteral("key_edit"));
        key_edit->setGeometry(QRect(130, 170, 181, 21));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font3.setPointSize(10);
        key_edit->setFont(font3);
        setKey_label = new QLabel(SetRoomDialog);
        setKey_label->setObjectName(QStringLiteral("setKey_label"));
        setKey_label->setGeometry(QRect(30, 170, 91, 21));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font4.setPointSize(12);
        setKey_label->setFont(font4);
        setKey_label->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label = new QLabel(SetRoomDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 400, 300));
        label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Background/setRoom.jpg);"));
        label->raise();
        layoutWidget->raise();
        roomname_edit->raise();
        roomname_label->raise();
        type_checkBox->raise();
        key_edit->raise();
        setKey_label->raise();

        retranslateUi(SetRoomDialog);
        QObject::connect(okButton, SIGNAL(clicked()), SetRoomDialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), SetRoomDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetRoomDialog);
    } // setupUi

    void retranslateUi(QDialog *SetRoomDialog)
    {
        SetRoomDialog->setWindowTitle(QApplication::translate("SetRoomDialog", "\350\256\276\347\275\256\346\210\277\351\227\264\344\277\241\346\201\257", Q_NULLPTR));
        okButton->setText(QApplication::translate("SetRoomDialog", "OK", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("SetRoomDialog", "Cancel", Q_NULLPTR));
        roomname_label->setText(QApplication::translate("SetRoomDialog", "\346\210\277\351\227\264\345\220\215\357\274\232", Q_NULLPTR));
        type_checkBox->setText(QApplication::translate("SetRoomDialog", "\350\256\276\344\270\272\347\247\201\344\272\272", Q_NULLPTR));
        setKey_label->setText(QApplication::translate("SetRoomDialog", "\350\256\276\347\275\256\345\257\206\347\240\201\357\274\232", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SetRoomDialog: public Ui_SetRoomDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CREATEROOM_H
