#include "airdefenseweapon.h"

AirDefenseWeapon::AirDefenseWeapon() {
    this->price = 10;
    this->maximumcount = 3;
    qDebug()<<QPixmap(":/weapons/images/air_defence.png").rect();
    setPixmap(QPixmap(":/weapons/images/air_defence.png"));
}

void AirDefenseWeapon::shoot()
{
    qDebug()<<"use airdefense";
}
