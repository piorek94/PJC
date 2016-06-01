#include "creature.h"

Creature::Creature()
{

}

Creature::~Creature()
{

}

int Creature::getHp()
{
    return Hp;
}

void Creature:: setHp(int _hp)
{
    Hp=_hp;
}

int Creature::getMaxHp()
{
    return MaxHp;
}

void Creature::setMaxHp(int _maxhp)
{
    MaxHp=_maxhp;
}

void Creature::setName(std::string _name)
{
    Name=_name;
}

std::string Creature::getName()
{
    return Name;
}

void Creature::setSpeed(float _speed)
{
    Speed=_speed;
}

float Creature::getSpeed()
{
    return Speed;
}

bool Creature::isDead()
{
    if(Hp<=0)
    {
        return true;
    }else{
        return false;
    }
}

int Creature::getX()
{
    return X;
}

int Creature::getY()
{
    return Y;
}

void Creature::setX(int _x)
{
    X=_x;
}

void Creature::setY(int _y)
{
    Y=_y;
}

int Creature::getWidth()
{
    return Width;
}

int Creature::getHeight()
{
    return Height;
}

void Creature::setWidth(int _width)
{
    Width=_width;
}

void Creature::setHeight(int _height)
{
    Height=_height;
}
