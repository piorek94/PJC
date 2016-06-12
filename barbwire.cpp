#include "barbwire.h"
#include "creature.h"

Barbwire::Barbwire(float _x, float _y)
    : Obstacle(_x, _y)
{

}
Barbwire::~Barbwire()
{

}

void Barbwire::reduceHp(Creature* _creature)
{
    _creature->setHp(_creature->getHp()-Damage);
}

void Barbwire::setDamage(int _damage)
{
    Damage=_damage;
}

int Barbwire::getDamage()
{
    return Damage;
}

bool Barbwire::CanPass()
{
    return true;
}
