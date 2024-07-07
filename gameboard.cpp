#include "gameboard.h"
#include <QGraphicsRectItem>
#include <QPen>
#include <QBrush>

GameBoard::GameBoard(QWidget *parent) : QGraphicsView(parent) {
    scene = new QGraphicsScene(this);
    setScene(scene);
    scene->setSceneRect(0, 0, gridSize * cellSize, gridSize * cellSize);

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            scene->addRect(j * cellSize, i * cellSize, cellSize, cellSize, QPen(Qt::black), QBrush(Qt::white));
        }
    }

    int initialY = gridSize * cellSize + 10;
    ships.append(new DraggableShip(160, 40));
    ships.append(new DraggableShip(120, 40));
    ships.append(new DraggableShip(80, 40));
    ships.append(new DraggableShip(40, 40));

    int xOffset = 10;
    for (auto *ship : ships) {
        scene->addItem(ship);
        ship->setPos(xOffset, initialY);
        xOffset += ship->rect().width() + 10;
    }
}
