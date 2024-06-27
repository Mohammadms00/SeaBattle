#include "signupwindow.h"
#include "ui_signupwindow.h"
#include "mainwindow.h"
#include "database.h"
#include "user.h"

SignUpWindow::SignUpWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::on_SignUpButton_clicked()
{
    Database *db = new Database();
    db->AddUser(User(ui->UsernameLE->text(),ui->PasswordLE->text(),ui->NameLE->text(),ui->LastNameLE->text(),ui->EmailLE->text()));
    this->finished(1);
}


void SignUpWindow::on_SignUpWindow_finished(int result)
{
    hide();
    MainWindow *mw = new MainWindow();
    mw->show();
}

