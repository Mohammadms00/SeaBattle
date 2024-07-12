#ifndef PLACESHIPSWIDGET_H
#define PLACESHIPSWIDGET_H

#include <QWidget>
#include "gameboard.h"

namespace Ui {
class placeShipsWidget;
}

class placeShipsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit placeShipsWidget(QWidget *parent = nullptr);
    ~placeShipsWidget();
    void setShips(QVector<DraggableShip *> ships);
private slots:
    void on_board_changed(GAMECLIP newboard[10][10]);
signals:
    void widgetAccept(QVector<DraggableShip *> ships);
private:
    Ui::placeShipsWidget *ui;
    GAMECLIP board[10][10];
    QVector<DraggableShip *> ships;
    GameBoard *gameroard;
};

#endif // PLACESHIPSWIDGET_H
