#include "clickablegameboard.h"
#include <QPainter>


ClickableGameBoard::ClickableGameBoard(QWidget *parent, GAMECLIP gameboard[10][10], QVector<int> airdefenserow, bool enemymode) : QGraphicsView(parent),airdefenserow(airdefenserow),enemymode(enemymode)
{

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            this->gameboard[i][j] = gameboard[i][j];
            this->clicked[i][j] = false;
        }
    }
    scene = new QGraphicsScene(this);
    setScene(scene);
    scene->setSceneRect(0, 0, gridSize * cellSize, gridSize * cellSize);
    draw();
}

void ClickableGameBoard::setGameBoard(GAMECLIP newgameboard[10][10])
{
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            this->gameboard[i][j] = newgameboard[i][j];
            scene->clear();
            draw();
        }
    }
}


void ClickableGameBoard::mousePressEvent(QMouseEvent *event)
{
    if(!enemymode) return;
    QGraphicsView::mousePressEvent(event);
    QPointF pos(event->pos().x()-(this->size().width()-(gridSize * cellSize))/2,event->pos().y()-(this->size().height()-(gridSize * cellSize))/2);
    QGraphicsRectItem *cell = dynamic_cast<QGraphicsRectItem *>(scene->itemAt(pos,QTransform()));

    if(!this->clicked[(int)(pos.x()/cellSize)][(int)(pos.y()/cellSize)])
    {
        if(this->gameboard[(int)(pos.x()/cellSize)][(int)(pos.y()/cellSize)] == SHIP)
        {
            if(!drowmShip((int)(pos.x()/cellSize),(int)(pos.y()/cellSize)))
                cell->setBrush(QBrush(QPixmap(":/weapons/images/X.png")));
            else
                cell->setBrush(QBrush(Qt::red));

        }
        else if(this->gameboard[(int)(pos.x()/cellSize)][(int)(pos.y()/cellSize)] == MINE)
            cell->setBrush(QBrush(QPixmap(":/weapons/images/X.png")));
        else
            cell->setBrush(QBrush(Qt::yellow));
        this->clicked[(int)(pos.x()/cellSize)][(int)(pos.y()/cellSize)] = true;
    }
}

void ClickableGameBoard::draw()
{
    if(enemymode)
        for (int i = 0; i < gridSize; ++i) {
            for (int j = 0; j < gridSize; ++j) {
                scene->addRect(j * cellSize, i * cellSize, cellSize, cellSize, QPen(Qt::black), QBrush(Qt::white));
            }
        }
    else
    {

        QPixmap pixmap(":/weapons/images/mine.png");
        pixmap.scaled(cellSize,cellSize,Qt::IgnoreAspectRatio,Qt::TransformationMode::SmoothTransformation);
        for (int i = 0; i < gridSize; ++i) {
            for (int j = 0; j < gridSize; ++j) {
                switch (gameboard[i][j]) {
                case EMPTY:
                    scene->addRect(j * cellSize, i * cellSize, cellSize, cellSize, QPen(Qt::black), QBrush(Qt::white));
                    break;
                case SHIP:
                    scene->addRect(j * cellSize, i * cellSize, cellSize, cellSize, QPen(Qt::black), QBrush(Qt::blue));
                    break;
                case MINE:
                    scene->addRect(j * cellSize, i * cellSize, cellSize, cellSize, QPen(Qt::black), QBrush(pixmap));
                    break;
                default:
                    break;
                }

            }
        }
    }
}

bool ClickableGameBoard::drowmShip(int i, int j)
{
    if(gameboard[i][j] == SHIP){
        if(clicked[i][j])
        {
            bool result = true;
            if(i>0)
                result &= drowmShip(i-1,j);
            if(i<9)
                result &= drowmShip(i+1,j);
            if(j>0)
                result &= drowmShip(i,j-1);
            if(j<9)
                result &= drowmShip(i,j+1);
            return result;
        }
        else
            return false;
    }
    else {
        return true;
    }
}



