/********************************************************************************
** Form generated from reading UI file 'Room.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROOM_H
#define UI_ROOM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormRoom
{
public:
    QLabel *background_label;
    QPushButton *match_button;
    QPushButton *create_Button;
    QPushButton *return_Button;
    QLabel *label_2;
    QLabel *label_3;
    QTableWidget *tableWidget;

    void setupUi(QWidget *FormRoom)
    {
        if (FormRoom->objectName().isEmpty())
            FormRoom->setObjectName(QStringLiteral("FormRoom"));
        FormRoom->resize(600, 600);
        FormRoom->setCursor(QCursor(Qt::ArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Image/Icon/\345\233\276\346\240\207.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        FormRoom->setWindowIcon(icon);
        FormRoom->setStyleSheet(QStringLiteral(""));
        background_label = new QLabel(FormRoom);
        background_label->setObjectName(QStringLiteral("background_label"));
        background_label->setGeometry(QRect(0, 0, 600, 600));
        background_label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Background/Main2.jpg);"));
        match_button = new QPushButton(FormRoom);
        match_button->setObjectName(QStringLiteral("match_button"));
        match_button->setGeometry(QRect(240, 520, 105, 45));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(14);
        match_button->setFont(font);
        match_button->setCursor(QCursor(Qt::PointingHandCursor));
        match_button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/100.40.jpg);\n"
"color: rgb(250, 250, 250);"));
        create_Button = new QPushButton(FormRoom);
        create_Button->setObjectName(QStringLiteral("create_Button"));
        create_Button->setGeometry(QRect(60, 520, 105, 45));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        create_Button->setFont(font1);
        create_Button->setCursor(QCursor(Qt::PointingHandCursor));
        create_Button->setStyleSheet(QLatin1String("color: rgb(250, 250, 250);\n"
"background-image: url(:/new/prefix1/Image/Button/100.40.jpg);"));
        return_Button = new QPushButton(FormRoom);
        return_Button->setObjectName(QStringLiteral("return_Button"));
        return_Button->setGeometry(QRect(430, 520, 105, 45));
        return_Button->setFont(font);
        return_Button->setCursor(QCursor(Qt::PointingHandCursor));
        return_Button->setStyleSheet(QLatin1String("color: rgb(250, 250, 250);\n"
"background-image: url(:/new/prefix1/Image/Button/100.40.jpg);"));
        label_2 = new QLabel(FormRoom);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 39, 521, 451));
        label_2->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/19189.jpg);\n"
"background-image: url(:/new/prefix1/Image/Background/a63a3b601c8308643ad54329ed253d5c.jpg);\n"
""));
        label_3 = new QLabel(FormRoom);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 50, 141, 31));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \"\346\245\267\344\275\223\";\n"
""));
        tableWidget = new QTableWidget(FormRoom);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font2.setBold(false);
        font2.setWeight(50);
        font2.setStyleStrategy(QFont::PreferAntialias);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        __qtablewidgetitem->setFont(font2);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(60, 90, 481, 381));
        tableWidget->setStyleSheet(QStringLiteral(""));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->horizontalHeader()->setDefaultSectionSize(120);
        tableWidget->horizontalHeader()->setMinimumSectionSize(35);
        tableWidget->verticalHeader()->setDefaultSectionSize(30);
        tableWidget->verticalHeader()->setMinimumSectionSize(20);

        retranslateUi(FormRoom);

        QMetaObject::connectSlotsByName(FormRoom);
    } // setupUi

    void retranslateUi(QWidget *FormRoom)
    {
        FormRoom->setWindowTitle(QApplication::translate("FormRoom", "\344\272\224\345\255\220\346\243\213\342\200\224\346\210\277\351\227\264", Q_NULLPTR));
        background_label->setText(QString());
        match_button->setText(QApplication::translate("FormRoom", "\345\214\271\351\205\215\345\257\271\346\211\213", Q_NULLPTR));
        create_Button->setText(QApplication::translate("FormRoom", "\345\210\233\345\273\272\346\210\277\351\227\264", Q_NULLPTR));
        return_Button->setText(QApplication::translate("FormRoom", "\350\277\224\345\233\236", Q_NULLPTR));
        label_2->setText(QString());
        label_3->setText(QApplication::translate("FormRoom", "\346\210\277\351\227\264\345\210\227\350\241\250\357\274\232", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("FormRoom", "\346\210\277\351\227\264\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("FormRoom", "\346\210\277\351\227\264\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("FormRoom", "\346\210\277\351\227\264\347\261\273\345\236\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("FormRoom", "\344\272\272\346\225\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormRoom: public Ui_FormRoom {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROOM_H
