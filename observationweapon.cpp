#include "observationweapon.h"

ObservationWeapon::ObservationWeapon() {
    this->price = 5;
    this->maximumcount = 5;
    qDebug()<<QPixmap(":/weapons/images/observation.png").rect();
    setPixmap(QPixmap(":/weapons/images/observation.png"));
}

void ObservationWeapon::shoot()
{
    qDebug()<<"use observation";
}
