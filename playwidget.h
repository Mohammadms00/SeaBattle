#ifndef PLAYWIDGET_H
#define PLAYWIDGET_H

#include <QWidget>
#include "clickablegameboard.h"

namespace Ui {
class PlayWidget;
}

class PlayWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PlayWidget(QWidget *parent = nullptr);
    void setGameBoard(GAMECLIP newboard[10][10]);
    ~PlayWidget();

private:
    Ui::PlayWidget *ui;
    ClickableGameBoard *myboard;
    ClickableGameBoard *enemyboard;
};

#endif // PLAYWIDGET_H
