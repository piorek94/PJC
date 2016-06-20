#include "enemy.h"
#include "player.h"
#include "board.h"
#include <math.h>

Enemy::Enemy(Board *_map, float _speed, int _maxHp,int _width, int _height)
    :Creature(_map,_speed, _maxHp, _width, _height)
{

}

Enemy::~Enemy()
{

}

void Enemy::shoot()
{

}

void Enemy::setWeapon()
{

}

bool Enemy::CanSee(Board *_map)
{
    Player *tmp;
    for(int i=0;i<_map->getNumberOfMobiles();i++)
    {
        tmp=dynamic_cast<Player*>(_map->getMobile(i));
        if(tmp)
        {
            float tmpX=_map->getMobile(i)->getX()+(_map->getMobile(i)->getWidth())/2;
            float tmpY=_map->getMobile(i)->getY()+(_map->getMobile(i)->getHeight())/2;
            if(Range>=sqrt((tmpX-X)*(tmpX-X)+(tmpY-Y)*(tmpY-Y)))
            {
                dst_X=tmpX;
                dst_Y=tmpY;
                return true;
            }
            else
            {
                return false;
            }

        }
    }
    return false;
}
