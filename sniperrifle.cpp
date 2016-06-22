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

Bullet* SniperRifle::CreateBullet(float _aimX, float _aimY, float _startX, float _startY)
{
    return new BulletSniper(14,4,4,30,_aimX,_aimY,_startX,_startY,ShootRange);
}
