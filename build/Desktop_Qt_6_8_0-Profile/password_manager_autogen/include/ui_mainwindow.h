/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame;
    QTextEdit *textEdit_website;
    QTextEdit *textEdit_password;
    QTextEdit *textEdit_username;
    QPushButton *pushButton_add;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *frame_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 700);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(600, 700));
        MainWindow->setMaximumSize(QSize(600, 700));
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(30, 20, 540, 180));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(57, 62, 70);\n"
"border-radius: 10px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        textEdit_website = new QTextEdit(frame);
        textEdit_website->setObjectName("textEdit_website");
        textEdit_website->setGeometry(QRect(130, 50, 360, 30));
        textEdit_website->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        textEdit_password = new QTextEdit(frame);
        textEdit_password->setObjectName("textEdit_password");
        textEdit_password->setGeometry(QRect(130, 130, 250, 30));
        textEdit_password->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        textEdit_username = new QTextEdit(frame);
        textEdit_username->setObjectName("textEdit_username");
        textEdit_username->setGeometry(QRect(130, 90, 360, 30));
        textEdit_username->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        pushButton_add = new QPushButton(frame);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setGeometry(QRect(390, 130, 100, 30));
        pushButton_add->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_add {\n"
"    background-color: rgb(34, 40, 49);\n"
"}\n"
"QPushButton#pushButton_add:hover:!pressed {\n"
"   background-color: rgb(150, 150, 150);\n"
"}\n"
""));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 50, 70, 30));
        label->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 90, 70, 30));
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 130, 70, 30));
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(170, 10, 200, 30));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_4->setAlignment(Qt::AlignCenter);
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(30, 230, 540, 440));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(57, 62, 70);\n"
"border-radius: 10px;"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_add->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Website:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "New Password Entry", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
