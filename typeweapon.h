#ifndef TYPEWEAPON_H
#define TYPEWEAPON_H
#include "object.h"

class TypeWeapon : public Object
{
protected:
    int ShootRange;
public:
    TypeWeapon();
    virtual ~TypeWeapon();
    int getShootRange();
};

#endif // TYPEWEAPON_H
