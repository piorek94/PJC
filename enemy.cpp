#include "enemy.h"

Enemy::Enemy(Board *_map, float _speed, int _maxHp)
    :Creature(_map,_speed, _maxHp)
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

void Enemy::move(Board *_map)
{
    int a=direction();

    if (a==up)
    {
        if(!checkCollisionUp(_map))
        {
            Y-=Speed;
        }
    }
    if (a==right)
    {
        if(!checkCollisionRight(_map))
        {
            X+=Speed;
        }
    }
    if (a==down)
    {
        if(!checkCollisionDown(_map))
        {
            Y+=Speed;
        }
    }
    if (a==left)
    {
        if(!checkCollisionLeft(_map))
        {
            X-=Speed;
        }
    }
}
