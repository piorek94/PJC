#ifndef TYPEWEAPON_H
#define TYPEWEAPON_H
#include "object.h"
#include "bullet.h"

class TypeWeapon : public Object
{
protected:
    int ShootRange;
public:
    TypeWeapon();
    virtual ~TypeWeapon();
    int getShootRange();
    virtual Bullet* CreateBullet(float _aimX, float _aimY, float _startX, float _startY)=0;
};

#endif // TYPEWEAPON_H
