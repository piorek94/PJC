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

float Obstacle::getX()
{
    return X;
}

float Obstacle::getY()
{
    return Y;
}

int Obstacle::getWidth()
{
    return Width;
}

int Obstacle::getHeight()
{
    return Height;
}
