#ifndef CLICKABLEGAMEBOARD_H
#define CLICKABLEGAMEBOARD_H

#include <QGraphicsView>
#include "gameboard.h"

class ClickableGameBoard : public QGraphicsView
{
public:
    ClickableGameBoard(QWidget *parent,GAMECLIP gameboard[10][10],QVector<int> airdefenserow,bool enemymode);
public slots:
    void setGameBoard(GAMECLIP newgameboard[10][10]);
signals:
    void Clicked(int i,int j);
protected:
    void mousePressEvent(QMouseEvent *event) override;
private:
    void draw();
    GAMECLIP gameboard[10][10];
    bool clicked[10][10];
    QVector<int> airdefenserow;
    bool enemymode;
    QGraphicsScene *scene;
    static const int gridSize = 10;
    static const int cellSize = 30;
    bool drowmShip(int i,int j);
};

#endif // CLICKABLEGAMEBOARD_H
