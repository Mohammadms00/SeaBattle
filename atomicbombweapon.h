#ifndef ATOMICBOMBWEAPON_H
#define ATOMICBOMBWEAPON_H

#include "weapon.h"

class AtomicBombWeapon : public Weapon
{
public:
    AtomicBombWeapon();
    void shoot() override;
};

#endif // ATOMICBOMBWEAPON_H
