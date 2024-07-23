#include "edit_password.h"
#include "ui_edit_password.h"

// Constructor
edit_password::edit_password(const QString &password_id, const QString &m_username, const QString &m_password, const QString &website, const QString &username, const QString &password, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::edit_password)
    , m_username(m_username)
    , m_password(m_password)
    , website(website)
    , username(username)
    , password(password)
    , password_id(password_id)
{
    ui->setupUi(this);
    set_placeholders();
}

// Destructor
edit_password::~edit_password()
{
    delete ui;
}

// Function to check if passwords match
bool edit_password::check_passwords_matches(const QString &password, const QString &confirm_password)
{
    if (!password.isEmpty())
    {
        return password == confirm_password;
    }
    else
    {
        return false;
    }
}

// Function to set placeholders in the UI
void edit_password::set_placeholders()
{
    ui->text_edit_website->setText(website);
    ui->text_edit_username->setText(username);
    ui->text_edit_password->setText(password);
    ui->text_edit_password_confirm->setText(password);
}

// Slot for cancel button click
void edit_password::on_cancel_button_clicked()
{
    close();
}

// Slot for save button click
void edit_password::on_save_button_clicked()
{
    if (check_passwords_matches(ui->text_edit_password->toPlainText(), ui->text_edit_password_confirm->toPlainText()))
    {
        QSqlDatabase& db = DatabaseManager::instance();

        // Encrypt password
        QString salt_out;
        QString iv_out;
        QString encrypted_password = encrypt_aes(ui->text_edit_password->toPlainText(), m_password, salt_out, iv_out);

        // Ensure the database is open
        if (!db.open()) {
            qDebug() << "Failed to open the database:" << db.lastError().text();
            return;
        }

        // Prepare SQL query to update the password in the database
        QSqlQuery query(db);
        query.prepare("UPDATE passwords SET website = :website, username = :username, password = :password, salt = :salt, iv = :iv WHERE id = :password_id");
        query.bindValue(":username", ui->text_edit_username->toPlainText());
        query.bindValue(":website", ui->text_edit_website->toPlainText());
        query.bindValue(":password", encrypted_password);
        query.bindValue(":salt", salt_out);
        query.bindValue(":iv", iv_out);
        query.bindValue(":password_id", password_id);

        // Execute the query and check the result
        if (!query.exec()) {
            QMessageBox::information(this, "ERROR", "An error occurred while executing the query!" + query.lastError().text());
            return;
        }
        else
        {
            QMessageBox::information(this, "INFO", "Record successfully updated!");
            close();
        }
    }
    else
    {
        qDebug() << "Passwords not matching!";
    }
}
