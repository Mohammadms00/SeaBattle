#include "user.h"

User::User(QString username,QString password,QString name,QString lastname,QString email,int money,int win,int lose,int level,int score){
    this->username = username;
    this->password = password;
    this->name = name;
    this->lastname = lastname;
    this->email = email;
    this->money = money;
    this->win = win;
    this->lose = lose;
    this->level = level;
    this->score = score;
}

User::User(QString username, QString password,QString name,QString lastname,QString email){
    this->username = username;
    this->password = password;
    this->name = name;
    this->lastname = lastname;
    this->email = email;
}

void User::setMoney(int _money) {
    this->money = _money;
}

void User::setWin(int _win) {
    this->win = _win;
}

void User::setLose(int _lose) {
    this->lose = _lose;
}

void User::setLevel(int _level) {
    this->level = _level;
}

void User::setScore(int _score) {
    this->score = _score;
}

QString User::getUsername(){
    return username;
}

QString User::getPassword(){
    return password;
}

QString User::getName(){
    return name;
}

QString User::getLastName(){
    return lastname;
}

QString User::getEmail(){
    return email;
}

int User::getMoney() {
    return money;
}

int User::getWin() {
    return win;
}

int User::getLose() {
    return lose;
}

int User::getLevel() {
    return level;
}

int User::getScore() {
    return score;
}
