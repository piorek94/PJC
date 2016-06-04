#include "obstacle.h"

Obstacle::Obstacle(int _x, int _y)
{
    X=_x;
    Y=_y;
}
Obstacle::~Obstacle()
{

}

int Obstacle::getX()
{
    return X;
}

int Obstacle::getY()
{
    return Y;
}

void Obstacle::setX(int _x)
{
    X=_x;
}

void Obstacle::setY(int _y)
{
    Y=_y;
}

int Obstacle::getWidth()
{
    return Width;
}

int Obstacle::getHeight()
{
    return Height;
}

void Obstacle::setWidth(int _width)
{
    Width=_width;
}

void Obstacle::setHeight(int _height)
{
    Height=_height;
}
