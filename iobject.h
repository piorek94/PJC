#ifndef IOBJECT_H
#define IOBJECT_H

#include "isize.h"

class IObject : public ISize
{
public:
    IObject();
    virtual ~IObject();
    virtual float getX()=0;
    virtual float getY()=0;
    virtual void setX(float _x)=0;
    virtual void setY(float _y)=0;
    virtual int getWidth()=0;
    virtual int getHeight()=0;
    virtual void setWidth(int _width)=0;
    virtual void setHeight(int _height)=0;
};

#endif // IOBJECT_H
