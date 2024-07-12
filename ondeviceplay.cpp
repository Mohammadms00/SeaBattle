#include "ondeviceplay.h"


OnDevicePlay::OnDevicePlay(QWidget *parent)
    : QMainWindow(parent)
{
    psw = new placeShipsWidget(this);
    bww = new buyWeaponWidget(this);
    pw = new PlayWidget(this);

    connect(psw,&placeShipsWidget::widgetAccept,this,&OnDevicePlay::placeShipsNext);
    connect(bww,&buyWeaponWidget::goBack,this,&OnDevicePlay::buyWeaponPreviuos);
    connect(bww,&buyWeaponWidget::goNext,this,[=](GAMECLIP board[10][10]){
        pw->setGameBoard(board);
        setState(PLAYING);
    });
    setState(PLACINGSHIPS);
    // ui->verticalLayout
}


void OnDevicePlay::setState(STATE newstate)
{
    if(!psw->isHidden())
        psw->hide();
    if(!bww->isHidden())
        bww->hide();
    if(!pw->isHidden())
        pw->hide();
    QWidget* currentWidget = centralWidget();
    if (currentWidget) {
        currentWidget->setParent(nullptr);
    }
    this->mystate = newstate;
    switch (newstate) {
    case PLACINGSHIPS:
        // psw->setHidden(false);
        // psw->show();
        if (psw) {
            setCentralWidget(psw);
            psw->show();
        } else {
            qWarning() << "placeShipsWidget is not initialized!";
        }
        break;
    case BUYINGWEAPON:
        // bww->setHidden(false);
        // bww->show();
        if (bww) {
            setCentralWidget(bww);
            bww->show();
        } else {
            qWarning() << "buyWeaponWidget is not initialized!";
        }
        break;
    case PLAYING:
        if (pw) {
            setCentralWidget(pw);
            pw->show();
        } else {
            qWarning() << "PlayWidget is not initialized!";
        }
        break;
    }
}

void OnDevicePlay::setUser(User *user)
{
    bww->setUser(user);
}

void OnDevicePlay::placeShipsNext(QVector<DraggableShip *> ships)
{
    // for (int i = 0; i < 10; ++i) {
    //     QString str;
    //     for (int j = 0; j < 10; ++j) {
    //         str += QString::number(board[i][j],2) + " ";
    //     }
    //     qDebug().noquote() << str;
    // }
    // bww->setBoard(board);
    // bww->setHidden(false);
    bww->setShips(ships);
    qDebug()<<"something";
    // this->setCentralWidget(bww);
    setState(BUYINGWEAPON);
}

void OnDevicePlay::buyWeaponPreviuos(QVector<DraggableShip *> ships)
{
    psw->setShips(ships);
    setState(PLACINGSHIPS);
    // psw->setHidden(false);
    qDebug()<<"something";
    // this->setCentralWidget(psw);
}



