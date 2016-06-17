#include "mud.h"
#include "creature.h"
Mud::Mud(float _x, float _y, float _slowness)
    : Obstacle(_x, _y)
{
    Slowness=_slowness;
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
        _creature->setSpeed(_creature->getMaxSpeed()-Slowness);
    }else
    {
        _creature->setSpeed(_creature->getMaxSpeed());
    }
}
