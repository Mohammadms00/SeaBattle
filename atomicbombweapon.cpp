#include "atomicbombweapon.h"

AtomicBombWeapon::AtomicBombWeapon() {
    this->price = 100;
    this->maximumcount = 1;
<<<<<<< HEAD
    // qDebug()<<QPixmap(":/weapons/images/atomic_bomb.png").rect();
    // setPixmap(QPixmap(":/weapons/images/atomic_bomb.png"));
=======
    qDebug()<<QPixmap(":/weapons/images/atomic_bomb.png").rect();
    setPixmap(QPixmap(":/weapons/images/atomic_bomb.png"));
>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953
}

void AtomicBombWeapon::shoot()
{
    qDebug()<<"use atomicbomb";
}
