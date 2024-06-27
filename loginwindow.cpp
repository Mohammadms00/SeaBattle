#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "mainwindow.h"
#include "database.h"
#include "forgetpasswordwindow.h"
LogInWindow::LogInWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LogInWindow)
{
    ui->setupUi(this);
}

LogInWindow::~LogInWindow()
{
    delete ui;
}

void LogInWindow::on_LogInWindow_finished(int result)
{
    MainWindow *mw = new MainWindow();
    mw->show();
}


void LogInWindow::on_LogInButton_clicked()
{
    Database *db = new Database();
    db->ValidateUser(ui->UsernameLE->text(),ui->PasswordLE->text());
}




void LogInWindow::on_ForgetPasswordButton_clicked()
{
    hide();
    ForgetPasswordWindow *fpw = new ForgetPasswordWindow();
    fpw->show();
}

