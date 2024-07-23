#ifndef SIGN_UP_H
#define SIGN_UP_H

#include "sign_in.h"
#include "database.h"
#include "cryptography.h"

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>

namespace Ui {
class sign_up;
}

class sign_up : public QWidget
{
    Q_OBJECT

public:
    explicit sign_up(QWidget *parent = nullptr);
    ~sign_up();

private slots:
    void on_sign_up_button_clicked();

    void on_cancel_button_clicked();

private:
    Ui::sign_up *ui;

    bool is_username_valid(const QString &username, QSqlDatabase db);

    bool check_passwords_matches(const QString &password, const QString &confirm_password);

    bool save_master_password(const QString &username, const QString &password, QSqlDatabase db);
};

#endif // SIGN_UP_H
