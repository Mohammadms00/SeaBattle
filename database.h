#ifndef DATABASE_H
#define DATABASE_H

#include <QDir>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <vector>
#include "user.h"

class Database
{
public:
    Database();
    ~Database();
    bool AddUser(User user);
    User *ValidateUser(QString Username, QString Password);
    bool UpdateUser(User user);
    QString UserPassword(QString Username,QString Password);
private:
    QSqlDatabase dbConnection;
};

#endif // DATABASE_H
