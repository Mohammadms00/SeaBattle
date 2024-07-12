#ifndef OBSERVATIONWEAPON_H
#define OBSERVATIONWEAPON_H

#include "weapon.h"

class ObservationWeapon : public Weapon
{
public:
    ObservationWeapon();
    void shoot() override;
};

#endif // OBSERVATIONWEAPON_H
