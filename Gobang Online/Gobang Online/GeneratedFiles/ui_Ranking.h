/********************************************************************************
** Form generated from reading UI file 'Ranking.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANKING_H
#define UI_RANKING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormRanking
{
public:
    QPushButton *return_Button;
    QLabel *label;
    QTextEdit *textEdit;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QWidget *FormRanking)
    {
        if (FormRanking->objectName().isEmpty())
            FormRanking->setObjectName(QStringLiteral("FormRanking"));
        FormRanking->resize(600, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Image/Icon/\345\233\276\346\240\207.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        FormRanking->setWindowIcon(icon);
        return_Button = new QPushButton(FormRanking);
        return_Button->setObjectName(QStringLiteral("return_Button"));
        return_Button->setGeometry(QRect(260, 520, 105, 45));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(18);
        return_Button->setFont(font);
        return_Button->setCursor(QCursor(Qt::PointingHandCursor));
        return_Button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/100.40.jpg);\n"
"color: rgb(250, 250, 250);"));
        label = new QLabel(FormRanking);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 600, 600));
        label->setStyleSheet(QStringLiteral("background-image: url(:/new/prefix1/Image/Background/Main2.jpg);"));
        textEdit = new QTextEdit(FormRanking);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(110, 130, 401, 361));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font1.setPointSize(22);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(9);
        textEdit->setFont(font1);
        textEdit->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/Image/Background/Main2.jpg);\n"
"font: 75 22pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"color: rgb(255, 255, 255);"));
        textEdit->setReadOnly(true);
        label_2 = new QLabel(FormRanking);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(110, 0, 401, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font2.setPointSize(22);
        label_2->setFont(font2);
        label_2->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"color: qlineargradient(spread:reflect, x1:0.418, y1:0.459818, x2:1, y2:0.023, stop:0.502488 rgba(189, 214, 255, 249), stop:1 rgba(255, 255, 255, 255));"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(FormRanking);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(110, 75, 401, 41));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font3.setPointSize(16);
        font3.setBold(true);
        font3.setWeight(75);
        label_3->setFont(font3);
        label_3->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        label->raise();
        return_Button->raise();
        textEdit->raise();
        label_2->raise();
        label_3->raise();

        retranslateUi(FormRanking);

        QMetaObject::connectSlotsByName(FormRanking);
    } // setupUi

    void retranslateUi(QWidget *FormRanking)
    {
        FormRanking->setWindowTitle(QApplication::translate("FormRanking", "\346\216\222\350\241\214\346\246\234", Q_NULLPTR));
        return_Button->setText(QApplication::translate("FormRanking", "\350\277\224\345\233\236", Q_NULLPTR));
        label->setText(QString());
        textEdit->setHtml(QApplication::translate("FormRanking", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'\345\276\256\350\275\257\351\233\205\351\273\221'; font-size:22pt; font-weight:72; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:20pt; font-weight:400;\">HyYang	73%		450</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:20pt; font-weight:400;\">HaoHuiF	65%		330</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:20pt; font-weight:400;\">JinMingJ"
                        "	64%		315</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:20pt; font-weight:400;\">HeJW		100%		100</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:20pt; font-weight:400;\">HeBK		50%		100</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:20pt; font-weight:400;\">H2333	0%		0</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun'; font-size:20pt; font-weight:400;\">8989		0%		0</span></p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("FormRanking", "\346\216\222\350\241\214\346\246\234", Q_NULLPTR));
        label_3->setText(QApplication::translate("FormRanking", "\346\230\265\347\247\260              \350\203\234\347\216\207             \345\210\206\346\225\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormRanking: public Ui_FormRanking {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANKING_H
