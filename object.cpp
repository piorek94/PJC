#include "object.h"

Object::Object()
{
    X=0;
    Y=0;
    Width=0;
    Height=0;
}

Object::~Object()
{

}

float Object::getX()
{
    return X;
}

float Object::getY()
{
    return Y;
}

int Object::getWidth()
{
    return Width;
}

int Object::getHeight()
{
    return Height;
}
