#ifndef CREATURE_H
#define CREATURE_H

#include "mobile.h"
#include "typeweapon.h"

class Creature : public Mobile
{
    void setStartPosition(Board *_map);
    bool collisionCreatureStart(Board *_map);
    int Hp;
    int MaxHp;
    float MaxSpeed;
    void Dead();
protected:
    TypeWeapon* Weapon;
public:
    Creature(Board *_map, float _speed, int _maxHp, int _width, int _height);
    virtual ~Creature();
    virtual void shoot(Board *_map)=0;
    virtual void move(Board *_map)=0;
    void checkField(Board *_map);
    int getHp();
    void setHp(int _hp);
    int getMaxHp();
    void setSpeed(float _speed);
    float getMaxSpeed();
    TypeWeapon* getWeponPtr();
};

#endif // CREATURE_H
