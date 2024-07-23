#include "account_settings.h"
#include "ui_account_settings.h"

// Constructor for account_settings class
account_settings::account_settings(MainWindow *main_window, const QString &user_id, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::account_settings)
    , user_id(user_id)
    , main_window(main_window)
{
    ui->setupUi(this); // Set up the UI
}

// Destructor for account_settings class
account_settings::~account_settings()
{
    delete ui; // Clean up UI
}

// Function to compare the existing master passwords
bool account_settings::compare_existing_master_password(const QString &entered_master_password, QSqlDatabase db)
{
    if (!db.open()) // Open the database connection
    {
        qDebug() << "Error: Failed to open database.";
        return false;
    }

    // Query to retrieve the hashed password and salt from the database for the given user_id
    QSqlQuery query(db);
    query.prepare("SELECT master_password, salt FROM users WHERE id = :id");
    query.bindValue(":id", user_id);

    if (!query.exec()) // Execute the query
    {
        qDebug() << "Error executing query:" << query.lastError().text();
        db.close();
        return false;
    }

    if (query.next()) // If query returns a result
    {
        QString hashed_password = query.value(0).toString();
        QString encoded_salt = query.value(1).toString();

        // Hash the entered master password with the retrieved salt
        QByteArray hashed_entered_m_password = hash_password(entered_master_password, encoded_salt);

        if (hashed_entered_m_password == hashed_password) // Compare the hashed passwords
        {
            db.close();
            return true;
        }
        else
        {
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

// Function to compare new passwords for match
bool account_settings::compare_new_passwords(const QString new_m_password, const QString confirm_m_password)
{
    if (new_m_password == confirm_m_password) // Compare the texts to see if they match
    {
        return true; // Return true if the texts match
    }
    else
    {
        qDebug() << "Passwords not matched!";
        return false; // Return false if the texts don't match
    }
}

// Function to save master password securely in the database
bool account_settings::save_master_password(const QString &user_id, const QString &password, QSqlDatabase db)
{
    // Hash password and retrieve salt and hashed password
    auto [hashed_password, salt] = hash_password(password);

    if (!db.open()) // Open SQLite database connection
    {
        qDebug() << "Error: Failed to open database.";
        return false;
    }

    // Insert hashed password and salt into the table
    QSqlQuery query(db);
    query.prepare("UPDATE users SET master_password = :master_password, salt = :salt WHERE id = :id");
    query.bindValue(":master_password", hashed_password);
    query.bindValue(":salt", salt);
    query.bindValue(":id", user_id);
    if (!query.exec())
    {
        qDebug() << "Error: Failed to insert values into table." << query.lastError().text();
        return false;
    }

    db.close(); // Close the database connection

    QMessageBox::information(this, "INFO", "Master password successfully changed! Please sign in with your new password.");
    return true; // Return true if insertion was successful
}

// Function to decrypt and encrypt passwords
bool account_settings::decrypt_and_encrypt_passwords(const QString &old_master_password, const QString &new_master_password, QSqlDatabase db)
{
    if (!db.open()) // Open the database connection
    {
        qDebug() << "Error: Failed to open database.";
        return false;
    }

    // Query to retrieve the hashed password and salt from the database for the given user_id
    QSqlQuery query(db);
    query.prepare("SELECT id, password, iv, salt FROM passwords WHERE user_id = :user_id");
    query.bindValue(":user_id", user_id);

    if (!query.exec()) // Execute the query
    {
        qDebug() << "Error executing query:" << query.lastError().text();
        db.close();
        return false;
    }

    while (query.next()) // If query returns a result
    {
        QString id = query.value(0).toString();
        QString password = query.value(1).toString();
        QString iv = query.value(2).toString();
        QString salt = query.value(3).toString();

        // Decrypt the password
        QString decrypted_password = decrypt_aes(password, old_master_password, salt, iv);

        QString salt_out;
        QString iv_out;

        // Encrypt the password with the new master password
        QString new_encrypted_password = encrypt_aes(decrypted_password, new_master_password, salt_out, iv_out);

        // Insert new encrypted password, salt and iv into the table
        QSqlQuery updateQuery(db);
        updateQuery.prepare("UPDATE passwords SET password = :password, salt = :salt, iv = :iv WHERE id = :id");
        updateQuery.bindValue(":password", new_encrypted_password);
        updateQuery.bindValue(":salt", salt_out);
        updateQuery.bindValue(":iv", iv_out);
        updateQuery.bindValue(":id", id);
        if (!updateQuery.exec())
        {
            qDebug() << "Error: Failed to insert values into table." << updateQuery.lastError().text();
            return false;
        }
    }
    db.close();
    return true;
}

// Slot for cancel button click
void account_settings::on_cancel_button_clicked()
{
    close(); // Close the account settings window
}

// Slot for save button click
void account_settings::on_save_button_clicked()
{
    QSqlDatabase& db = DatabaseManager::instance();

    // Check if the existing master password matches
    if (!compare_existing_master_password(ui->textEdit_old_password->toPlainText(), db))
    {
        QMessageBox::information(this, "ERROR", "Wrong master password!");
        return;
    }

    // Check if the new passwords match
    if (!compare_new_passwords(ui->textEdit_new_password->toPlainText(), ui->textEdit_confirm_password->toPlainText()))
    {
        QMessageBox::information(this, "ERROR", "Passwords not matched!");
        return;
    }

    // Decrypt and encrypt passwords with the new master password
    if (!decrypt_and_encrypt_passwords(ui->textEdit_old_password->toPlainText(), ui->textEdit_new_password->toPlainText(), db))
    {
        QMessageBox::information(this, "ERROR", "An error occurred while changing master password!");
        return;
    }

    // Save the new master password in the database
    if (!save_master_password(user_id, ui->textEdit_new_password->toPlainText(), db))
    {
        QMessageBox::information(this, "ERROR", "An error occurred while changing master password!");
        return;
    }

    // Close the main window and open the sign-in window
    sign_in *Sign_in = new sign_in();
    close();
    main_window->close();
    Sign_in->show();
}

void account_settings::on_delete_button_clicked()
{
    bool ok;
    QString entered_master_password = QInputDialog::getText(this, "Delete Account", "Enter master password:", QLineEdit::Password, "", &ok);
    if (ok && !entered_master_password.isEmpty()) {
        QSqlDatabase& db = DatabaseManager::instance();
        if (!db.open()) // Open the database connection
        {
            qDebug() << "Error: Failed to open database.";
            return;
        }

        // Query to retrieve the hashed password and salt from the database for the given user_id
        QSqlQuery query(db);
        query.prepare("SELECT master_password, salt FROM users WHERE id = :id");
        query.bindValue(":id", user_id);

        if (!query.exec()) // Execute the query
        {
            qDebug() << "Error executing query:" << query.lastError().text();
            db.close();
            return;
        }

        if (query.next()) // If query returns a result
        {
            QString hashed_password = query.value(0).toString();
            QString encoded_salt = query.value(1).toString();

            // Hash the entered master password with the retrieved salt
            QByteArray hashed_entered_m_password = hash_password(entered_master_password, encoded_salt);
            if (hashed_entered_m_password == hashed_password) {

                // Query to retrieve the hashed password and salt from the database for the given user_id
                QSqlQuery query(db);
                query.prepare("DELETE FROM passwords WHERE user_id = :user_id");
                query.bindValue(":user_id", user_id);

                if (!query.exec()) // Execute the query
                {
                    qDebug() << "Error executing query:" << query.lastError().text();
                    db.close();
                    return;
                }

                // Query to retrieve the hashed password and salt from the database for the given user_id
                query.prepare("DELETE FROM users WHERE id = :id");
                query.bindValue(":id", user_id);

                if (!query.exec()) // Execute the query
                {
                    qDebug() << "Error executing query:" << query.lastError().text();
                    db.close();
                    return;
                }

                QMessageBox::warning(this, "INFO", "Account has been deleted!");

                close();
                main_window->close();
                sign_in *sign_in_window = new sign_in();
                sign_in_window->show();

            } else {
                QMessageBox::warning(this, "Error", "Incorrect master password.");
            }
        }
        else
        {
            qDebug() << "An Error Occured";
            db.close();
            return;
        }
    } else {
        if (!ok) {
            qDebug("Account deletion cancelled by user.");
        }
    }
}

