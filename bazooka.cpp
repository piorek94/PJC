#include "bazooka.h"
#include "bulletbazooka.h"

Bazooka::Bazooka()
{
    ShootRange=300;
    Width=35;
    Height=17;
}

Bazooka::~Bazooka()
{

}

Bullet* Bazooka::CreateBullet(float _aimX, float _aimY, float _startX, float _startY)
{
    return new BulletBazooka(6,5,5,20,_aimX,_aimY,_startX,_startY,ShootRange);
}

