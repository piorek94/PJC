#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include "imobile.h"

class Creature : public IMobile
{
protected:
    int Hp;
    int MaxHp;
    int X;
    int Y;
    int Height;
    int Width;
    std::string Name;
    float Speed;
public:
    Creature();
    virtual ~Creature();
    virtual void move()=0;
    virtual void rotate(double _angle)=0;
    virtual int getX()=0;
    virtual int getY()=0;
    virtual void setX(int _x)=0;
    virtual void setY(int _y)=0;
    virtual int getWidth()=0;
    virtual int getHeight()=0;
    virtual void setWidth(int _width)=0;
    virtual void setHeight(int _height)=0;
    virtual void shoot()=0;
    virtual void setWeapon()=0;
    bool isDead();
    int getHp();
    void setHp(int _hp);
    int getMaxHp();
    void setMaxHp(int _maxhp);
    void setName(std::string _name);
    std::string getName();
    void setSpeed(float _speed);
    float getSpeed();
};

#endif // CREATURE_H
