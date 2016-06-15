#ifndef WALL_H
#define WALL_H
#include "obstacle.h"

class Wall : public Obstacle
{
public:
    Wall(float _x, float _y);
    ~Wall();
    virtual bool CanPass();
    virtual void affect(Creature *_creature, bool condition);
};

#endif // WALL_H
