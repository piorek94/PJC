#ifndef IMOBILE_H
#define IMOBILE_H

#include "iobject.h"

class IMobile : public IObject
{
public:
    IMobile();
    virtual ~IMobile();
    virtual void move(int, int)=0;
    virtual void rotate(double)=0;
    virtual int getX()=0;
    virtual int getY()=0;
    virtual void setX(int)=0;
    virtual void setY(int)=0;
    virtual int getWidth()=0;
    virtual int getHeight()=0;
    virtual void setWidth(int)=0;
    virtual void setHeight(int)=0;
};

#endif // IMOBILE_H
