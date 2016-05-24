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
    bool CanPass;
public:
    Obstacle();
    ~Obstacle();
    int getX();
    int getY();
    void setX(int);
    void setY(int);
    int getWidth();
    int getHeight();
    void setWidth(int);
    void setHeight(int);
};

#endif // OBSTACLE_H
