#include "observationweapon.h"

ObservationWeapon::ObservationWeapon() {
    this->price = 5;
<<<<<<< HEAD
    this->maximumcount = 1;
    // qDebug()<<QPixmap(":/weapons/images/observation.png").rect();
    // setPixmap(QPixmap(":/weapons/images/observation.png"));
=======
    this->maximumcount = 5;
    qDebug()<<QPixmap(":/weapons/images/observation.png").rect();
    setPixmap(QPixmap(":/weapons/images/observation.png"));
>>>>>>> 9036e3d5a322f2aa44cfb909356e74238e649953
}

void ObservationWeapon::shoot()
{
    qDebug()<<"use observation";
}
