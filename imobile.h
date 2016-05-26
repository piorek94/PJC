#ifndef IMOBILE_H
#define IMOBILE_H

#include "iobject.h"

class IMobile : public IObject
{
public:
    IMobile();
    virtual ~IMobile();
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
};

#endif // IMOBILE_H
