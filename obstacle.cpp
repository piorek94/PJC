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

void Obstacle::setX(float _x)
{
    X=_x;
}

void Obstacle::setY(float _y)
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
