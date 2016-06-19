#ifndef MOBILE_H
#define MOBILE_H
#include "imobile.h"
#include "object.h"

class Mobile : public IMobile, public Object
{
protected:
    float Speed;
public:
    Mobile(float _speed);
    virtual ~Mobile();
};
//ta kalsa ma przejac czesc funkcji creature ktore sa wspolne dla pocisku
#endif // MOBILE_H

//protected:
//    int Hp;
//    int MaxHp;
//    float MaxSpeed;
//    bool collisionCreatureStart(Board *_map);
//public:
//    Creature(Board *_map, float _speed, int _maxHp, int _width, int _height);*
//    virtual ~Creature();*
//    virtual void move(Board *_map)=0;*
//    virtual void shoot()=0;---
//    virtual void setWeapon()=0;---
//    void checkField(Board *_map);---
//    void setStartPosition(Board *_map);*
//    bool isDead();---
//    int getHp();---
//    void setHp(int _hp);---
//    int getMaxHp();---
//    void setSpeed(float _speed);---
//    float getMaxSpeed();----
