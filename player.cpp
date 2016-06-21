#include "player.h"
#include "pistol.h"
#include "bazooka.h"
#include "sniperrifle.h"



Player::Player(Board *_map, float _speed, int _maxHp, int _width, int _height)
    :Creature(_map,_speed,_maxHp,_width,_height)
{
    Weapons.push_back(new Pistol());
    Weapons.push_back(new Bazooka());
    Weapons.push_back(new SniperRifle());
    Weapon=Weapons.at(0);
}

Player::~Player()
{
    for(int i=0;i<(int)Weapons.size();i++)
    {
        delete Weapons.at(i);
    }
    Weapons.clear();
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

void Player::ChangeWeapon()
{
    if(pistolOn)
    {
        Pistol* tmp;
        for(int i=0;i<(int)Weapons.size();i++)
        {
            tmp=dynamic_cast<Pistol*>(Weapons.at(i));
            if(tmp)
            {
                Weapon=Weapons.at(i);
            }
        }
    }
    else if(bazookaOn)
    {
        Bazooka* tmp;
        for(int i=0;i<(int)Weapons.size();i++)
        {
            tmp=dynamic_cast<Bazooka*>(Weapons.at(i));
            if(tmp)
            {
                Weapon=Weapons.at(i);
            }
        }
    }
    else if(sniperrifleOn)
    {
        SniperRifle* tmp;
        for(int i=0;i<(int)Weapons.size();i++)
        {
            tmp=dynamic_cast<SniperRifle*>(Weapons.at(i));
            if(tmp)
            {
                Weapon=Weapons.at(i);
            }
        }
    }

}
