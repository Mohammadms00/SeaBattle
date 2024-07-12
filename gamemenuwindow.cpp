#include "gamemenuwindow.h"
#include "ui_gamemenuwindow.h"
#include "mainwindow.h"
#include "ondeviceplay.h"
GameMenuWindow::GameMenuWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GameMenuWindow)
{

    ui->setupUi(this);

}

GameMenuWindow::~GameMenuWindow()
{
    delete ui;
}
void GameMenuWindow::setUser(User *user)
{
    this->user = user;
    ui->UsernameLabel->setText(user->getUsername());
    QString money;
    QTextStream(&money) << user->getMoney() << " $";
    ui->MoneyLabel->setText(money);
    ui->LevelLabel->setText(QString::number(user->getLevel()));
    ui->ScoreLabel->setText(QString::number(user->getScore()));
    ui->WinLabel->setText(QString::number(user->getWin()));
    ui->LoseLabel->setText(QString::number(user->getLose()));
}

void GameMenuWindow::on_GameMenuWindow_finished(int result)
{
    (new MainWindow())->show();
}


void GameMenuWindow::on_pushButton_clicked()
{

    QString str;
    QTextStream(&str) << "Username: " << user->getUsername() << "\nPassword: " << user->getPassword() << "\nName: " << user->getName() << "\nLastName: " << user->getLastName() << "\nEmail: " << user->getEmail();
    msg.setText(str);
    msg.show();
}


void GameMenuWindow::on_OnDeviceButton_clicked()
{
    auto *odp = new OnDevicePlay();
    odp->setUser(user);
    odp->show();

}

