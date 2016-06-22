#include "barbwire.h"
#include "creature.h"

Barbwire::Barbwire(float _x, float _y)
    : Obstacle(_x, _y)
{
    Damage=2;
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
