#include "bullet.h"
#include "creature.h"
#include <math.h>
Bullet::Bullet(float _speed, int _width, int _height,int _damage, float _aimX, float _aimY, float _startX, float _startY, int _range)
    :Mobile(_speed,_width,_height)
{
    Damage=_damage;
    AimX=_aimX;
    AimY=_aimY;
    StartX=_startX;
    X=_startX;
    StartY=_startY;
    Y=_startY;
    BulletRange=_range;
    Angle=calculateAngle(AimX,AimY,StartX,StartY);
}

Bullet::~Bullet()
{

}

void Bullet::reduceHp(Creature* _creature)
{
    _creature->setHp(_creature->getHp()-Damage);
}

float Bullet::calculateAngle(float _aimX, float _aimY, float _startX, float _startY)
{
    float x=_aimX-_startX;
    float y=_aimY-_startY;
    if(x==0)
    {
        if(y>=0)
        {
            return M_PI/2;
        }
        else
        {
            return 3*M_PI/2;
        }
    }
    else
    {
        float angle=atan(y/x);
        if(x>0)
        {
            return angle;
        }
        else
        {
            return angle+M_PI;
        }
    }
}

void Bullet::move(Board *_map)
{
    X+=cos(Angle)*Speed;
    Y+=sin(Angle)*Speed;
}
