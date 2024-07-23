/********************************************************************************
** Form generated from reading UI file 'sign_up.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGN_UP_H
#define UI_SIGN_UP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_sign_up
{
public:
    QFrame *frame;
    QTextEdit *textEdit_master_su_pass;
    QTextEdit *textEdit_master_su_username;
    QPushButton *pushButton_su_sign_up;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_2;
    QTextEdit *textEdit_master_su_pass_conf;
    QLabel *label_5;

    void setupUi(QWidget *sign_up)
    {
        if (sign_up->objectName().isEmpty())
            sign_up->setObjectName("sign_up");
        sign_up->resize(700, 330);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Ignored, QSizePolicy::Policy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sign_up->sizePolicy().hasHeightForWidth());
        sign_up->setSizePolicy(sizePolicy);
        sign_up->setMinimumSize(QSize(700, 330));
        sign_up->setMaximumSize(QSize(700, 330));
        sign_up->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);"));
        frame = new QFrame(sign_up);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(80, 40, 540, 250));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(57, 62, 70);\n"
"border-radius: 10px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        textEdit_master_su_pass = new QTextEdit(frame);
        textEdit_master_su_pass->setObjectName("textEdit_master_su_pass");
        textEdit_master_su_pass->setGeometry(QRect(150, 100, 360, 30));
        textEdit_master_su_pass->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        textEdit_master_su_username = new QTextEdit(frame);
        textEdit_master_su_username->setObjectName("textEdit_master_su_username");
        textEdit_master_su_username->setGeometry(QRect(150, 50, 360, 30));
        textEdit_master_su_username->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        pushButton_su_sign_up = new QPushButton(frame);
        pushButton_su_sign_up->setObjectName("pushButton_su_sign_up");
        pushButton_su_sign_up->setGeometry(QRect(230, 200, 100, 30));
        pushButton_su_sign_up->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_su_sign_up {\n"
"    background-color: rgb(34, 40, 49);\n"
"}\n"
"QPushButton#pushButton_su_sign_up:hover:!pressed {\n"
"   background-color: rgb(150, 150, 150);\n"
"}\n"
""));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(230, 10, 100, 30));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_4->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 100, 120, 30));
        label_3->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 50, 120, 30));
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;\n"
""));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        textEdit_master_su_pass_conf = new QTextEdit(frame);
        textEdit_master_su_pass_conf->setObjectName("textEdit_master_su_pass_conf");
        textEdit_master_su_pass_conf->setGeometry(QRect(150, 150, 360, 30));
        textEdit_master_su_pass_conf->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 150, 120, 30));
        label_5->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        retranslateUi(sign_up);

        QMetaObject::connectSlotsByName(sign_up);
    } // setupUi

    void retranslateUi(QWidget *sign_up)
    {
        sign_up->setWindowTitle(QCoreApplication::translate("sign_up", "Form", nullptr));
        pushButton_su_sign_up->setText(QCoreApplication::translate("sign_up", "SIGN UP", nullptr));
        label_4->setText(QCoreApplication::translate("sign_up", "SIGN UP", nullptr));
        label_3->setText(QCoreApplication::translate("sign_up", "Password:", nullptr));
        label_2->setText(QCoreApplication::translate("sign_up", "Username:", nullptr));
        label_5->setText(QCoreApplication::translate("sign_up", "Confirm Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class sign_up: public Ui_sign_up {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGN_UP_H
