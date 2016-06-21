#include "sniper.h"
#include "sniperrifle.h"

Sniper::Sniper(Board *_map, float _speed, int _maxHp, int _width, int _height)
    :Enemy(_map,_speed,_maxHp,_width, _height)
{
    Weapon=new SniperRifle();
}

Sniper::~Sniper()
{
    delete Weapon;
}

int Sniper::direction(Board *_map)
{
    return 0;
}

void Sniper::move(Board *_map)
{

}

