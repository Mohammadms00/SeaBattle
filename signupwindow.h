#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H

#include <QDialog>


namespace Ui {
class SignUpWindow;
}

class SignUpWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SignUpWindow(QWidget *parent = nullptr);
    ~SignUpWindow();

private slots:
    void on_SignUpButton_clicked();

    void on_SignUpWindow_finished(int result);

private:
    Ui::SignUpWindow *ui;

};

#endif // SIGNUPWINDOW_H
