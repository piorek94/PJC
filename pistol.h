#ifndef PISTOL_H
#define PISTOL_H
#include "typeweapon.h"

class Pistol : public TypeWeapon
{
public:
    Pistol();
    virtual ~Pistol();
    Bullet* CreateBullet(float _aimX, float _aimY, float _startX, float _startY);
};

#endif // PISTOL_H
