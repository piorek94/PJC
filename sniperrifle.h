#ifndef SNIPERRIFLE_H
#define SNIPERRIFLE_H
#include "typeweapon.h"

class SniperRifle : public TypeWeapon
{
public:
    SniperRifle();
    virtual ~SniperRifle();
    Bullet* CreateBullet(float _aimX, float _aimY, float _startX, float _startY);
};

#endif // SNIPERRIFLE_H
