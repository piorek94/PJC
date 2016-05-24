#ifndef IOBJECT_H
#define IOBJECT_H

#include "isize.h"

class IObject : public ISize
{
public:
    IObject();
    virtual ~IObject();
    virtual int getX()=0;
    virtual int getY()=0;
    virtual void setX(int)=0;
    virtual void setY(int)=0;
    virtual int getWidth()=0;
    virtual int getHeight()=0;
    virtual void setWidth(int)=0;
    virtual void setHeight(int)=0;
};

#endif // IOBJECT_H
