#ifndef EDIT_PASSWORD_H
#define EDIT_PASSWORD_H

#include "mainwindow.h"

namespace Ui {
class edit_password;
}

class edit_password : public QWidget
{
    Q_OBJECT

public:
    explicit edit_password(const QString &password_id, const QString &m_username, const QString &m_password, const QString &website, const QString &username, const QString &password,QWidget *parent = nullptr);
    ~edit_password();

private slots:
    void on_cancel_button_clicked();

    void on_save_button_clicked();

private:
    Ui::edit_password *ui;
    QString m_username;
    QString m_password;
    QString website;
    QString username;
    QString password;
    QString password_id;

    void set_placeholders();

    bool check_passwords_matches(const QString &password, const QString &confirm_password);

};

#endif // EDIT_PASSWORD_H
