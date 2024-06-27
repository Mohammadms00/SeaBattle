#ifndef DATABASE_H
#define DATABASE_H

#include <QDir>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class Database
{
public:
    Database();
    ~Database();
    bool AddUser(QString Username, QString Password,QString Name,QString LastName,QString Email);
    bool ValidateUser(QString Username, QString Password);
    QString UserPassword(QString Username,QString Password);
private:
    QSqlDatabase dbConnection;
};

#endif // DATABASE_H
