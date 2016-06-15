#include "wall.h"

Wall::Wall(float _x, float _y)
    : Obstacle(_x,_y)
{

}
Wall::~Wall()
{

}
bool Wall::CanPass()
{
    return false;
}

void Wall::affect(Creature *_creature, bool condition)
{

}
