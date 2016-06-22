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
    virtual Bullet* CreateBullet()=0;
};

#endif // TYPEWEAPON_H
