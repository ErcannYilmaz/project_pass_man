#ifndef ACCOUNT_SETTINGS_H
#define ACCOUNT_SETTINGS_H

#include "mainwindow.h"
#include <QInputDialog>

class MainWindow;

namespace Ui {
class account_settings;
}

class account_settings : public QWidget
{
    Q_OBJECT

public:
    explicit account_settings(MainWindow *main_window, const QString &user_id, QWidget *parent = nullptr);
    ~account_settings();

private slots:
    void on_cancel_button_clicked();

    void on_save_button_clicked();

    void on_delete_button_clicked();

private:
    Ui::account_settings *ui;
    QString user_id;
    MainWindow *main_window;

    bool compare_existing_master_password(const QString &entered_master_password, QSqlDatabase db);

    bool compare_new_passwords(const QString new_m_password, const QString confirm_m_password);

    bool save_master_password(const QString &user_id, const QString &password, QSqlDatabase db);

    bool decrypt_and_encrypt_passwords(const QString &old_master_password, const QString &new_master_password, QSqlDatabase db);
};

#endif // ACCOUNT_SETTINGS_H
