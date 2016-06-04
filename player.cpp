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
    if(move_up)
    {
        if(!checkCollisionUp())
        {
            Y-=Speed;
        }
    }

    if(move_right)
    {
        if(!checkCollisionRight())
        {
            X+=Speed;
        }
    }
    if(move_down)
    {
        if(!checkCollisionDown())
        {
            Y+=Speed;
        }
    }

    if (move_left)
    {
        if(!checkCollisionLeft())
        {
            X-=Speed;
        }
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
