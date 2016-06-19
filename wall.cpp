#include "wall.h"
#include "creature.h"

Wall::Wall(float _x, float _y)
    : Obstacle(_x,_y)
{

}

Wall::~Wall()
{

}

void Wall::affect(Creature *_creature, bool condition)
{

}
