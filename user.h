#ifndef USER_H
#define USER_H

#include<QString>

class User
{
private:
    QString username;
    QString password;
    QString name;
    QString lastname;
    QString email;
    int money;
    int win;
    int lose;
    int level;
    int score;

public:
    User(QString username,QString password,QString name,QString lastname,QString email,int money,int win,int lose,int level,int score);
    User(QString username, QString password,QString name,QString lastname,QString email);
    void setMoney(int _money);
    void setWin(int _win);
    void setLose(int _lose);
    void setLevel(int _level);
    void setScore(int _score);
    QString getUsername();
    QString getPassword();
    QString getName();
    QString getLastName();
    QString getEmail();
    int getMoney();
    int getWin();
    int getLose();
    int getLevel();
    int getScore();
};

#endif // USER_H
