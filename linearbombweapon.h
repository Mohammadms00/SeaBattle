#ifndef LINEARBOMBWEAPON_H
#define LINEARBOMBWEAPON_H

#include "weapon.h"

class LinearBombWeapon : public Weapon
{
public:
    LinearBombWeapon();
    void shoot() override;
};

#endif // LINEARBOMBWEAPON_H
