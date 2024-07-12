#ifndef BUYWEAPONWIDGET_H
#define BUYWEAPONWIDGET_H

#include <QWidget>
#include "gameboard.h"
#include "mineweapon.h"
#include "user.h"

namespace Ui {
class buyWeaponWidget;
}

class buyWeaponWidget : public QWidget
{
    Q_OBJECT

public:
    explicit buyWeaponWidget(QWidget *parent = nullptr);
    ~buyWeaponWidget();

public slots:
    void setShips(QVector<DraggableShip *> ships);
    void setUser(User *user);
signals:
    void goBack(QVector<DraggableShip *> ships);
    void goNext(GAMECLIP gameboard[10][10]);
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::buyWeaponWidget *ui;
    GAMECLIP board[10][10];
    QVector<DraggableShip *> ships;
    QVector<MineWeapon *> mine;
    GameBoard *gameroard;
    User *user;
    int radarcount = 0;
    int atomicbombcount = 0;
    int linearbombcount = 0;
};

#endif // BUYWEAPONWIDGET_H
