#include "wall.h"

Wall::Wall(int _x, int _y)
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
