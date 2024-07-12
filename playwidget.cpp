#include "playwidget.h"
#include "ui_playwidget.h"



PlayWidget::PlayWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlayWidget)
{
    GAMECLIP gameboardarray[10][10] = {
                                       {SHIP,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
                                       {SHIP,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
                                       {SHIP,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
                                       {SHIP,EMPTY,EMPTY,SHIP,SHIP,SHIP,EMPTY,EMPTY,EMPTY,EMPTY},
                                       {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
                                       {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
                                       {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
                                       {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY},
                                       {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,MINE,EMPTY,EMPTY,EMPTY},
                                       {EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY,EMPTY}};
    void arrangeShips();
    ui->setupUi(this);
    // myboard = new ClickableGameBoard(this,gameboardarray,QVector<int>({1,2,3}),false);
    enemyboard = new ClickableGameBoard(this,gameboardarray,QVector<int>({1,2,3}),true);
    // ui->verticalLayout->addWidget(myboard);
    ui->verticalLayout_2->addWidget(enemyboard);
}

void PlayWidget::setGameBoard(GAMECLIP newboard[10][10])
{
    myboard = new ClickableGameBoard(this,newboard,QVector<int>({1,2,3}),false);
    ui->verticalLayout->addWidget(myboard);
}

PlayWidget::~PlayWidget()
{
    delete ui;
}

