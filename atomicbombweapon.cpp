#include "atomicbombweapon.h"

AtomicBombWeapon::AtomicBombWeapon() {
    this->price = 100;
    this->maximumcount = 1;
    // qDebug()<<QPixmap(":/weapons/images/atomic_bomb.png").rect();
    // setPixmap(QPixmap(":/weapons/images/atomic_bomb.png"));
}

void AtomicBombWeapon::shoot()
{
    qDebug()<<"use atomicbomb";
}
