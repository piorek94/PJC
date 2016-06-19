#ifndef OBJECT_H
#define OBJECT_H
#include "iobject.h"

class Object : public IObject
{
protected:
    float X;
    float Y;
    int Width;
    int Height;
public:
    Object();
    virtual ~Object();
    float getX();
    float getY();
    int getWidth();
    int getHeight();
};

#endif // OBJECT_H
