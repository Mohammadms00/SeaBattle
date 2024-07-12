#include "placeshipswidget.h"
#include "ui_placeshipswidget.h"

placeShipsWidget::placeShipsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::placeShipsWidget)
{
    ui->setupUi(this);
    gameroard = new GameBoard();
    connect(gameroard,&GameBoard::boardChanged,this,&placeShipsWidget::on_board_changed);
    connect(ui->submitButton,&QPushButton::clicked,this,[=](){emit widgetAccept(this->ships);});
    ui->someLayout->addWidget(gameroard);
    if(ships.isEmpty())
        gameroard->initializeShips();
}
placeShipsWidget::~placeShipsWidget()
{
    delete ui;
}

void placeShipsWidget::setShips(QVector<DraggableShip *> ships)
{
    this->ships = ships;
    for (auto ship : ships) {
        ship->setDragablity(true);
    }
    gameroard->setShips(ships);
}

void placeShipsWidget::on_board_changed(GAMECLIP newboard[10][10])
{
    int count = 0;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if(newboard[i][j] == SHIP)
                count++;
        }
    }
    if(count == 20)
    {
        ui->submitButton->setEnabled(true);
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                this->board[i][j] = newboard[i][j];
                this->ships = gameroard->getShips();
            }
        }

    }
    else
        ui->submitButton->setEnabled(false);

}

