#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVector>
#include <QDropEvent>
#include "DraggableShip.h"
#include "mineweapon.h"
#include "airdefenseweapon.h"
enum GAMECLIP{
    EMPTY,
    SHIP,
    MINE,
};

class GameBoard : public QGraphicsView {
    Q_OBJECT

public:
    GameBoard(QWidget *parent = nullptr);
    void setShips(QVector<DraggableShip*> ships);
    QVector<DraggableShip*> getShips();
    void initializeShips();
public slots:
    void setBoard(GAMECLIP gameboardarray[10][10]);
    void addMine();
    void addAirDefense();
    void resetWeapom();
signals:
    void boardChanged(GAMECLIP newgameboardarray[10][10]);
protected:
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QGraphicsScene *scene;
    QVector<DraggableShip*> ships;
    QVector<MineWeapon*> mines;
    QVector<AirDefenseWeapon*> airDefenses;
    static const int gridSize = 10;
    static const int cellSize = 40;
    GAMECLIP gameboardarray[10][10] = {
                                       {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
                                       {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
                                       {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
                                       {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
                                       {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
                                       {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
                                       {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
                                       {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
                                       {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
                                       {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY}};
    void arrangeShips();
    void arrangeWeapons();
};

#endif // GAMEBOARD_H
