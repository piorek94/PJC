#include "pistol.h"
#include "bulletpistol.h"

Pistol::Pistol()
{
    ShootRange=100;
    Width=12;
    Height=10;
}

Pistol::~Pistol()
{

}

Bullet* Pistol::CreateBullet(float _aimX, float _aimY, float _startX, float _startY)
{
    return new BulletPistol(8,2,2,4,_aimX,_aimY,_startX,_startY,ShootRange);
}
