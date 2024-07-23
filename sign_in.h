#ifndef SIGN_IN_H
#define SIGN_IN_H

#include "sign_up.h"
#include "mainwindow.h"
#include "database.h"
#include "cryptography.h"

namespace Ui {
class sign_in;
}

class sign_in : public QWidget
{
    Q_OBJECT

public:
    explicit sign_in(QWidget *parent = nullptr);
    ~sign_in();

private slots:
    void on_sign_in_button_clicked();

    void on_sign_up_button_clicked();

private:
    Ui::sign_in *ui;

    bool is_user_exists(const QString &username, QSqlDatabase db);

    bool compare_password(const QString &username, const QString &entered_password, QSqlDatabase db);
};

#endif // SIGN_IN_H
