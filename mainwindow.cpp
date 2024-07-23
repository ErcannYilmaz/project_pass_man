#include "mainwindow.h"
#include "./ui_mainwindow.h"

// Constructor
MainWindow::MainWindow(const QString &username, const QString &password, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_username(username)
    , m_password(password)
{
    ui->setupUi(this);
    QSqlDatabase& db = DatabaseManager::instance();
    list_stored_passwords(m_username, db, ui->scroll_area);
}

// Destructor
MainWindow::~MainWindow()
{
    delete ui;
}

// Function to list all stored passwords for a given user
bool MainWindow::list_stored_passwords(const QString &username, QSqlDatabase db, QScrollArea *scroll_area)
{
    // Check if the database is open
    if (!db.open())
    {
        QMessageBox::information(this, tr("ERROR"),tr("An error occurred while opening the database!"));
        return false;
    }

    // Prepare SQL query to select passwords for the given user
    QSqlQuery query(db);
    query.prepare("SELECT id, website, username, password, salt, iv FROM passwords WHERE user_id = (SELECT id FROM users WHERE username = :username)");
    query.bindValue(":username", username);

    // Execute the query and iterate over the results
    if (query.exec())
    {
        QVBoxLayout *layout = new QVBoxLayout();
        layout->setSpacing(20);
        QWidget *content_widget = new QWidget();
        content_widget->setLayout(layout);
        scroll_area->setWidget(content_widget);

        while (query.next())
        {
            QString password_id = query.value(0).toString();
            QString website = query.value(1).toString();
            QString username = query.value(2).toString();
            QString password = query.value(3).toString();
            QString salt = query.value(4).toString();
            QString iv = query.value(5).toString();

            // Create a new group box for each record
            QGroupBox *group_box = new QGroupBox();
            group_box->setStyleSheet("background-color: rgb(34, 40, 49);\npadding-top: 3px;\npadding-left: 3px;");
            group_box->setMaximumHeight(150);

            // Create a vertical layout for the group box
            QVBoxLayout *vbox = new QVBoxLayout(group_box);

            // Add labels for username and password
            QLabel *website_label = new QLabel("Website: " + website);
            website_label->setTextInteractionFlags(Qt::TextSelectableByMouse);
            QLabel *username_label = new QLabel("Username: " + username.left(3) + "*****");
            username_label->setTextInteractionFlags(Qt::TextSelectableByMouse);
            QLabel *password_label = new QLabel("Password: ***********");
            password_label->setTextInteractionFlags(Qt::TextSelectableByMouse);

            // Add labels to the layout
            vbox->addWidget(website_label);
            vbox->addWidget(username_label);
            vbox->addWidget(password_label);

            // Create horizontal layout for buttons
            QHBoxLayout *button_layout = new QHBoxLayout();

            // Create edit and delete buttons
            QPushButton *edit_button = new QPushButton("Edit");
            QPushButton *delete_button = new QPushButton("Delete");
            QPushButton *show_button = new QPushButton("Show");

            edit_button->setStyleSheet("QPushButton {\n    background-color: rgb(34, 40, 49);\nborder: 2px solid rgb(150, 150, 150);\n}\nQPushButton:hover:!pressed {\n   background-color: rgb(150, 150, 150);\n}");
            delete_button->setStyleSheet("QPushButton {\n    background-color: rgb(34, 40, 49);\nborder: 2px solid rgb(150, 150, 150);\n}\nQPushButton:hover:!pressed {\n   background-color: rgb(150, 150, 150);\n}");
            show_button->setStyleSheet("QPushButton {\n    background-color: rgb(34, 40, 49);\nborder: 2px solid rgb(150, 150, 150);\n}\nQPushButton:hover:!pressed {\n   background-color: rgb(150, 150, 150);\n}");

            edit_button->setFixedSize(140, 26);
            delete_button->setFixedSize(140, 26);
            show_button->setFixedSize(140, 26);
            edit_button->setCursor(Qt::PointingHandCursor);
            delete_button->setCursor(Qt::PointingHandCursor);
            show_button->setCursor(Qt::PointingHandCursor);

            QObject::connect(delete_button, &QPushButton::clicked, this, [=]() {
                on_delete_button_clicked(password_id);
            });

            QObject::connect(edit_button, &QPushButton::clicked, this, [=]() {
                on_edit_button_clicked(password_id, m_username, m_password, website, username, decrypt_aes(password, m_password, salt, iv));
            });

            QObject::connect(show_button, &QPushButton::clicked, this, [=]() {
                on_show_button_clicked(m_password, iv, salt, username, password, username_label, password_label, show_button);
            });

            // Add buttons to the button layout
            button_layout->addWidget(show_button);
            button_layout->addWidget(edit_button);
            button_layout->addWidget(delete_button);

            // Add button layout to the main layout
            vbox->addLayout(button_layout);

            // Add the group box to the main layout
            layout->addWidget(group_box);
        }
    }
    else
    {
        QMessageBox::information(this, "ERROR", "An error occurred while executing the query!" + query.lastError().text());
        return false;
    }

    // Close the database connection
    db.close();
    return true;
}

// Function to add a new password for a given user
bool MainWindow::add_new_password(const QString &m_username, const QString &m_password, const QString &website, const QString &username, const QString &password, QSqlDatabase db)
{
    // Check if the database is open
    if (!db.open()) {
        qDebug() << "Database is not open.";
        return false;
    }

    QSqlQuery query(db);
    query.prepare("SELECT id FROM users WHERE username = :username");
    query.bindValue(":username", m_username);

    // Execute the query and check the result
    if (!query.exec())
    {
        QMessageBox::information(this, "ERROR", "An error occurred while executing the query!" + query.lastError().text());
        return false;
    }

    if (query.next())
    {
        int user_id = query.value(0).toInt();

        // Encrypt password
        QString salt_out;
        QString iv_out;
        QString encrypted_password = encrypt_aes(password, m_password, salt_out, iv_out);

        // Prepare SQL query to add the new password to the database
        QSqlQuery query(db);
        query.prepare("INSERT INTO passwords (user_id, username, website, password, salt, iv) VALUES (:user_id, :username, :website, :password, :salt, :iv)");
        query.bindValue(":user_id", user_id);
        query.bindValue(":username", username);
        query.bindValue(":website", website);
        query.bindValue(":password", encrypted_password);
        query.bindValue(":salt", salt_out);
        query.bindValue(":iv", iv_out);

        // Execute the query and check the result
        if (!query.exec()) {
            QMessageBox::information(this, "ERROR", "An error occurred while executing the query!" + query.lastError().text());
            return false;
        }
    }
    return true;
}

// Slot for delete button click
void MainWindow::on_delete_button_clicked(const QString &password_id)
{
    QSqlDatabase& db = DatabaseManager::instance();
    QMessageBox::StandardButton reply = QMessageBox::question(this, "DELETE RECORD", "Are you sure you want to delete record?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        // Check if the database is open
        if (!db.open()) {
            QMessageBox::information(this, "ERROR", "An error occurred while deleting the password: Database not open!");
            return;
        }

        // Prepare SQL query to delete the password from the database
        QSqlQuery query(db);
        query.prepare("DELETE FROM passwords WHERE id = :id");
        query.bindValue(":id", password_id);

        // Execute the query and check the result
        if (!query.exec())
        {
            QMessageBox::information(this, "ERROR", "An error occurred while deleting the password!" + query.lastError().text());
            return;
        }

        // list updated passwords
        if (!list_stored_passwords(m_username, db, ui->scroll_area))
        {
            qDebug() << "An error occurred while listing passwords!";
        }
    }
    else {
        return;
    }
}

// Slot for edit button click
void MainWindow::on_edit_button_clicked(const QString &password_id, const QString &m_username, const QString &m_password, const QString &website, const QString &username, const QString &password)
{
    QPushButton *clicked_button = qobject_cast<QPushButton*>(sender());
    if (clicked_button) {
        QSqlDatabase& db = DatabaseManager::instance();
        edit_password *edit = new edit_password(password_id, m_username, m_password, website, username, password);
        edit->show();
    }
}

// Slot for show button click
void MainWindow::on_show_button_clicked(const QString m_password, const QString iv, const QString salt, const QString &username, const QString &password, QLabel *username_label, QLabel *password_label, QPushButton *show_button)
{
    QPushButton *clicked_button = qobject_cast<QPushButton*>(sender());
    if (clicked_button) {
        if (show_button->text() == "Show")
        {
            username_label->setText("Username: " + username);
            password_label->setText("Password: " + decrypt_aes(password, m_password, salt, iv));
            show_button->setText("Hide");
        }
        else
        {
            username_label->setText("Username: " + username.left(3) + "*****");
            password_label->setText("Password: ***********");
            show_button->setText("Show");
        }
    }
}

// Slot for add button click
void MainWindow::on_add_button_clicked()
{
    QSqlDatabase& db = DatabaseManager::instance();
    QString website = ui->text_edit_website->toPlainText();
    QString username = ui->text_edit_username->toPlainText();
    QString password = ui->text_edit_password->toPlainText();
    if (!add_new_password(m_username, m_password, website, username, password, db))
    {
        QMessageBox::information(this, "ERROR", "An error occurred while saving the password to the database!");
    }
    else
    {
        QMessageBox::information(this, "INFO", "Password successfully saved!");
        ui->text_edit_website->setText("");
        ui->text_edit_username->setText("");
        ui->text_edit_password->setText("");
    }

    if (!list_stored_passwords(m_username, db, ui->scroll_area))
    {
        qDebug() << "An error occurred while listing passwords!";
    }
}

// Slot for sign out button click
void MainWindow::on_sign_out_button_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this, "SIGN OUT", "Are you sure you want to sign out?", QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        sign_in *sign_in_window = new sign_in();
        close();
        sign_in_window->show();
    }
    else {
        qDebug("Signing out cancelled!");
    }
}

// Slot for refresh button click
void MainWindow::on_refresh_button_clicked()
{
    QSqlDatabase& db = DatabaseManager::instance();
    list_stored_passwords(m_username, db, ui->scroll_area);
}

// Slot for change master password button click
void MainWindow::on_change_mpassword_button_clicked()
{
    QSqlDatabase& db = DatabaseManager::instance();

    // Check if the database is open
    if (!db.open())
    {
        QMessageBox::information(this, tr("ERROR"),tr("An error occurred while opening the database!"));
        return;
    }

    QSqlQuery query(db);
    query.prepare("SELECT id FROM users WHERE username = :username");
    query.bindValue(":username", m_username);
    if (query.exec())
    {
        if (query.next())
        {
            QString user_id = query.value(0).toString();
            account_settings *account_settings_window = new account_settings(this, user_id);
            account_settings_window->show();
        }
        else
        {
            QMessageBox::information(this, tr("ERROR"), tr("No user found with the given username!"));
        }
    }
    else
    {
        QMessageBox::information(this, "ERROR", "An error occurred while executing the query!" + query.lastError().text());
        return;
    }
}
