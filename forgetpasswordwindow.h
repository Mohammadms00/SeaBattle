#ifndef FORGETPASSWORDWINDOW_H
#define FORGETPASSWORDWINDOW_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class ForgetPasswordWindow;
}

class ForgetPasswordWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ForgetPasswordWindow(QWidget *parent = nullptr);
    ~ForgetPasswordWindow();

private slots:


    void on_ForgetPasswordWindow_finished(int result);

    void on_RestorePasswordButton_clicked();

private:
    Ui::ForgetPasswordWindow *ui;
    QMessageBox msg;
};

#endif // FORGETPASSWORDWINDOW_H
