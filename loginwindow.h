#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QDialog>

namespace Ui {
class LogInWindow;
}

class LogInWindow : public QDialog
{
    Q_OBJECT

public:
    explicit LogInWindow(QWidget *parent = nullptr);
    ~LogInWindow();

private slots:
    void on_LogInWindow_finished(int result);

    void on_LogInButton_clicked();


    void on_ForgetPasswordButton_clicked();

private:
    Ui::LogInWindow *ui;
};

#endif // LOGINWINDOW_H
