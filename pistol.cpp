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

Bullet* Pistol::CreateBullet()
{
    return new BulletPistol(3,4,4,0,0,300,300,200);
}
