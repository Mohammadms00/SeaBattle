#ifndef GAMEMENUWINDOW_H
#define GAMEMENUWINDOW_H

#include <QDialog>
#include <QTextStream>
#include <QString>
#include <QMessageBox>
#include "user.h"

namespace Ui {
class GameMenuWindow;
}

class GameMenuWindow : public QDialog
{
    Q_OBJECT

public:
    explicit GameMenuWindow(QWidget *parent = nullptr);
    ~GameMenuWindow();
    void setUser(User *user);

private slots:
    void on_GameMenuWindow_finished(int result);

    void on_pushButton_clicked();

    void on_OnDeviceButton_clicked();

private:
    Ui::GameMenuWindow *ui;
    User *user;
    QMessageBox msg;
};

#endif // GAMEMENUWINDOW_H
