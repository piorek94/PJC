#include "enemy.h"



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

int Enemy::direction()
{
    srand(time(0));
    return rand()%4;
}

void Enemy::move()
{
    int a=direction();

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
