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
    virtual int getWidth()=0;
    virtual int getHeight()=0;
};

#endif // IOBJECT_H
