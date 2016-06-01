#ifndef WALL_H
#define WALL_H
#include <obstacle.h>

class Wall : public Obstacle
{
public:
    Wall();
    ~Wall();
    virtual bool CanPass();
};

#endif // WALL_H
