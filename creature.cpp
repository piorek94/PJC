#include "creature.h"
#include "board.h"


Creature::Creature(Board *_map, float _speed, int _maxHp)
{
    setMaxSpeed(_speed);
    Speed=MaxSpeed;
    MaxHp=_maxHp;
    Hp=_maxHp;
    Height=30;
    Width=20;
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
    Speed=_speed;
}

float Creature::getSpeed()
{
    return Speed;
}

void Creature::setMaxSpeed(float _maxSpeed)
{
    if(_maxSpeed<0)
    {
        _maxSpeed=-_maxSpeed;
    }
    MaxSpeed=_maxSpeed;
}

float Creature::getMaxSpeed()
{
    return MaxSpeed;
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
    return false;
}

bool Creature::checkCollisionDown(Board *_map)
{
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
    return false;
}

bool Creature::checkCollisionLeft(Board *_map)
{
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
    return false;
}


bool Creature::checkCollisionRight(Board *_map)
{
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
            if(((X+Width+Speed>=LefC && X+Width+Speed<=RigC) && !(Y+Height<=TopC || Y>=BotC)))
            {
                return true;
            }
        }
    }
    return false;
}

bool Creature::collisionCreatureStart(Board *_map)
{
    if(X<=0||Y<=0||Y+Height>=_map->getHeight()||X+Width>=_map->getWidth())
    {
        return true;
    }
    for(int i=0; i<_map->getNumberOfCreature();i++)
    {
        if(this!=_map->getCreature(i))
        {
            int TopC=_map->getCreature(i)->getY();
            int BotC=TopC+_map->getCreature(i)->getHeight();
            int LefC=_map->getCreature(i)->getX();
            int RigC=LefC+_map->getCreature(i)->getWidth();
            if(!(X>=RigC||X+Width<=LefC||Y>=BotC||Y+Height<=TopC))
            {
                return true;
            }
        }
    }
    for(int i=0;i<_map->getNumberOfObstacle();i++)
    {
        if(_map->getObstacle(i)->CanPass()==false)
        {
            int TopO=_map->getObstacle(i)->getY();
            int BotO=TopO+_map->getObstacle(i)->getHeight();
            int LefO=_map->getObstacle(i)->getX();
            int RigO=LefO+_map->getObstacle(i)->getWidth();
            if(!(X>=RigO||X+Width<=LefO||Y>=BotO||Y+Height<=TopO))
            {
                return true;
            }
        }
    }
    return false;
}

void Creature::checkField(Board *_map)
{
    int X_c=X+Width/2;
    int Y_c=Y+Height/2;
    bool condition=false;
    for(int i=0;i<_map->getNumberOfObstacle();i++)
    {
        int TopO=_map->getObstacle(i)->getY();
        int BotO=TopO+_map->getObstacle(i)->getHeight();
        int LefO=_map->getObstacle(i)->getX();
        int RigO=LefO+_map->getObstacle(i)->getWidth();
        if( ( X_c>=LefO && X_c<=RigO ) && ( Y_c>=TopO && Y_c<=BotO ) )
        {
            condition=true;
            _map->getObstacle(i)->affect(this,condition);
            return;
        }
        else
        {
            condition=false;
            _map->getObstacle(i)->affect(this,condition);
        }
    }
}



void Creature::setPosition(Board *_map)
{
    bool success=false;
    srand(time(0));
    while(!success)
    {
        X=rand()%(_map->getWidth());
        Y=rand()%(_map->getHeight());
        if(!collisionCreatureStart(_map))
        {
            success=true;
        }
    }
}

