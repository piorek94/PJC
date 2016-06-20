#include "creature.h"
#include "board.h"
#include <ctime>
#include <cstdlib>

Creature::Creature(Board *_map, float _speed, int _maxHp, int _width, int _height)
    :Mobile(_speed,_width,_height)
{
    MaxSpeed=_speed;
    MaxHp=_maxHp;
    Hp=_maxHp;
    setStartPosition(_map);
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

void Creature::setSpeed(float _speed)
{
    Speed=_speed;
}

float Creature::getMaxSpeed()
{
    return MaxSpeed;
}

void Creature::Dead()
{
    if(Hp<=0)
    {
        ToRemove=true;
    }else{
        ToRemove=false;
    }
}

bool Creature::collisionCreatureStart(Board *_map)
{
    if(X<=0||Y<=0||Y+Height>=_map->getHeight()||X+Width>=_map->getWidth())
    {
        return true;
    }

    Creature *tmp;
    for(int i=0; i<_map->getNumberOfMobiles();i++)
    {
        tmp=dynamic_cast<Creature*>(_map->getMobile(i));
        if(this!=_map->getMobile(i) && tmp)
        {
            int TopC=_map->getMobile(i)->getY();
            int BotC=TopC+_map->getMobile(i)->getHeight();
            int LefC=_map->getMobile(i)->getX();
            int RigC=LefC+_map->getMobile(i)->getWidth();
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
    this->Dead();
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



void Creature::setStartPosition(Board *_map)
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

