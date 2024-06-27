#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "signupwindow.h"
#include "loginwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_SignUpButton_clicked()
{
    hide();
    SignUpWindow *suw = new SignUpWindow();
    suw->show();
    // suw->closeEvent();
}


void MainWindow::on_LogInButton_clicked()
{
    hide();
    LogInWindow *liw = new LogInWindow();
    liw->show();
}

// void on_Close_SignUpWindow()
