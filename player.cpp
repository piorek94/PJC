#include "player.h"

Player::Player(Board* _map)
    :Creature(_map)
{

}

Player::~Player()
{

}

void Player::move()
{
    if (move_up && !checkCollisionUp())
    {
        Y-=Speed;
    }
    if (move_right && !checkCollisionRight())
    {
        X+=Speed;
    }
    if (move_down && !checkCollisionDown())
    {
        Y+=Speed;
    }
    if (move_left && !checkCollisionLeft())
    {
        X-=Speed;
    }
}

void Player::shoot()
{

}

void Player::rotate(float _angle)
{

}

void Player::setWeapon()
{

}
