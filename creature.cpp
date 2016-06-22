#include "creature.h"
#include "board.h"
#include "bullet.h"
#include <ctime>
#include <cstdlib>

Creature::Creature(Board *_map, float _speed, int _maxHp, int _width, int _height)
    :Mobile(_speed,_width,_height)
{
    Weapon=NULL;
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

    float X_c=X+Width/2;
    float Y_c=Y+Height/2;
    Object *obj;
    for(int i=0; i<_map->getNumberOfMobiles();i++)
    {
        obj=_map->getMobile(i);

            if(isOn(X_c,Y_c,obj))
            {
                obj=NULL;
                return true;
            }
    }

    for(int i=0;i<_map->getNumberOfObstacle();i++)
    {
        if(_map->getObstacle(i)->CanPass()==false)
        {
            obj=_map->getObstacle(i);

                if(isOn(X_c,Y_c,obj))
                {
                    obj=NULL;
                    return true;
                }
        }
    }
    return false;
}

void Creature::checkField(Board *_map)
{
    this->Dead();
    float X_c=X+Width/2;
    float Y_c=Y+Height/2;
    bool condition=false;
    Object *obj=NULL;
    //w razie jakby tamto nie działało z bulletów reducehp
//    Bullet *bull;
//    for(int i=0;i<_map->getNumberOfMobiles();i++)
//    {
//        obj=_map->getMobile(i);
//        if( this->isOn(X_c,Y_c,obj) )
//        {
//            bull=dynamic_cast<Bullet*>(_map->getMobile(i));
//            if(bull)
//            {
//                bull->reduceHp(this);
//                _map->removeMobile(i);
//            }
//        }
//    }
    for(int i=0;i<_map->getNumberOfObstacle();i++)
    {
        obj=_map->getObstacle(i);

        if( this->isOn(X_c,Y_c,obj) )
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

TypeWeapon* Creature::getWeponPtr()
{
    return Weapon;
}
