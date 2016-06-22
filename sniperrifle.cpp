#include "sniperrifle.h"
#include "bulletsniper.h"

SniperRifle::SniperRifle()
{
    ShootRange=500;
    Width=30;
    Height=15;
}

SniperRifle::~SniperRifle()
{

}

Bullet* SniperRifle::CreateBullet()
{
    return new BulletSniper(3,4,4,300,200,200,200,100);
}
