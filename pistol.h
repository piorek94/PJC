#ifndef PISTOL_H
#define PISTOL_H
#include "typeweapon.h"

class Pistol : public TypeWeapon
{
public:
    Pistol();
    virtual ~Pistol();
    Bullet* CreateBullet();
};

#endif // PISTOL_H
