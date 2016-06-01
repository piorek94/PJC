#include "barbwire.h"

Barbwire::Barbwire()
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
