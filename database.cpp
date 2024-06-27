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
bool Database::AddUser(User user)
{
    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password, name, lastname, email) VALUES (?, ?, ?, ?, ?)");
    if(user.getUsername().length() > 0 && user.getPassword().length()>0 && user.getName().length()>0 && user.getLastName().length()>0 && user.getEmail().length() > 0)
    {
        query.addBindValue(user.getUsername());
        query.addBindValue(user.getPassword());
        query.addBindValue(user.getName());
        query.addBindValue(user.getLastName());
        query.addBindValue(user.getEmail());
        if (!query.exec()) {
            qDebug() << "Error adding user:" << query.lastError().text();
            return false;
        }
    }
    return true;
}
User *Database::ValidateUser(QString Username, QString Password)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM users WHERE username = ? AND password = ?");
    query.addBindValue(Username);
    query.addBindValue(Password);

    if (!query.exec() || !query.next()) {
        return nullptr;
    }
    return (new User(query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString(),query.value(6).toInt(),query.value(7).toInt(),query.value(8).toInt(),query.value(9).toInt(),query.value(10).toInt()));
}
QString Database::UserPassword(QString Username,QString Email)
{
    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = ? AND email = ?");
    query.addBindValue(Username);
    query.addBindValue(Email);

    if (!query.exec() || !query.next()) {
        return "";
    }
    return query.value(0).toString();
}
