#include "gameboard.h"
#include "mineweapon.h"
GameBoard::GameBoard(QWidget *parent) : QGraphicsView(parent) {

    scene = new QGraphicsScene(this);
    setScene(scene);
    scene->setSceneRect(0, 0, gridSize * cellSize, gridSize * cellSize);

    for (int i = 0; i < gridSize; ++i) {
        for (int j = 0; j < gridSize; ++j) {
            scene->addRect(j * cellSize, i * cellSize, cellSize, cellSize, QPen(Qt::black), QBrush(Qt::white));
        }
    }
}

void GameBoard::setShips(QVector<DraggableShip *> ships)
{
    this->ships = ships;
    for (auto ship : ships) {
        scene->addItem(ship);
    }
}

QVector<DraggableShip *> GameBoard::getShips()
{
    return ships;
}

void GameBoard::initializeShips()
{
    ships.append(new DraggableShip(160, 40)); // 4-cell ship
    ships.append(new DraggableShip(120, 40)); // 3-cell ship
    ships.append(new DraggableShip(120, 40)); // 3-cell ship
    ships.append(new DraggableShip(80, 40));  // 2-cell ship
    ships.append(new DraggableShip(80, 40));  // 2-cell ship
    ships.append(new DraggableShip(80, 40));  // 2-cell ship
    ships.append(new DraggableShip(40, 40));  // 1-cell ship
    ships.append(new DraggableShip(40, 40));  // 1-cell ship
    ships.append(new DraggableShip(40, 40));  // 1-cell ship
    ships.append(new DraggableShip(40, 40));  // 1-cell ship
    arrangeShips();
}




void GameBoard::setBoard(GAMECLIP gameboardarray[10][10])
{
    bool cond = false;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if(this->gameboardarray[i][j] != gameboardarray[i][j])
                cond = true;
        }
    }
    if(cond)
    {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                this->gameboardarray[i][j] = gameboardarray[i][j];
            }
        }
        emit boardChanged(gameboardarray);
    }
}

void GameBoard::addMine()
{
    if (mines.size() >= 5) return;
    mines.append(new MineWeapon());
    arrangeWeapons();
}

void GameBoard::addAirDefense() {
    // if (airDefenses.size() < 2) {
    //     auto *airDefense = new DraggableLineGroup(gridSize * cellSize, 40);
    //     scene->addItem(airDefense);

    //     std::random_device rd;
    //     std::mt19937 gen(rd());
    //     std::uniform_int_distribution<> dis(0, gridSize * cellSize - 40);

    //     airDefense->setPos(0, dis(gen));
    //     airDefenses.append(airDefense);
    // }
    if (airDefenses.size() >= 2) return; // Limit to 2 air defenses

    int yPos = (rand() % (gridSize - 1)) * cellSize;
    auto *airDefense = new AirDefenseWeapon();
    scene->addItem(airDefense);
    airDefense->setPos(0, yPos);
    airDefenses.append(airDefense);
}

void GameBoard::resetWeapom()
{
    for (auto min : mines) {
        scene->removeItem(min);
    }
    this->mines.clear();
    for (auto airdefense : airDefenses) {
        scene->removeItem(airdefense);
    }
    this->airDefenses.clear();
}
void GameBoard::arrangeShips() {
    int xOffset = gridSize * cellSize + 40; // Position at the right side of the map
    int yOffset = -20;

    yOffset -= 30; // Move ships 30 units higher

    for (auto *ship : ships) {
        if (ship->rect().width() == 160) {
            scene->addItem(ship);
            ship->setPos(xOffset, yOffset);
            yOffset += ship->rect().height() + 10;
        }
    }

    yOffset += 10;
    for (auto *ship : ships) {
        if (ship->rect().width() == 120) {
            scene->addItem(ship);
            ship->setPos(xOffset, yOffset);
            yOffset += ship->rect().height() + 10;
        }
    }

    yOffset += 10;
    for (auto *ship : ships) {
        if (ship->rect().width() == 80) {
            scene->addItem(ship);
            ship->setPos(xOffset, yOffset);
            yOffset += ship->rect().height() + 10;
        }
    }

    yOffset += 10;
    for (auto *ship : ships) {
        if (ship->rect().width() == 40) {
            scene->addItem(ship);
            ship->setPos(xOffset, yOffset);
            yOffset += ship->rect().height() + 10;
        }
    }
    yOffset += 10;
    for (auto *mine : mines) {
        if (mine->rect().width() == 40) {
            scene->addItem(mine);
            mine->setPos(xOffset, yOffset);
            yOffset += mine->rect().height() + 10;
        }
    }
}

void GameBoard::arrangeWeapons() {
    int xOffset = gridSize * cellSize + 40; // Position at the right side of the map
    int yOffset = -20;

    yOffset -= 30; // Move ships 30 units higher

    for (auto *mine : mines) {
        scene->addItem(mine);
        mine->setPos(xOffset, yOffset);
        yOffset += mine->rect().height() + 10;
        qDebug()<<mine->rect();
    }


}

void GameBoard::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
    GAMECLIP boarder[10][10];

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            boarder[i][j] = EMPTY;
        }
    }

    for (auto ship : ships) {
        for (int i = 0; i < ship->getArrayRect().width(); ++i) {
            for (int j = 0; j < ship->getArrayRect().height(); ++j) {
                boarder[ship->getArrayRect().y()+j][ship->getArrayRect().x()+i] = SHIP;
            }

        }
    }
    for (auto min : mines) {
        for (int i = 0; i < min->getArrayRect().width(); ++i) {
            for (int j = 0; j < min->getArrayRect().height(); ++j) {
                boarder[min->getArrayRect().y()+j][min->getArrayRect().x()+i] = MINE;
            }

        }
    }
    setBoard(boarder);


}
