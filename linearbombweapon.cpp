#include "linearbombweapon.h"

LinearBombWeapon::LinearBombWeapon() {
    this->price = 12;
    this->maximumcount = 2;
<<<<<<< HEAD
    // qDebug()<<QPixmap(":/weapons/images/linear_bomb.png").rect();
    // setPixmap(QPixmap(":/weapons/images/linear_bomb.png"));
=======
    qDebug()<<QPixmap(":/weapons/images/linear_bomb.png").rect();
    setPixmap(QPixmap(":/weapons/images/linear_bomb.png"));
>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953
}

void LinearBombWeapon::shoot()
{
    qDebug()<<"use linearbomb";
}
