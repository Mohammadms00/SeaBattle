#include "observationweapon.h"

ObservationWeapon::ObservationWeapon() {
    this->price = 5;
    this->maximumcount = 1;
    // qDebug()<<QPixmap(":/weapons/images/observation.png").rect();
    // setPixmap(QPixmap(":/weapons/images/observation.png"));
}

void ObservationWeapon::shoot()
{
    qDebug()<<"use observation";
}
