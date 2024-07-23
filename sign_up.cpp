#include "sign_up.h"
#include "ui_sign_up.h"

// Constructor and Destructor
sign_up::sign_up(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::sign_up)
{
    ui->setupUi(this);
}

sign_up::~sign_up()
{
    delete ui;
}

// Function to check if the given username is valid
bool sign_up::is_username_valid(const QString &username, QSqlDatabase db)
{
    // Check if the username is empty
    if (username.isEmpty())
    {
        qDebug() << "Error: Username is empty.";
        return false;
    }

    // Ensure the database is open
    if (!db.isOpen() && !db.open())
    {
        qDebug() << "Error: Failed to open database." << db.lastError().text();
        return false;
    }

    // Prepare the query to check if the username already exists
    QSqlQuery query(db);
    query.prepare("SELECT COUNT(*) FROM users WHERE username = :username");
    query.bindValue(":username", username);

    // Execute the query
    if (!query.exec())
    {
        qDebug() << "Error: Failed to execute query." << query.lastError().text();
        return false;
    }

    // Move to the first record
    query.next();
    int count = query.value(0).toInt();

    // Check if the username already exists
    if (count > 0)
    {
        qDebug() << "Error: Username already exists.";
        return false;
    }

    return true; // Return true if the username is valid
}

// Function to check if the passwords in the text edits match
bool sign_up::check_passwords_matches(const QString &password, const QString &confirm_password)
{
    // Compare the passwords
    return password == confirm_password;
}

// Function to save master password securely in the database
bool sign_up::save_master_password(const QString &username, const QString &password, QSqlDatabase db)
{
    // Encrypt password and retrieve salt and encrypted password
    auto [encrypted_password, salt] = hash_password(password);

    // Ensure the database is open
    if (!db.isOpen() && !db.open())
    {
        qDebug() << "Error: Failed to open database." << db.lastError().text();
        return false;
    }

    // Prepare the query to insert username, hashed password, and salt into the table
    QSqlQuery query(db);
    query.prepare("INSERT INTO users (username, master_password, salt) VALUES (:username, :master_password, :salt)");
    query.bindValue(":username", username);
    query.bindValue(":master_password", encrypted_password);
    query.bindValue(":salt", salt);

    // Execute the query
    if (!query.exec())
    {
        qDebug() << "Error: Failed to insert values into table." << query.lastError().text();
        return false;
    }

    return true; // Return true if insertion was successful
}

// Slot for the sign up button click event
void sign_up::on_sign_up_button_clicked()
{
    // Get the database instance
    QSqlDatabase& db = DatabaseManager::instance();

    // Get the username and passwords from the UI
    QString username = ui->textEdit_master_su_username->toPlainText();
    QString password = ui->textEdit_master_su_pass->toPlainText();
    QString confirm_password = ui->textEdit_master_su_pass_conf->toPlainText();

    // Validate the username
    if (!is_username_valid(username, db))
    {
        QMessageBox::information(this, "ERROR", "Invalid username.");
        return;
    }

    // Check if the passwords match
    if (!check_passwords_matches(password, confirm_password))
    {
        QMessageBox::information(this, "ERROR", "Passwords do not match.");
        return;
    }

    // Save the master password
    if (!save_master_password(username, password, db))
    {
        QMessageBox::information(this, "ERROR", "Failed to save master password.");
        return;
    }

    QMessageBox::information(this, "INFO", "User successfully signed up!");
    sign_in *Sign_in = new sign_in();
    close();
    Sign_in->show();
}

void sign_up::on_cancel_button_clicked()
{
    sign_in *Sign_in = new sign_in();
    close();
    Sign_in->show();
}

