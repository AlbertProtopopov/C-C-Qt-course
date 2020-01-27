/********************************************************************************
** Form generated from reading UI file 'Widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *forwardPushButton;
    QPushButton *leftPushButton;
    QPushButton *rightPushButton;
    QPushButton *backPushButton;
    QPushButton *spinLeftPushButton;
    QPushButton *spinRightPushButton;
    QLabel *label;
    QLabel *label_2;
    QTextEdit *connectionTextEdit;
    QTextBrowser *textBrowser;
    QTextEdit *distance_textEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(538, 510);
        Widget->setMaximumSize(QSize(538, 510));
        Widget->setMouseTracking(false);
        Widget->setLayoutDirection(Qt::LeftToRight);
        Widget->setAutoFillBackground(false);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(64, 191, 145);"));
        forwardPushButton = new QPushButton(Widget);
        forwardPushButton->setObjectName(QString::fromUtf8("forwardPushButton"));
        forwardPushButton->setGeometry(QRect(230, 280, 80, 71));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(forwardPushButton->sizePolicy().hasHeightForWidth());
        forwardPushButton->setSizePolicy(sizePolicy);
        forwardPushButton->setLayoutDirection(Qt::LeftToRight);
        forwardPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));
        leftPushButton = new QPushButton(Widget);
        leftPushButton->setObjectName(QString::fromUtf8("leftPushButton"));
        leftPushButton->setGeometry(QRect(149, 350, 81, 71));
        sizePolicy.setHeightForWidth(leftPushButton->sizePolicy().hasHeightForWidth());
        leftPushButton->setSizePolicy(sizePolicy);
        leftPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));
        rightPushButton = new QPushButton(Widget);
        rightPushButton->setObjectName(QString::fromUtf8("rightPushButton"));
        rightPushButton->setGeometry(QRect(310, 350, 81, 71));
        sizePolicy.setHeightForWidth(rightPushButton->sizePolicy().hasHeightForWidth());
        rightPushButton->setSizePolicy(sizePolicy);
        rightPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));
        backPushButton = new QPushButton(Widget);
        backPushButton->setObjectName(QString::fromUtf8("backPushButton"));
        backPushButton->setEnabled(true);
        backPushButton->setGeometry(QRect(230, 420, 80, 71));
        sizePolicy.setHeightForWidth(backPushButton->sizePolicy().hasHeightForWidth());
        backPushButton->setSizePolicy(sizePolicy);
        backPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));
        backPushButton->setAutoDefault(false);
        spinLeftPushButton = new QPushButton(Widget);
        spinLeftPushButton->setObjectName(QString::fromUtf8("spinLeftPushButton"));
        spinLeftPushButton->setGeometry(QRect(30, 350, 81, 71));
        spinLeftPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(78, 154, 6);"));
        spinRightPushButton = new QPushButton(Widget);
        spinRightPushButton->setObjectName(QString::fromUtf8("spinRightPushButton"));
        spinRightPushButton->setGeometry(QRect(430, 350, 81, 71));
        sizePolicy.setHeightForWidth(spinRightPushButton->sizePolicy().hasHeightForWidth());
        spinRightPushButton->setSizePolicy(sizePolicy);
        spinRightPushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(64, 139, 191);\n"
"background-color: rgb(78, 154, 6);"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 260, 67, 31));
        QFont font;
        font.setPointSize(13);
        label->setFont(font);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 10, 91, 21));
        label_2->setFont(font);
        connectionTextEdit = new QTextEdit(Widget);
        connectionTextEdit->setObjectName(QString::fromUtf8("connectionTextEdit"));
        connectionTextEdit->setGeometry(QRect(110, 10, 131, 31));
        connectionTextEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(211, 215, 207);\n"
"background-color: rgb(255, 255, 255);"));
        textBrowser = new QTextBrowser(Widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(110, 50, 321, 192));
        textBrowser->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 52, 54);"));
        distance_textEdit = new QTextEdit(Widget);
        distance_textEdit->setObjectName(QString::fromUtf8("distance_textEdit"));
        distance_textEdit->setGeometry(QRect(120, 260, 104, 31));
        distance_textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        forwardPushButton->raise();
        leftPushButton->raise();
        rightPushButton->raise();
        backPushButton->raise();
        spinRightPushButton->raise();
        spinLeftPushButton->raise();
        label->raise();
        label_2->raise();
        connectionTextEdit->raise();
        textBrowser->raise();
        distance_textEdit->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        forwardPushButton->setText(QApplication::translate("Widget", "forward", nullptr));
#ifndef QT_NO_SHORTCUT
        forwardPushButton->setShortcut(QApplication::translate("Widget", "Up", nullptr));
#endif // QT_NO_SHORTCUT
        leftPushButton->setText(QApplication::translate("Widget", "left", nullptr));
#ifndef QT_NO_SHORTCUT
        leftPushButton->setShortcut(QApplication::translate("Widget", "Left", nullptr));
#endif // QT_NO_SHORTCUT
        rightPushButton->setText(QApplication::translate("Widget", "right", nullptr));
#ifndef QT_NO_SHORTCUT
        rightPushButton->setShortcut(QApplication::translate("Widget", "Right", nullptr));
#endif // QT_NO_SHORTCUT
        backPushButton->setText(QApplication::translate("Widget", "back", nullptr));
#ifndef QT_NO_SHORTCUT
        backPushButton->setShortcut(QApplication::translate("Widget", "Down", nullptr));
#endif // QT_NO_SHORTCUT
        spinLeftPushButton->setText(QApplication::translate("Widget", "right spin", nullptr));
#ifndef QT_NO_SHORTCUT
        spinLeftPushButton->setShortcut(QApplication::translate("Widget", "Shift+Left", nullptr));
#endif // QT_NO_SHORTCUT
        spinRightPushButton->setText(QApplication::translate("Widget", "left spin", nullptr));
#ifndef QT_NO_SHORTCUT
        spinRightPushButton->setShortcut(QApplication::translate("Widget", "Shift+Right", nullptr));
#endif // QT_NO_SHORTCUT
        label->setText(QApplication::translate("Widget", "distance", nullptr));
        label_2->setText(QApplication::translate("Widget", "connection", nullptr));
        textBrowser->setHtml(QApplication::translate("Widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0"
                        "px;\"><br /></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">No Video</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
