#ifndef AIRDEFENSEWEAPON_H
#define AIRDEFENSEWEAPON_H

#include "weapon.h"

class AirDefenseWeapon : public Weapon
{
public:
    AirDefenseWeapon();
    void shoot() override;
};

#endif // AIRDEFENSEWEAPON_H
