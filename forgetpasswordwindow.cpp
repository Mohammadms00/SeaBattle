#include "forgetpasswordwindow.h"
#include "ui_forgetpasswordwindow.h"
#include "loginwindow.h"
#include "database.h"
ForgetPasswordWindow::ForgetPasswordWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ForgetPasswordWindow)
{
    ui->setupUi(this);
}

ForgetPasswordWindow::~ForgetPasswordWindow()
{
    delete ui;
}




void ForgetPasswordWindow::on_ForgetPasswordWindow_finished(int result)
{
    hide();
    LogInWindow *liw = new LogInWindow();
    liw->show();
}


void ForgetPasswordWindow::on_RestorePasswordButton_clicked()
{
    Database *db = new Database();
    QString password = db->UserPassword(ui->UsernameLE->text(),ui->EmailLE->text());
    QMessageBox msg;
    msg.setText("your password is "+password);
    msg.show();
    finished(1);
}

