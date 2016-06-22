#include "bazooka.h"
#include "bulletbazooka.h"

Bazooka::Bazooka()
{
    ShootRange=200;
    Width=35;
    Height=17;
}

Bazooka::~Bazooka()
{

}

Bullet* Bazooka::CreateBullet()
{
    return new BulletBazooka(3,4,4,0,0,300,300,200);
}
