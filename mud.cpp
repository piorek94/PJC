#include "mud.h"
#include "creature.h"

Mud::Mud(float _x, float _y)
    : Obstacle(_x, _y)
{
    Slowness=2;
}

Mud::~Mud()
{

}

bool Mud::CanPass()
{
    return true;
}

void Mud::affect(Creature* _creature, bool condition)
{
    if(condition)
    {
        _creature->setSpeed(_creature->getMaxSpeed()/Slowness);
    }else
    {
        _creature->setSpeed(_creature->getMaxSpeed());
    }
}
