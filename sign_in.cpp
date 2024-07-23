#include "sign_in.h"
#include "ui_sign_in.h"

sign_in::sign_in(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sign_in)
{
    ui->setupUi(this);
}

sign_in::~sign_in()
{
    delete ui;
}

// Function to check if the given username exists in the database
bool sign_in::is_user_exists(const QString &username, QSqlDatabase db)
{
    // Check if the username is empty
    if (username.isEmpty())
    {
        qDebug() << "Error: Username is empty.";
        return false;
    }

    if (!db.open())
    {
        qDebug() << "Error: Failed to open database.";
        return false;
    }

    // Check if the username exists in the database
    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM users WHERE username = :username");
    query.bindValue(":username", username);
    query.exec(); // Execute the query
    query.next(); // Move to the first (and only) row
    int count = query.value(0).toInt();
    if (count == 0)
    {
        qDebug() << "No user found with username:" << username;
        db.close();
        return false;
    }

    // Close the database connection
    db.close();

    return true; // Return true if the username is valid
}

// Function to compare the entered password with the hashed password from the database
bool sign_in::compare_password(const QString &username, const QString &entered_password, QSqlDatabase db)
{
    if (!db.open())
    {
        qDebug() << "Error: Failed to open database.";
        return false;
    }

    // Query to retrieve the hashed password and salt from the database for the given username
    QSqlQuery query(db);
    query.prepare("SELECT master_password, salt FROM users WHERE username = :username");
    query.bindValue(":username", username);

    if (!query.exec())
    {
        qDebug() << "Error executing query:" << query.lastError().text();
        db.close();
        return false;
    }

    if (query.next())
    {
        QString hashed_password = query.value(0).toString();
        QString encoded_salt = query.value(1).toString();

        QByteArray encrypted_entered_password = hash_password(entered_password, encoded_salt);

        if (encrypted_entered_password == hashed_password)
        {
            // Passwords match
            db.close();
            return true;
        }
        else
        {
            // Passwords do not match
            db.close();
            return false;
        }
    }
    else
    {
        qDebug() << "An Error Occured";
        db.close();
        return false;
    }
}

void sign_in::on_sign_up_button_clicked()
{
    sign_up *sign_up_window = new sign_up();
    close();
    sign_up_window->show();
}

void sign_in::on_sign_in_button_clicked()
{
    QSqlDatabase& db = DatabaseManager::instance();
    QString username = ui->text_edit_master_username->toPlainText();
    QString password = ui->text_edit_master_password->toPlainText();

    if (!is_user_exists(username, db))
    {
        QMessageBox::information(this, "ERROR", "User Not Found.");
        return;
    }

    if (!compare_password(username, password, db))
    {
        QMessageBox::information(this, "ERROR", "Wrong Password.");
        return;
    }

    QMessageBox::information(this, "INFO", "User successfully signed in.");

    close();
    MainWindow *main_window = new MainWindow(username, password);
    main_window->show();
}

