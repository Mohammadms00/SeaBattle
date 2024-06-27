#include "database.h"

Database::Database() {
    QDir databasePath;
    QString path = "SeaBattleDB.db";
    this->dbConnection = QSqlDatabase::addDatabase("QSQLITE");
    dbConnection.setDatabaseName(path);
    dbConnection.open();
    QSqlQuery query;
    query.exec("CREATE TABLE IF NOT EXISTS users ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "username TEXT UNIQUE NOT NULL, "
               "password TEXT NOT NULL, "
               "name TEXT NOT NULL, "
               "lastname TEXT NOT NULL, "
               "email TEXT NOT NULL, "
               "money INTEGER DEFAULT 30, "
               "win INTEGER DEFAULT 0, "
               "lose INTEGER DEFAULT 0, "
               "level INTEGER DEFAULT 1, "
               "score INTEGER DEFAULT 0)");
    if (!query.exec()) {
        qDebug() << "Error creating table";
        return;
    }
}
Database::~Database() {
    dbConnection.close();
}
bool Database::AddUser(QString Username, QString Password, QString Name, QString LastName, QString Email)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password, name, lastname, email) VALUES (?, ?, ?, ?, ?)");
    if(Username.length() > 0 && Password.length()>0 && Name.length()>0 && LastName.length()>0 && Email.length() > 0)
    {
        query.addBindValue(Username);
        query.addBindValue(Password);
        query.addBindValue(Name);
        query.addBindValue(LastName);
        query.addBindValue(Email);
        if (!query.exec()) {
            qDebug() << "Error adding user:" << query.lastError().text();
            return false;
        }
    }
    return true;
}
bool Database::ValidateUser(QString Username, QString Password)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = ? AND password = ?");
    query.addBindValue(Username);
    query.addBindValue(Password);

    if (!query.exec() || !query.next()) {
        return false;
    }
    return true;
}
QString Database::UserPassword(QString Username,QString Email)
{
    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = ? AND email = ?");
    query.addBindValue(Username);
    query.addBindValue(Email);
    QString password="";
    if(query.next()) {
        password = query.value(0).toString();
    }
    return password;
}
