#include "bazooker.h"
#include "bazooka.h"
#include <ctime>
#include <cstdlib>

Bazooker::Bazooker(Board *_map, float _speed, int _maxHp, int _width, int _height)
    :Enemy(_map,_speed,_maxHp,_width, _height)
{
    Weapon=new Bazooka();
}

Bazooker::~Bazooker()
{

}

int Bazooker::direction(Board *_map)
{
    srand(time(0));
    return rand()%4;
}

void Bazooker::move(Board *_map)
{
    int a=direction(_map);

    if (a==up)
    {
        if(!checkCollisionUp(_map))
        {
            Y-=Speed;
        }
    }
    if (a==right)
    {
        if(!checkCollisionRight(_map))
        {
            X+=Speed;
        }
    }
    if (a==down)
    {
        if(!checkCollisionDown(_map))
        {
            Y+=Speed;
        }
    }
    if (a==left)
    {
        if(!checkCollisionLeft(_map))
        {
            X-=Speed;
        }
    }
}
