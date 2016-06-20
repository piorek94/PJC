#ifndef CREATURE_H
#define CREATURE_H

#include "mobile.h"

class Creature : public Mobile
{
protected:
    int Hp;
    int MaxHp;
    float MaxSpeed;
    void setStartPosition(Board *_map);
    bool collisionCreatureStart(Board *_map);
    void Dead();
public:
    Creature(Board *_map, float _speed, int _maxHp, int _width, int _height);
    virtual ~Creature();
    virtual void shoot()=0;
    virtual void setWeapon()=0;
    virtual void move(Board *_map)=0;
    void checkField(Board *_map);
    int getHp();
    void setHp(int _hp);
    int getMaxHp();
    void setSpeed(float _speed);
    float getMaxSpeed();
};

#endif // CREATURE_H
