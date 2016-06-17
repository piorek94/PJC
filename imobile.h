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
    virtual float getX()=0;
    virtual float getY()=0;
    virtual int getWidth()=0;
    virtual int getHeight()=0;
    virtual bool checkCollisionUp(Board *_map)=0;
    virtual bool checkCollisionDown(Board *_map)=0;
    virtual bool checkCollisionRight(Board *_map)=0;
    virtual bool checkCollisionLeft(Board *_map)=0;
    virtual void setSpeed(float _speed)=0;
};

#endif // IMOBILE_H
