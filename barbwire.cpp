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

void Barbwire::affect(Creature* _creature)
{
//    int X_c=_creature->getX()+_creature->getWidth()/2;
//    int Y_c=_creature->getY()+_creature->getHeight()/2;
//    if( ( X_c>=X && X_c<=X+Width ) && ( Y_c>=Y && Y_c<=Y+Height ) )
//    {
        _creature->setHp(_creature->getHp()-Damage);
//    }
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
