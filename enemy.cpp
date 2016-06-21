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
    bool visible=true;//
    Object *obj;//
    int y,y_min,y_max,x,x_min,x_max,a,b,tmpX,tmpY;
    int Xe=X+Width/2;
    int Ye=Y+Height/2;
    for(int m=0;m<_map->getNumberOfMobiles();m++)
    {
        tmp=dynamic_cast<Player*>(_map->getMobile(m));
        if(tmp)
        {
            tmpX=_map->getMobile(m)->getX()+(_map->getMobile(m)->getWidth())/2;
            tmpY=_map->getMobile(m)->getY()+(_map->getMobile(m)->getHeight())/2;

            if(Ye-tmpY<2)//jesli sa w tym samym y
            {
                y=Ye;
                if(Xe<=tmpX)
                {
                    x_min=Xe;
                    x_max=tmpX;
                }
                else
                {
                    x_min=tmpX;
                    x_max=Xe;
                }
                for(int i=x_min;i<x_max;i+=10)
                {
                    for(int j=0;j<_map->getNumberOfObstacle();j++)
                    {
                        if(_map->getObstacle(j)->CanPass()==false)
                        {
                            obj=_map->getObstacle(j);
                            if(isOn(i,y,obj))
                            {
                                visible=false;
                            }
                        }
//                        if(visible==false)
//                        {
//                            break;
//                        }
                    }
//                    if(visible==false)
//                    {
//                        break;
//                    }
                }
            }
            else if(X-tmpX<2)//jesli sa w tym samym x
            {
                x=Xe;
                if(Ye<=tmpY)
                {
                    y_min=Ye;
                    y_max=tmpY;
                }
                else
                {
                    y_min=tmpY;
                    y_max=Ye;
                }
                for(float i=y_min;i<=y_max;i+=15)
                {
                    for(int j=0;j<_map->getNumberOfObstacle();j++)
                    {
                        if(_map->getObstacle(j)->CanPass()==false)
                        {
                            obj=_map->getObstacle(j);
                            if(isOn(x,i,obj))
                            {
                                visible=false;
                            }
                        }
//                        if(visible==false)
//                        {
//                            break;
//                        }
                    }
//                    if(visible==false)
//                    {
//                        break;
//                    }
                }
            }
            else
            {
                a=(Ye-tmpY)/(Xe-tmpX);
                b=Ye-a*Xe;

                if(abs(a)>=1)//jesli przyrost y jest wiekszy niz x to zmienna to y
                {
                    if(Ye<=tmpY)
                    {
                        y_min=Ye;
                        y_max=tmpY;
                    }
                    else
                    {
                        y_min=tmpY;
                        y_max=Ye;
                    }

                    for(float i=y_min;i<=y_max;i+=4)
                    {
                        x=(i-b)/a;
                        for(int j=0;j<_map->getNumberOfObstacle();j++)
                        {
                            if(_map->getObstacle(j)->CanPass()==false)
                            {
                                obj=_map->getObstacle(j);
                                if(isOn(x,i,obj))
                                {
                                    visible=false;
                                }
                            }
//                            if(visible==false)
//                            {
//                                break;
//                            }
                        }
//                        if(visible==false)
//                        {
//                            break;
//                        }
                    }
                }
                else
                {
                    if(Xe<=tmpX)
                    {
                        x_min=Xe;
                        x_max=tmpX;
                    }
                    else
                    {
                        x_min=tmpX;
                        x_max=Xe;
                    }
                    for(float i=x_min;i<=x_max;i+=4)
                    {
                        y=a*i+b;
                        for(int j=0;j<_map->getNumberOfObstacle();j++)
                        {
                            if(_map->getObstacle(j)->CanPass()==false)
                            {
                                obj=_map->getObstacle(j);
                                if(isOn(i,y,obj))
                                {
                                    visible=false;
                                }
                            }
//                            if(visible==false)
//                            {
//                                break;
//                            }
                        }
//                        if(visible==false)
//                        {
//                            break;
//                        }
                    }
                }
            }
            if(visible)
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
