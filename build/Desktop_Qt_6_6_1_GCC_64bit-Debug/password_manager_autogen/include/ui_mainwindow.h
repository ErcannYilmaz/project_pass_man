/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *frame_add_new;
    QTextEdit *text_edit_website;
    QTextEdit *text_edit_password;
    QTextEdit *text_edit_username;
    QPushButton *add_button;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QScrollArea *scroll_area;
    QWidget *scrollAreaWidgetContents;
    QFrame *frame;
    QPushButton *sign_out_button;
    QPushButton *change_mpassword_button;
    QPushButton *refresh_button;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(600, 700);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(600, 700));
        MainWindow->setMaximumSize(QSize(600, 700));
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("emblem-readonly")));
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);"));
        MainWindow->setTabShape(QTabWidget::Rounded);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        frame_add_new = new QFrame(centralwidget);
        frame_add_new->setObjectName("frame_add_new");
        frame_add_new->setGeometry(QRect(30, 20, 450, 180));
        frame_add_new->setStyleSheet(QString::fromUtf8("background-color: rgb(57, 62, 70);\n"
"border-radius: 10px;"));
        frame_add_new->setFrameShape(QFrame::StyledPanel);
        frame_add_new->setFrameShadow(QFrame::Raised);
        text_edit_website = new QTextEdit(frame_add_new);
        text_edit_website->setObjectName("text_edit_website");
        text_edit_website->setGeometry(QRect(110, 50, 310, 30));
        text_edit_website->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
"color: white;\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        text_edit_password = new QTextEdit(frame_add_new);
        text_edit_password->setObjectName("text_edit_password");
        text_edit_password->setGeometry(QRect(110, 130, 200, 30));
        text_edit_password->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
"color: white;\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        text_edit_username = new QTextEdit(frame_add_new);
        text_edit_username->setObjectName("text_edit_username");
        text_edit_username->setGeometry(QRect(110, 90, 310, 30));
        text_edit_username->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
"color: white;\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        add_button = new QPushButton(frame_add_new);
        add_button->setObjectName("add_button");
        add_button->setGeometry(QRect(320, 130, 100, 30));
        add_button->setCursor(QCursor(Qt::PointingHandCursor));
        add_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(34, 40, 49);\n"
"	color: white;\n"
"	border: 2px solid rgb(150, 150, 150);\n"
"}\n"
"QPushButton:hover:!pressed {\n"
"   background-color: rgb(150, 150, 150);\n"
"}"));
        label = new QLabel(frame_add_new);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 50, 70, 30));
        label->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(frame_add_new);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 90, 70, 30));
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(frame_add_new);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 130, 70, 30));
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(frame_add_new);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(135, 10, 200, 30));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_4->setAlignment(Qt::AlignCenter);
        scroll_area = new QScrollArea(centralwidget);
        scroll_area->setObjectName("scroll_area");
        scroll_area->setGeometry(QRect(30, 220, 540, 440));
        scroll_area->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        scroll_area->setStyleSheet(QString::fromUtf8("background-color: rgb(57, 62, 70);\n"
"border-radius: 10px;"));
        scroll_area->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 540, 440));
        scroll_area->setWidget(scrollAreaWidgetContents);
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(500, 20, 70, 180));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(57, 62, 70);\n"
"border-radius: 10px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        sign_out_button = new QPushButton(frame);
        sign_out_button->setObjectName("sign_out_button");
        sign_out_button->setGeometry(QRect(20, 125, 30, 30));
        sign_out_button->setCursor(QCursor(Qt::PointingHandCursor));
        sign_out_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(34, 40, 49);\n"
"	border: 2px solid rgb(150, 150, 150);\n"
"}\n"
"QPushButton:hover:!pressed {\n"
"   background-color: rgb(150, 150, 150);\n"
"}"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/assets/icons/log-out.svg"), QSize(), QIcon::Normal, QIcon::Off);
        sign_out_button->setIcon(icon1);
        sign_out_button->setIconSize(QSize(22, 22));
        change_mpassword_button = new QPushButton(frame);
        change_mpassword_button->setObjectName("change_mpassword_button");
        change_mpassword_button->setGeometry(QRect(20, 75, 30, 30));
        change_mpassword_button->setCursor(QCursor(Qt::PointingHandCursor));
        change_mpassword_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(34, 40, 49);\n"
"	color: white;\n"
"	border: 2px solid rgb(150, 150, 150);\n"
"}\n"
"QPushButton:hover:!pressed {\n"
"   background-color: rgb(150, 150, 150);\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/assets/icons/account.svg"), QSize(), QIcon::Normal, QIcon::Off);
        change_mpassword_button->setIcon(icon2);
        change_mpassword_button->setIconSize(QSize(22, 22));
        refresh_button = new QPushButton(frame);
        refresh_button->setObjectName("refresh_button");
        refresh_button->setGeometry(QRect(20, 25, 30, 30));
        refresh_button->setCursor(QCursor(Qt::PointingHandCursor));
        refresh_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(34, 40, 49);\n"
"	color: white;\n"
"	border: 2px solid rgb(150, 150, 150);\n"
"}\n"
"QPushButton:hover:!pressed {\n"
"   background-color: rgb(150, 150, 150);\n"
"}"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/assets/icons/refresh.svg"), QSize(), QIcon::Normal, QIcon::Off);
        refresh_button->setIcon(icon3);
        refresh_button->setIconSize(QSize(22, 22));
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
        add_button->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Website:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "New Password Entry", nullptr));
        sign_out_button->setText(QString());
        change_mpassword_button->setText(QString());
        refresh_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
