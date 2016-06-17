#ifndef CREATURE_H
#define CREATURE_H

#include "imobile.h"
#include <ctime>
#include <cstdlib>

class Creature : public IMobile
{
protected:
    int Hp;
    int MaxHp;
    float X;
    float Y;
    int Height;
    int Width;
    float Speed;
    float MaxSpeed;
    bool checkCollisionUp(Board *_map);
    bool checkCollisionDown(Board *_map);
    bool checkCollisionRight(Board *_map);
    bool checkCollisionLeft(Board *_map);
    bool collisionCreatureStart(Board *_map);
public:
    Creature(Board *_map, float _speed, int _maxHp, int _width, int _height);
    virtual ~Creature();
    virtual void move(Board *_map)=0;
    virtual void shoot()=0;
    virtual void setWeapon()=0;
    void checkField(Board *_map);
    void setPosition(Board *_map);
    float getX();
    float getY();
    int getWidth();
    int getHeight();
    bool isDead();
    int getHp();
    void setHp(int _hp);
    int getMaxHp();
    void setSpeed(float _speed);
    float getMaxSpeed();
};

#endif // CREATURE_H
