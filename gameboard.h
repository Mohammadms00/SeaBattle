#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QVector>
#include "DraggableShip.h"

class GameBoard : public QGraphicsView {
    Q_OBJECT

public:
    GameBoard(QWidget *parent = nullptr);

private:
    QGraphicsScene *scene;
    QVector<DraggableShip*> ships;
    static const int gridSize = 10;
    static const int cellSize = 40;
};

#endif // GAMEBOARD_H
