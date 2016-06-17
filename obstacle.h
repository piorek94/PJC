#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "iobject.h"
class Creature;
class Obstacle : public IObject
{
protected:
    float X;
    float Y;
    int Width;
    int Height;
public:
    virtual bool CanPass()=0;
    virtual void affect(Creature *_creature,bool condition)=0;
    Obstacle(float _x, float _y);
    ~Obstacle();
    float getX();
    float getY();
    int getWidth();
    int getHeight();    
};

#endif // OBSTACLE_H
