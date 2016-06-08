#include "creature.h"
#include "board.h"

Creature::Creature(Board *_map)
{
    Map=_map;
    setSpeed(1);
    //tutaj musi byc cos co samo bedzie ustawiało ludka
    X=10;
    Y=70;
//    Height=30;//jesli textury
//    Width=30;//jesli textury
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

void Creature::setSpeed(int _speed)
{
    if(_speed<0)
    {
        _speed=-_speed;
    }
    Speed=_speed;
}

int Creature::getSpeed()
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

bool Creature::checkCollisionUp()
{
    bool collision=false;
    for(int i=0;i<Map->getNumberOfObstacle();i++)
    {
        if(Map->getObstacle(i)->CanPass()==false)
        {
            int TopO=Map->getObstacle(i)->getY();
            int BotO=TopO+Map->getObstacle(i)->getHeight();
            int LefO=Map->getObstacle(i)->getX();
            int RigO=LefO+Map->getObstacle(i)->getWidth();
            if(((Y-Speed<=BotO && Y-Speed>=TopO) && !(X+Width<=LefO || X>=RigO)) || (Y-Speed<=0))
            {
                return true;
            }
        }
    }
    for(int i=0; i<Map->getNumberOfCreature();i++)
    {
        if(this!=Map->getCreature(i))
        {
            int TopC=Map->getCreature(i)->getY();
            int BotC=TopC+Map->getCreature(i)->getHeight();
            int LefC=Map->getCreature(i)->getX();
            int RigC=LefC+Map->getCreature(i)->getWidth();
            if((Y-Speed<=BotC && Y-Speed>=TopC) && !(X+Width<=LefC || X>=RigC))
            {
                return true;
            }
        }
    }
    return collision;
}

bool Creature::checkCollisionDown()
{
    bool collision=false;
    for(int i=0;i<Map->getNumberOfObstacle();i++)
    {
        if(Map->getObstacle(i)->CanPass()==false)
        {
            int TopO=Map->getObstacle(i)->getY();
            int BotO=TopO+Map->getObstacle(i)->getHeight();
            int LefO=Map->getObstacle(i)->getX();
            int RigO=LefO+Map->getObstacle(i)->getWidth();
            if(((Y+Height+Speed>=TopO && Y+Height+Speed<=BotO) && !(X+Width<=LefO || X>=RigO)) || (Y+Height+Speed>=Map->getHeight()))
            {
                return true;
            }
        }
    }
    for(int i=0; i<Map->getNumberOfCreature();i++)
    {
        if(this!=Map->getCreature(i))
        {
            int TopC=Map->getCreature(i)->getY();
            int BotC=TopC+Map->getCreature(i)->getHeight();
            int LefC=Map->getCreature(i)->getX();
            int RigC=LefC+Map->getCreature(i)->getWidth();
            if((Y+Height+Speed>=TopC && Y+Height+Speed<=BotC) && !(X+Width<=LefC || X>=RigC))
            {
                return true;
            }
        }
    }
    return collision;
}

bool Creature::checkCollisionLeft()
{
    bool collision=false;
    for(int i=0;i<Map->getNumberOfObstacle();i++)
    {
        if(Map->getObstacle(i)->CanPass()==false)
        {
            int TopO=Map->getObstacle(i)->getY();
            int BotO=TopO+Map->getObstacle(i)->getHeight();
            int LefO=Map->getObstacle(i)->getX();
            int RigO=LefO+Map->getObstacle(i)->getWidth();
            if(((X-Speed<=RigO && X-Speed>=LefO) && !(Y+Height<=TopO || Y>=BotO)) || (X-Speed<=0))
            {
                return true;
            }
        }
    }
    for(int i=0; i<Map->getNumberOfCreature();i++)
    {
        if(this!=Map->getCreature(i))
        {
            int TopC=Map->getCreature(i)->getY();
            int BotC=TopC+Map->getCreature(i)->getHeight();
            int LefC=Map->getCreature(i)->getX();
            int RigC=LefC+Map->getCreature(i)->getWidth();
            if((X-Speed<=RigC && X-Speed>=LefC) && !(Y+Height<=TopC || Y>=BotC))
            {
                return true;
            }
        }
    }
    return collision;

}bool Creature::checkCollisionRight()
{
    bool collision=false;
    for(int i=0;i<Map->getNumberOfObstacle();i++)
    {
        if(Map->getObstacle(i)->CanPass()==false)
        {
            int TopO=Map->getObstacle(i)->getY();
            int BotO=TopO+Map->getObstacle(i)->getHeight();
            int LefO=Map->getObstacle(i)->getX();
            int RigO=LefO+Map->getObstacle(i)->getWidth();
            if(((X+Width+Speed>=LefO && X+Width+Speed<=RigO) && !(Y+Height<=TopO || Y>=BotO)) || (X+Width+Speed>=Map->getWidth()))
            {
                return true;
            }
        }
    }
    for(int i=0; i<Map->getNumberOfCreature();i++)
    {
        if(this!=Map->getCreature(i))
        {
            int TopC=Map->getCreature(i)->getY();
            int BotC=TopC+Map->getCreature(i)->getHeight();
            int LefC=Map->getCreature(i)->getX();
            int RigC=LefC+Map->getCreature(i)->getWidth();
            if((X+Width+Speed>=LefC && X+Width+Speed<=RigC) && !(Y+Height<=TopC || Y>=BotC))
            {
                return true;
            }
        }
    }
    return collision;
}
