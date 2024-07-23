#ifndef DATABASE_H
#define DATABASE_H

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QDir>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>
#include <QApplication>

class DatabaseManager {
public:
    static QSqlDatabase& instance() {
        static QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "my_connection");
        QString database_name =  qApp->applicationDirPath() + "/../../database/database.db";
        db.setDatabaseName(database_name);
        return db;
    }
};

#endif // DATABASE_H
