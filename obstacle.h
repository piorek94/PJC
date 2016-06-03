#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "iobject.h"

class Obstacle : public IObject
{
protected:
    int X;
    int Y;
    int Width;
    int Height;
public:
    virtual bool CanPass()=0;//after add inherit class it will be pure virtual, it could be only a data not method
    Obstacle();
    ~Obstacle();
    int getX();
    int getY();
    void setX(int _x);
    void setY(int _y);
    int getWidth();
    int getHeight();
    void setWidth(int _width);
    void setHeight(int _height);
};

#endif // OBSTACLE_H
