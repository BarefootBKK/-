/********************************************************************************
** Form generated from reading UI file 'level.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEVEL_H
#define UI_LEVEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_LevelDialog
{
public:
    QPushButton *easyAI_button;
    QPushButton *middleAI_button;
    QPushButton *difficultAI_button;
    QPushButton *nightmareAI_button;
    QPushButton *normalAI_button;
    QLabel *label;

    void setupUi(QDialog *LevelDialog)
    {
        if (LevelDialog->objectName().isEmpty())
            LevelDialog->setObjectName(QStringLiteral("LevelDialog"));
        LevelDialog->resize(400, 410);
        LevelDialog->setCursor(QCursor(Qt::UpArrowCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Image/Icon/\345\233\276\346\240\207.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        LevelDialog->setWindowIcon(icon);
        LevelDialog->setStyleSheet(QStringLiteral(""));
        easyAI_button = new QPushButton(LevelDialog);
        easyAI_button->setObjectName(QStringLiteral("easyAI_button"));
        easyAI_button->setGeometry(QRect(130, 20, 155, 55));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\215\216\346\226\207\350\241\214\346\245\267"));
        font.setPointSize(14);
        easyAI_button->setFont(font);
        easyAI_button->setCursor(QCursor(Qt::PointingHandCursor));
        easyAI_button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/150.50.jpg);\n"
"color: rgb(255, 255, 255);"));
        middleAI_button = new QPushButton(LevelDialog);
        middleAI_button->setObjectName(QStringLiteral("middleAI_button"));
        middleAI_button->setGeometry(QRect(130, 180, 155, 55));
        middleAI_button->setFont(font);
        middleAI_button->setCursor(QCursor(Qt::PointingHandCursor));
        middleAI_button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/150.50.jpg);\n"
"\n"
"color: rgb(255, 255, 255);"));
        difficultAI_button = new QPushButton(LevelDialog);
        difficultAI_button->setObjectName(QStringLiteral("difficultAI_button"));
        difficultAI_button->setGeometry(QRect(130, 260, 155, 55));
        difficultAI_button->setFont(font);
        difficultAI_button->setCursor(QCursor(Qt::PointingHandCursor));
        difficultAI_button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/150.50.jpg);\n"
"\n"
"color: rgb(255, 255, 255);"));
        nightmareAI_button = new QPushButton(LevelDialog);
        nightmareAI_button->setObjectName(QStringLiteral("nightmareAI_button"));
        nightmareAI_button->setGeometry(QRect(130, 340, 155, 55));
        nightmareAI_button->setFont(font);
        nightmareAI_button->setCursor(QCursor(Qt::PointingHandCursor));
        nightmareAI_button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/150.50.jpg);\n"
"\n"
"color: rgb(255, 255, 255);"));
        normalAI_button = new QPushButton(LevelDialog);
        normalAI_button->setObjectName(QStringLiteral("normalAI_button"));
        normalAI_button->setGeometry(QRect(130, 100, 155, 55));
        normalAI_button->setFont(font);
        normalAI_button->setCursor(QCursor(Qt::PointingHandCursor));
        normalAI_button->setStyleSheet(QLatin1String("background-image: url(:/new/prefix1/Image/Button/150.50.jpg);\n"
"\n"
"color: rgb(255, 255, 255);"));
        label = new QLabel(LevelDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 400, 410));
        label->setCursor(QCursor(Qt::ArrowCursor));
        label->setStyleSheet(QString::fromUtf8("background-image: url(:/new/prefix1/Image/Background/2_\345\211\257\346\234\254.jpg);"));
        label->raise();
        easyAI_button->raise();
        middleAI_button->raise();
        difficultAI_button->raise();
        nightmareAI_button->raise();
        normalAI_button->raise();

        retranslateUi(LevelDialog);

        QMetaObject::connectSlotsByName(LevelDialog);
    } // setupUi

    void retranslateUi(QDialog *LevelDialog)
    {
        LevelDialog->setWindowTitle(QApplication::translate("LevelDialog", "\351\200\211\346\213\251\351\232\276\345\272\246", Q_NULLPTR));
        easyAI_button->setText(QApplication::translate("LevelDialog", "\347\256\200\345\215\225\344\272\272\346\234\272", Q_NULLPTR));
        middleAI_button->setText(QApplication::translate("LevelDialog", "\344\270\255\347\255\211\344\272\272\346\234\272", Q_NULLPTR));
        difficultAI_button->setText(QApplication::translate("LevelDialog", "\345\233\260\351\232\276\344\272\272\346\234\272", Q_NULLPTR));
        nightmareAI_button->setText(QApplication::translate("LevelDialog", "\345\231\251\346\242\246\344\272\272\346\234\272", Q_NULLPTR));
        normalAI_button->setText(QApplication::translate("LevelDialog", "\346\231\256\351\200\232\344\272\272\346\234\272", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LevelDialog: public Ui_LevelDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEVEL_H
