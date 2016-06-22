#ifndef BAZOOKA_H
#define BAZOOKA_H
#include "typeweapon.h"

class Bazooka : public TypeWeapon
{
public:
    Bazooka();
    virtual ~Bazooka();
    Bullet* CreateBullet();
};

#endif // BAZOOKA_H
