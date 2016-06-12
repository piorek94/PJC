#include "creature.h"
#include "board.h"


Creature::Creature(Board *_map, float _speed, int _maxHp)
{
    setSpeed(_speed);
    MaxHp=_maxHp;
    Hp=_maxHp;
    Height=30;//jesli textury
    Width=30;//jesli textury
    setPosition(_map);
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

void Creature::setSpeed(float _speed)
{
    if(_speed<0)
    {
        _speed=-_speed;
    }
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

float Creature::getX()
{
    return X;
}

float Creature::getY()
{
    return Y;
}

void Creature::setX(float _x)
{
    X=_x;
}

void Creature::setY(float _y)
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

bool Creature::checkCollisionUp(Board *_map)
{
    bool collision=false;
    for(int i=0;i<_map->getNumberOfObstacle();i++)
    {
        if(_map->getObstacle(i)->CanPass()==false)
        {
            int TopO=_map->getObstacle(i)->getY();
            int BotO=TopO+_map->getObstacle(i)->getHeight();
            int LefO=_map->getObstacle(i)->getX();
            int RigO=LefO+_map->getObstacle(i)->getWidth();
            if(((Y-Speed<=BotO && Y-Speed>=TopO) && !(X+Width<=LefO || X>=RigO)) || (Y-Speed<=0))
            {
                return true;
            }
        }
    }
    for(int i=0; i<_map->getNumberOfCreature();i++)
    {
        if(this!=_map->getCreature(i))
        {
            int TopC=_map->getCreature(i)->getY();
            int BotC=TopC+_map->getCreature(i)->getHeight();
            int LefC=_map->getCreature(i)->getX();
            int RigC=LefC+_map->getCreature(i)->getWidth();
            if((Y-Speed<=BotC && Y-Speed>=TopC) && !(X+Width<=LefC || X>=RigC))
            {
                return true;
            }
        }
    }
    return collision;
}

bool Creature::checkCollisionDown(Board *_map)
{
    bool collision=false;
    for(int i=0;i<_map->getNumberOfObstacle();i++)
    {
        if(_map->getObstacle(i)->CanPass()==false)
        {
            int TopO=_map->getObstacle(i)->getY();
            int BotO=TopO+_map->getObstacle(i)->getHeight();
            int LefO=_map->getObstacle(i)->getX();
            int RigO=LefO+_map->getObstacle(i)->getWidth();
            if(((Y+Height+Speed>=TopO && Y+Height+Speed<=BotO) && !(X+Width<=LefO || X>=RigO)) || (Y+Height+Speed>=_map->getHeight()))
            {
                return true;
            }
        }
    }
    for(int i=0; i<_map->getNumberOfCreature();i++)
    {
        if(this!=_map->getCreature(i))
        {
            int TopC=_map->getCreature(i)->getY();
            int BotC=TopC+_map->getCreature(i)->getHeight();
            int LefC=_map->getCreature(i)->getX();
            int RigC=LefC+_map->getCreature(i)->getWidth();
            if((Y+Height+Speed>=TopC && Y+Height+Speed<=BotC) && !(X+Width<=LefC || X>=RigC))
            {
                return true;
            }
        }
    }
    return collision;
}

bool Creature::checkCollisionLeft(Board *_map)
{
    bool collision=false;
    for(int i=0;i<_map->getNumberOfObstacle();i++)
    {
        if(_map->getObstacle(i)->CanPass()==false)
        {
            int TopO=_map->getObstacle(i)->getY();
            int BotO=TopO+_map->getObstacle(i)->getHeight();
            int LefO=_map->getObstacle(i)->getX();
            int RigO=LefO+_map->getObstacle(i)->getWidth();
            if(((X-Speed<=RigO && X-Speed>=LefO) && !(Y+Height<=TopO || Y>=BotO)) || (X-Speed<=0))
            {
                return true;
            }
        }
    }
    for(int i=0; i<_map->getNumberOfCreature();i++)
    {
        if(this!=_map->getCreature(i))
        {
            int TopC=_map->getCreature(i)->getY();
            int BotC=TopC+_map->getCreature(i)->getHeight();
            int LefC=_map->getCreature(i)->getX();
            int RigC=LefC+_map->getCreature(i)->getWidth();
            if((X-Speed<=RigC && X-Speed>=LefC) && !(Y+Height<=TopC || Y>=BotC))
            {
                return true;
            }
        }
    }
    return collision;
}


bool Creature::checkCollisionRight(Board *_map)
{
    bool collision=false;
    for(int i=0;i<_map->getNumberOfObstacle();i++)
    {
        if(_map->getObstacle(i)->CanPass()==false)
        {
            int TopO=_map->getObstacle(i)->getY();
            int BotO=TopO+_map->getObstacle(i)->getHeight();
            int LefO=_map->getObstacle(i)->getX();
            int RigO=LefO+_map->getObstacle(i)->getWidth();
            if(((X+Width+Speed>=LefO && X+Width+Speed<=RigO) && !(Y+Height<=TopO || Y>=BotO)) || (X+Width+Speed>=_map->getWidth()))
            {
                return true;
            }
        }
    }
    for(int i=0; i<_map->getNumberOfCreature();i++)
    {
        if(this!=_map->getCreature(i))
        {
            int TopC=_map->getCreature(i)->getY();
            int BotC=TopC+_map->getCreature(i)->getHeight();
            int LefC=_map->getCreature(i)->getX();
            int RigC=LefC+_map->getCreature(i)->getWidth();
            if((X+Width+Speed>=LefC && X+Width+Speed<=RigC) && !(Y+Height<=TopC || Y>=BotC) || (X==LefC && Y==TopC))//ostatnie lub zeby na sobie nie były
            {
                return true;
            }
        }
    }
    return collision;
}


void Creature::setPosition(Board *_map)
{
    bool success=false;
    srand(time(0));
    while(!success)
    {
        X=rand()%(_map->getWidth());
        Y=rand()%(_map->getHeight());
        if(!checkCollisionDown(_map) && !checkCollisionLeft(_map) && !checkCollisionRight(_map) && !checkCollisionUp(_map))
        {
            success=true;
        }
    }
}
