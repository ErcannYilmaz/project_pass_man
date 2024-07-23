#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QScrollArea>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QVBoxLayout>
#include <string>
#include <QMessageBox>

#include "sign_in.h"
#include "account_settings.h"
#include "edit_password.h"
#include "database.h"
#include "cryptography.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString &username, const QString &password, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_add_button_clicked();

    void on_sign_out_button_clicked();

    void on_refresh_button_clicked();

    void on_change_mpassword_button_clicked();

private:
    Ui::MainWindow *ui;
    QString m_username;
    QString m_password;

    void on_delete_button_clicked(const QString &password_id);

    void on_edit_button_clicked(const QString &password_id, const QString &m_username, const QString &m_password, const QString &website, const QString &username, const QString &password);

    void on_show_button_clicked(const QString m_password, const QString iv, const QString salt, const QString &username, const QString &password, QLabel *username_label, QLabel *password_label, QPushButton *show_button);

    bool list_stored_passwords(const QString &username, QSqlDatabase db, QScrollArea *scroll_area);

    bool delete_password(const QString &password_id, QSqlDatabase db);

    bool add_new_password(const QString &m_username, const QString &m_password, const QString &website, const QString &username, const QString &password, QSqlDatabase db);
};
#endif // MAINWINDOW_H
