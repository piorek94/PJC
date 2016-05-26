#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include "imobile.h"

class Creature : public IMobile
{
public:
    Creature();
    virtual ~Creature();
    std::string name;
    float speed;
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
    virtual bool isDeat()=0;
    virtual void setWeapon()=0;


};

#endif // CREATURE_H
