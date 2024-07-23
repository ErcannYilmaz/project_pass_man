/********************************************************************************
** Form generated from reading UI file 'sign_in.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_IN_H
#define UI_SIGN_IN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sign_in
{
public:
    QFrame *frame;
    QTextEdit *text_edit_master_password;
    QTextEdit *text_edit_master_username;
    QPushButton *sign_in_button;
    QLabel *label_4;
    QPushButton *sign_up_button;
    QLabel *label_3;
    QLabel *label_2;

    void setupUi(QWidget *sign_in)
    {
        if (sign_in->objectName().isEmpty())
            sign_in->setObjectName("sign_in");
        sign_in->resize(700, 300);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sign_in->sizePolicy().hasHeightForWidth());
        sign_in->setSizePolicy(sizePolicy);
        sign_in->setMinimumSize(QSize(700, 300));
        sign_in->setMaximumSize(QSize(700, 300));
        sign_in->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);"));
        frame = new QFrame(sign_in);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(80, 50, 540, 200));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(57, 62, 70);\n"
"border-radius: 10px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        text_edit_master_password = new QTextEdit(frame);
        text_edit_master_password->setObjectName("text_edit_master_password");
        text_edit_master_password->setGeometry(QRect(150, 100, 360, 30));
        text_edit_master_password->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
"color: white;\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        text_edit_master_username = new QTextEdit(frame);
        text_edit_master_username->setObjectName("text_edit_master_username");
        text_edit_master_username->setGeometry(QRect(150, 50, 360, 30));
        text_edit_master_username->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
"color: white;\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        sign_in_button = new QPushButton(frame);
        sign_in_button->setObjectName("sign_in_button");
        sign_in_button->setGeometry(QRect(140, 150, 100, 30));
        sign_in_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(34, 40, 49);\n"
"	color: white;\n"
"	border: 2px solid rgb(150, 150, 150);\n"
"}\n"
"QPushButton:hover:!pressed {\n"
"   background-color: rgb(150, 150, 150);\n"
"}"));
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
        sign_up_button = new QPushButton(frame);
        sign_up_button->setObjectName("sign_up_button");
        sign_up_button->setGeometry(QRect(300, 150, 100, 30));
        sign_up_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(34, 40, 49);\n"
"	color: white;\n"
"	border: 2px solid rgb(150, 150, 150);\n"
"}\n"
"QPushButton:hover:!pressed {\n"
"   background-color: rgb(150, 150, 150);\n"
"}"));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 100, 70, 30));
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 50, 70, 30));
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(sign_in);

        QMetaObject::connectSlotsByName(sign_in);
    } // setupUi

    void retranslateUi(QWidget *sign_in)
    {
        sign_in->setWindowTitle(QCoreApplication::translate("sign_in", "Form", nullptr));
        sign_in_button->setText(QCoreApplication::translate("sign_in", "SIGN IN", nullptr));
        label_4->setText(QCoreApplication::translate("sign_in", "Enter Master Password", nullptr));
        sign_up_button->setText(QCoreApplication::translate("sign_in", "SIGN UP", nullptr));
        label_3->setText(QCoreApplication::translate("sign_in", "Password:", nullptr));
        label_2->setText(QCoreApplication::translate("sign_in", "Username:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sign_in: public Ui_sign_in {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_IN_H
