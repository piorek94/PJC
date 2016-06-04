#ifndef WALL_H
#define WALL_H
#include "obstacle.h"

class Wall : public Obstacle
{
public:
    Wall(int _x, int _y);
    ~Wall();
    virtual bool CanPass();
};

#endif // WALL_H
