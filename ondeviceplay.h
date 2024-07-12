#ifndef ONDEVICEPLAY_H
#define ONDEVICEPLAY_H

#include <QMainWindow>
#include <QPushButton>
#include <QHBoxLayout>
#include <QSpacerItem>
#include "gameboard.h"
#include "placeshipswidget.h"
#include "buyweaponwidget.h"
#include "playwidget.h"
#include "user.h"
enum STATE{
    PLACINGSHIPS,
    BUYINGWEAPON,
    PLAYING
};


class OnDevicePlay : public QMainWindow
{
    Q_OBJECT

public:
    explicit OnDevicePlay(QWidget *parent = nullptr);
    void setUser(User *user);
private slots:
    void setState(STATE newstate);

    void placeShipsNext(QVector<DraggableShip *> ships);
    void buyWeaponPreviuos(QVector<DraggableShip *> ships);
private:
    QVector<DraggableShip *> ships;
    STATE mystate = PLACINGSHIPS;
    placeShipsWidget *psw;
    buyWeaponWidget *bww;
    PlayWidget *pw;
};

#endif // ONDEVICEPLAY_H
