#include "barbwire.h"
#include "creature.h"

Barbwire::Barbwire(float _x, float _y, int _damage)
    : Obstacle(_x, _y)
{
    Damage=_damage;
}
Barbwire::~Barbwire()
{

}

void Barbwire::affect(Creature* _creature, bool condition)
{
    if(condition)
    {
        _creature->setHp(_creature->getHp()-Damage);
    }
}

bool Barbwire::CanPass()
{
    return true;
}
