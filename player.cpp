#include "player.h"

Player::Player(Board *_map, float _speed, int _maxHp, int _width, int _height)
    :Creature(_map,_speed,_maxHp,_width,_height)
{

}

Player::~Player()
{

}

void Player::move(Board *_map)
{
    if(move_up)
    {
        if(!checkCollisionUp(_map))
        {
            Y-=Speed;
        }
    }

    if(move_right)
    {
        if(!checkCollisionRight(_map))
        {
            X+=Speed;
        }
    }
    if(move_down)
    {
        if(!checkCollisionDown(_map))
        {
            Y+=Speed;
        }
    }

    if (move_left)
    {
        if(!checkCollisionLeft(_map))
        {
            X-=Speed;
        }
    }
}

void Player::shoot()
{

}

void Player::setWeapon()
{

}
