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
    Creature(Board *_map, float _speed, int _maxHp);
    virtual ~Creature();
    virtual void move(Board *_map)=0;
    virtual void rotate(float _angle)=0;
    virtual void shoot()=0;
    virtual void setWeapon()=0;
    void checkField(Board *_map);
    void setPosition(Board *_map);
    float getX();
    float getY();
    void setX(float _x);
    void setY(float _y);
    int getWidth();
    int getHeight();
    void setWidth(int _width);
    void setHeight(int _height);
    bool isDead();
    int getHp();
    void setHp(int _hp);
    int getMaxHp();
    void setMaxHp(int _maxhp);
    void setSpeed(float _speed);
    float getSpeed();
    void setMaxSpeed(float _maxSpeed);
    float getMaxSpeed();
};

#endif // CREATURE_H
