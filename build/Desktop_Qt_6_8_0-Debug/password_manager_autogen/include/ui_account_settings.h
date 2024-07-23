/********************************************************************************
** Form generated from reading UI file 'account_settings.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNT_SETTINGS_H
#define UI_ACCOUNT_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_account_settings
{
public:
    QFrame *frame;
    QPushButton *save_button;
    QTextEdit *textEdit_confirm_password;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QTextEdit *textEdit_new_password;
    QTextEdit *textEdit_old_password;
    QLabel *label_5;
    QPushButton *cancel_button;
    QPushButton *delete_button;

    void setupUi(QWidget *account_settings)
    {
        if (account_settings->objectName().isEmpty())
            account_settings->setObjectName("account_settings");
        account_settings->resize(700, 340);
        frame = new QFrame(account_settings);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(50, 20, 600, 290));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(57, 62, 70);\n"
"border-radius: 10px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        save_button = new QPushButton(frame);
        save_button->setObjectName("save_button");
        save_button->setGeometry(QRect(120, 220, 100, 30));
        save_button->setCursor(QCursor(Qt::PointingHandCursor));
        save_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(34, 40, 49);\n"
"}\n"
"QPushButton:hover:!pressed {\n"
"   background-color: rgb(150, 150, 150);\n"
"}"));
        textEdit_confirm_password = new QTextEdit(frame);
        textEdit_confirm_password->setObjectName("textEdit_confirm_password");
        textEdit_confirm_password->setGeometry(QRect(160, 170, 360, 30));
        textEdit_confirm_password->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 70, 120, 30));
        label->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 170, 120, 30));
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 120, 120, 30));
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        textEdit_new_password = new QTextEdit(frame);
        textEdit_new_password->setObjectName("textEdit_new_password");
        textEdit_new_password->setGeometry(QRect(160, 120, 360, 30));
        textEdit_new_password->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        textEdit_old_password = new QTextEdit(frame);
        textEdit_old_password->setObjectName("textEdit_old_password");
        textEdit_old_password->setGeometry(QRect(160, 70, 360, 30));
        textEdit_old_password->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(170, 20, 260, 30));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_5->setAlignment(Qt::AlignCenter);
        cancel_button = new QPushButton(frame);
        cancel_button->setObjectName("cancel_button");
        cancel_button->setGeometry(QRect(260, 220, 100, 30));
        cancel_button->setCursor(QCursor(Qt::PointingHandCursor));
        cancel_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(34, 40, 49);\n"
"}\n"
"QPushButton:hover:!pressed {\n"
"   background-color: rgb(150, 150, 150);\n"
"}"));
        delete_button = new QPushButton(frame);
        delete_button->setObjectName("delete_button");
        delete_button->setGeometry(QRect(400, 220, 100, 30));
        delete_button->setCursor(QCursor(Qt::PointingHandCursor));
        delete_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(136, 8, 8);\n"
"}\n"
"QPushButton:hover:!pressed {\n"
"   background-color: rgb(255, 0, 0);\n"
"}"));

        retranslateUi(account_settings);

        QMetaObject::connectSlotsByName(account_settings);
    } // setupUi

    void retranslateUi(QWidget *account_settings)
    {
        account_settings->setWindowTitle(QCoreApplication::translate("account_settings", "Form", nullptr));
        save_button->setText(QCoreApplication::translate("account_settings", "Save", nullptr));
        label->setText(QCoreApplication::translate("account_settings", "Old Password", nullptr));
        label_3->setText(QCoreApplication::translate("account_settings", "Confirm Password", nullptr));
        label_2->setText(QCoreApplication::translate("account_settings", "New Password", nullptr));
        label_5->setText(QCoreApplication::translate("account_settings", "CHANGE MASTER PASSWORD", nullptr));
        cancel_button->setText(QCoreApplication::translate("account_settings", "Cancel", nullptr));
        delete_button->setText(QCoreApplication::translate("account_settings", "Delete Account", nullptr));
    } // retranslateUi

};

namespace Ui {
    class account_settings: public Ui_account_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNT_SETTINGS_H
