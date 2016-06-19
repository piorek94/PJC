#ifndef OBSTACLE_H
#define OBSTACLE_H

#include "object.h"
class Creature;
class Obstacle : public Object
{
public:
    Obstacle(float _x, float _y);
    virtual ~Obstacle();
    virtual bool CanPass();
    virtual void affect(Creature *_creature,bool condition)=0;   
};

#endif // OBSTACLE_H
