#ifndef IMOBILE_H
#define IMOBILE_H

#include "iobject.h"
class Board;
class IMobile : public IObject
{
public:

    IMobile();
    virtual ~IMobile();
    virtual void move(Board *_map)=0;
    virtual void rotate(float _angle)=0;
    virtual float getX()=0;
    virtual float getY()=0;
    virtual void setX(float _x)=0;
    virtual void setY(float _y)=0;
    virtual int getWidth()=0;
    virtual int getHeight()=0;
    virtual void setWidth(int _width)=0;
    virtual void setHeight(int _height)=0;
    virtual bool checkCollisionUp(Board *_map)=0;
    virtual bool checkCollisionDown(Board *_map)=0;
    virtual bool checkCollisionRight(Board *_map)=0;
    virtual bool checkCollisionLeft(Board *_map)=0;
    virtual void setSpeed(float _speed)=0;
    virtual float getSpeed()=0;
};

#endif // IMOBILE_H
