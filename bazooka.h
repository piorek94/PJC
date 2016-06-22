#ifndef BAZOOKA_H
#define BAZOOKA_H
#include "typeweapon.h"

class Bazooka : public TypeWeapon
{
public:
    Bazooka();
    virtual ~Bazooka();
    Bullet* CreateBullet(float _aimX, float _aimY, float _startX, float _startY);
};

#endif // BAZOOKA_H
