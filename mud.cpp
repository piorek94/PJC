#include "mud.h"

Mud::Mud(int _x, int _y)
    : Obstacle(_x, _y)
{

}
Mud::~Mud()
{

}

bool Mud::CanPass()
{
    return true;
}
//nie wiem jak zrobic zeby spowalniało tylko podczas postoju na nim(zrobic metode bool isOn()?)
//void Mud::reduceSpeed(Creature* _creature)
//{
//    _creature->setSpeed(_creature->getSpeed()-Slowness);
//}

void Mud::setSlowness(float _slowness)
{
    Slowness=_slowness;
}

float Mud::getSlowness()
{
    return Slowness;
}
