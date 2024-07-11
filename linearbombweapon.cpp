#include "linearbombweapon.h"

LinearBombWeapon::LinearBombWeapon() {
    this->price = 12;
    this->maximumcount = 2;
    qDebug()<<QPixmap(":/weapons/images/linear_bomb.png").rect();
    setPixmap(QPixmap(":/weapons/images/linear_bomb.png"));
}

void LinearBombWeapon::shoot()
{
    qDebug()<<"use linearbomb";
}
