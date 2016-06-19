#include "obstacle.h"

Obstacle::Obstacle(float _x, float _y)
{
    X=_x;
    Y=_y;
    Height=60;
    Width=60;
}

Obstacle::~Obstacle()
{

}

bool Obstacle::CanPass()
{
    return false;
}
