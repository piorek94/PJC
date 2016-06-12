#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "iobject.h"
class Obstacle : public IObject
{
protected:
    float X;
    float Y;
    int Width;
    int Height;
public:
    virtual bool CanPass()=0;
    Obstacle(float _x, float _y);
    ~Obstacle();
    float getX();
    float getY();
    void setX(float _x);
    void setY(float _y);
    int getWidth();
    int getHeight();
    void setWidth(int _width);
    void setHeight(int _height);
};

#endif // OBSTACLE_H
