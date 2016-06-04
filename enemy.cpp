#include "enemy.h"
#include <ctime>
#include <cstdlib>


Enemy::Enemy(Board *_map)
    : Creature(_map)
{

}

Enemy::~Enemy()
{

}

void Enemy::shoot()
{

}

void Enemy::rotate(float _angle)
{

}

void Enemy::setWeapon()
{

}

void Enemy::move()
{
    srand(time(0));
    int a=rand()%4;

    if (a==up)
    {
        if(!checkCollisionUp())
        {
            Y-=Speed;
        }
    }
    if (a==right)
    {
        if(!checkCollisionRight())
        {
            X+=Speed;
        }
    }
    if (a==down)
    {
        if(!checkCollisionDown())
        {
            Y+=Speed;
        }
    }
    if (a==left)
    {
        if(!checkCollisionLeft())
        {
            X-=Speed;
        }
    }
}
