/********************************************************************************
** Form generated from reading UI file 'edit_password.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_PASSWORD_H
#define UI_EDIT_PASSWORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_edit_password
{
public:
    QFrame *frame;
    QPushButton *save_button;
    QTextEdit *text_edit_password;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QTextEdit *text_edit_username;
    QTextEdit *text_edit_website;
    QLabel *label_4;
    QTextEdit *text_edit_password_confirm;
    QLabel *label_5;
    QPushButton *cancel_button;

    void setupUi(QWidget *edit_password)
    {
        if (edit_password->objectName().isEmpty())
            edit_password->setObjectName("edit_password");
        edit_password->resize(700, 400);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(edit_password->sizePolicy().hasHeightForWidth());
        edit_password->setSizePolicy(sizePolicy);
        edit_password->setMinimumSize(QSize(700, 400));
        edit_password->setMaximumSize(QSize(700, 400));
        edit_password->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_si_sign_up {\\n    background-color: rgb(34, 40, 49);\\n}\\nQPushButton#pushButton_si_sign_up:hover:!pressed {\\n   background-color: rgb(150, 150, 150);\\n}"));
        frame = new QFrame(edit_password);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(50, 20, 600, 350));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(57, 62, 70);\n"
"border-radius: 10px;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        save_button = new QPushButton(frame);
        save_button->setObjectName("save_button");
        save_button->setGeometry(QRect(150, 280, 100, 30));
        save_button->setCursor(QCursor(Qt::PointingHandCursor));
        save_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(34, 40, 49);\n"
"}\n"
"QPushButton:hover:!pressed {\n"
"   background-color: rgb(150, 150, 150);\n"
"}"));
        text_edit_password = new QTextEdit(frame);
        text_edit_password->setObjectName("text_edit_password");
        text_edit_password->setGeometry(QRect(160, 170, 360, 30));
        text_edit_password->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
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
        text_edit_username = new QTextEdit(frame);
        text_edit_username->setObjectName("text_edit_username");
        text_edit_username->setGeometry(QRect(160, 120, 360, 30));
        text_edit_username->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        text_edit_website = new QTextEdit(frame);
        text_edit_website->setObjectName("text_edit_website");
        text_edit_website->setGeometry(QRect(160, 70, 360, 30));
        text_edit_website->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 220, 120, 30));
        label_4->setStyleSheet(QString::fromUtf8("color:rgb(238, 238, 238);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        text_edit_password_confirm = new QTextEdit(frame);
        text_edit_password_confirm->setObjectName("text_edit_password_confirm");
        text_edit_password_confirm->setGeometry(QRect(160, 220, 360, 30));
        text_edit_password_confirm->setStyleSheet(QString::fromUtf8("background-color: rgb(34, 40, 49);\n"
"padding-top: 3px;\n"
"padding-left: 3px;"));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(200, 20, 200, 30));
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
        cancel_button->setGeometry(QRect(340, 280, 100, 30));
        cancel_button->setCursor(QCursor(Qt::PointingHandCursor));
        cancel_button->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"    background-color: rgb(34, 40, 49);\n"
"}\n"
"QPushButton:hover:!pressed {\n"
"   background-color: rgb(150, 150, 150);\n"
"}"));

        retranslateUi(edit_password);

        QMetaObject::connectSlotsByName(edit_password);
    } // setupUi

    void retranslateUi(QWidget *edit_password)
    {
        edit_password->setWindowTitle(QCoreApplication::translate("edit_password", "Form", nullptr));
        save_button->setText(QCoreApplication::translate("edit_password", "Save", nullptr));
        label->setText(QCoreApplication::translate("edit_password", "Website:", nullptr));
        label_3->setText(QCoreApplication::translate("edit_password", "Password:", nullptr));
        label_2->setText(QCoreApplication::translate("edit_password", "Username:", nullptr));
        label_4->setText(QCoreApplication::translate("edit_password", "Confirm Password:", nullptr));
        label_5->setText(QCoreApplication::translate("edit_password", "EDIT PASSWORD", nullptr));
        cancel_button->setText(QCoreApplication::translate("edit_password", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class edit_password: public Ui_edit_password {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_PASSWORD_H
