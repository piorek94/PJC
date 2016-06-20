#include "pistoler.h"
#include <ctime>
#include <cstdlib>

Pistoler::Pistoler(Board *_map, float _speed, int _maxHp, int _width, int _height)
    :Enemy(_map,_speed,_maxHp,_width, _height)
{

}

Pistoler::~Pistoler()
{

}

int Pistoler::direction(Board *_map)
{
    if(CanSee(_map))
    {
        int Xc=X+Width/2;
        int Yc=Y+Height/2;
        if(dst_X<=Xc && dst_Y<=Yc)//2
        {
            if(Xc-dst_X<=Yc-dst_Y)
            {
                if(!checkCollisionUp(_map))
                {
                    return up;
                }
                else
                {
                    return left;
                }
            }
            else
            {
                if(!checkCollisionLeft(_map))
                {
                    return left;
                }
                else
                {
                    return up;
                }
            }
        }
        if(dst_X<=Xc && dst_Y>=Yc)//3
        {
            if(Xc-dst_X<=dst_Y-Yc)
            {
                if(!checkCollisionDown(_map))
                {
                    return down;
                }
                else
                {
                    return left;
                }
            }
            else
            {
                if(!checkCollisionLeft(_map))
                {
                    return left;
                }
                else
                {
                    return down;
                }
            }
        }
        if(dst_X>=Xc && dst_Y>=Yc)//4
        {
            if(dst_X-Xc<=dst_Y-Yc)
            {
                if(!checkCollisionDown(_map))
                {
                    return down;
                }
                else
                {
                    return right;
                }
            }
            else
            {
                if(!checkCollisionRight(_map))
                {
                    return right;
                }
                else
                {
                    return down;
                }
            }
        }
        if(dst_X>=Xc && dst_Y<=Yc)//1
        {
            if(dst_X-Xc<=Yc-dst_Y)
            {
                if(!checkCollisionUp(_map))
                {
                    return up;
                }
                else
                {
                    return right;
                }
            }
            else
            {
                if(!checkCollisionRight(_map))
                {
                    return right;
                }
                else
                {
                    return up;
                }
            }
        }
    }
    srand(time(0));
    return rand()%4;
}

void Pistoler::move(Board *_map)
{
    int a=direction(_map);

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

