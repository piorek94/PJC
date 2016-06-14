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

void Mud::affect(Creature* _creature)
{
//    int X_c=_creature->getX()+_creature->getWidth()/2;
//    int Y_c=_creature->getY()+_creature->getHeight()/2;
//    if( ( X_c>=X && X_c<=X+Width ) && ( Y_c>=Y && Y_c<=Y+Height ) )
//    {
        _creature->setSpeed(_creature->getMaxSpeed()-Slowness);
//        return;
//    }
//    else
//    {
//        _creature->setSpeed(_creature->getMaxSpeed());
//    }
}
void Mud::setSlowness(float _slowness)
{
    Slowness=_slowness;
}

float Mud::getSlowness()
{
    return Slowness;
}
