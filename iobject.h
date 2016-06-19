#ifndef IOBJECT_H
#define IOBJECT_H

class IObject
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
