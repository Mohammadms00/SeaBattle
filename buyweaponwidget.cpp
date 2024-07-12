#include "buyweaponwidget.h"
#include "ui_buyweaponwidget.h"

#include "database.h"

buyWeaponWidget::buyWeaponWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::buyWeaponWidget)
{
    ui->setupUi(this);
    connect(ui->backButton,&QPushButton::clicked,this,[=](){ emit goBack(this->ships);});
    connect(ui->submitButton,&QPushButton::clicked,this,[=](){ emit goNext(this->board);Database().UpdateUser(*user);});
    gameroard = new GameBoard();
    connect(gameroard,&GameBoard::boardChanged,this,[=](GAMECLIP newboard[10][10]){
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                this->board[i][j] = newboard[i][j];
            }
        }
    });
    ui->verticalLayout->addWidget(gameroard);
}

buyWeaponWidget::~buyWeaponWidget()
{
    delete ui;
}

void buyWeaponWidget::setShips(QVector<DraggableShip *> ships)
{
    this->ships = ships;
    for (auto ship : ships) {
        ship->setDragablity(false);
    }
    gameroard->setShips(ships);
    gameroard->resetWeapom();
}

void buyWeaponWidget::setUser(User *user)
{
    this->user = user;
}


void buyWeaponWidget::on_pushButton_3_clicked()
{
    if(user->getMoney() > 5)
    {
        gameroard->addMine();
        user->setMoney(user->getMoney()-5);
    }
}


void buyWeaponWidget::on_pushButton_clicked()
{
    if(user->getMoney()>10)
    {
        gameroard->addAirDefense();
        user->setMoney(user->getMoney()-10);
    }


}


void buyWeaponWidget::on_pushButton_2_clicked()
{
    if(linearbombcount < 2 && user->getMoney() >= 12)
    {
        user->setMoney(user->getMoney()-12);
        linearbombcount++;
    }
}


void buyWeaponWidget::on_pushButton_5_clicked()
{
    if(radarcount == 0 && user->getMoney() >= 5)
    {
        user->setMoney(user->getMoney()-5);
        radarcount++;
    }
}


void buyWeaponWidget::on_pushButton_4_clicked()
{
    if(atomicbombcount == 0 && user->getMoney() >= 100)
    {
        user->setMoney(user->getMoney()-100);
        radarcount++;
    }
}

