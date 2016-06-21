#include "mobile.h"
#include "board.h"
#include "creature.h"
#include "obstacle.h"

Mobile::Mobile(float _speed, int _width, int _height)
{
    ToRemove=false;
    Speed=_speed;
    Width=_width;
    Height=_height;
}

Mobile::~Mobile()
{

}

bool Mobile::getToRemove()
{
    return ToRemove;
}

bool Mobile::checkCollisionUp(Board *_map)
{
    for(int i=0;i<_map->getNumberOfObstacle();i++)
    {
        if(_map->getObstacle(i)->CanPass()==false)
        {
            int TopO=_map->getObstacle(i)->getY();
            int BotO=TopO+_map->getObstacle(i)->getHeight();
            int LefO=_map->getObstacle(i)->getX();
            int RigO=LefO+_map->getObstacle(i)->getWidth();
            if(((Y-Speed<=BotO && Y-Speed>=TopO) && !(X+Width<=LefO || X>=RigO)) || (Y-Speed<=0))
            {
                return true;
            }
        }
    }
    Creature *tmp;
    for(int i=0; i<_map->getNumberOfMobiles();i++)
    {
        tmp=dynamic_cast<Creature*>(_map->getMobile(i));
        if(tmp)
        {
            int TopC=_map->getMobile(i)->getY();
            int BotC=TopC+_map->getMobile(i)->getHeight();
            int LefC=_map->getMobile(i)->getX();
            int RigC=LefC+_map->getMobile(i)->getWidth();
            if((Y-Speed<=BotC && Y-Speed>=TopC) && !(X+Width<=LefC || X>=RigC))
            {
                return true;
            }
        }
    }
    return false;
}

bool Mobile::checkCollisionDown(Board *_map)
{
    for(int i=0;i<_map->getNumberOfObstacle();i++)
    {
        if(_map->getObstacle(i)->CanPass()==false)
        {
            int TopO=_map->getObstacle(i)->getY();
            int BotO=TopO+_map->getObstacle(i)->getHeight();
            int LefO=_map->getObstacle(i)->getX();
            int RigO=LefO+_map->getObstacle(i)->getWidth();
            if(((Y+Height+Speed>=TopO && Y+Height+Speed<=BotO) && !(X+Width<=LefO || X>=RigO)) || (Y+Height+Speed>=_map->getHeight()))
            {
                return true;
            }
        }
    }
    Creature *tmp;
    for(int i=0; i<_map->getNumberOfMobiles();i++)
    {
        tmp=dynamic_cast<Creature*>(_map->getMobile(i));
        if(tmp)
        {
            int TopC=_map->getMobile(i)->getY();
            int BotC=TopC+_map->getMobile(i)->getHeight();
            int LefC=_map->getMobile(i)->getX();
            int RigC=LefC+_map->getMobile(i)->getWidth();
            if((Y+Height+Speed>=TopC && Y+Height+Speed<=BotC) && !(X+Width<=LefC || X>=RigC))
            {
                return true;
            }
        }
    }
    return false;
}

bool Mobile::checkCollisionLeft(Board *_map)
{
    for(int i=0;i<_map->getNumberOfObstacle();i++)
    {
        if(_map->getObstacle(i)->CanPass()==false)
        {
            int TopO=_map->getObstacle(i)->getY();
            int BotO=TopO+_map->getObstacle(i)->getHeight();
            int LefO=_map->getObstacle(i)->getX();
            int RigO=LefO+_map->getObstacle(i)->getWidth();
            if(((X-Speed<=RigO && X-Speed>=LefO) && !(Y+Height<=TopO || Y>=BotO)) || (X-Speed<=0))
            {
                return true;
            }
        }
    }
    Creature *tmp;
    for(int i=0; i<_map->getNumberOfMobiles();i++)
    {
        tmp=dynamic_cast<Creature*>(_map->getMobile(i));
        if(tmp)
        {
            int TopC=_map->getMobile(i)->getY();
            int BotC=TopC+_map->getMobile(i)->getHeight();
            int LefC=_map->getMobile(i)->getX();
            int RigC=LefC+_map->getMobile(i)->getWidth();
            if((X-Speed<=RigC && X-Speed>=LefC) && !(Y+Height<=TopC || Y>=BotC))
            {
                return true;
            }
        }
    }
    return false;
}


bool Mobile::checkCollisionRight(Board *_map)
{
    for(int i=0;i<_map->getNumberOfObstacle();i++)
    {
        if(_map->getObstacle(i)->CanPass()==false)
        {
            int TopO=_map->getObstacle(i)->getY();
            int BotO=TopO+_map->getObstacle(i)->getHeight();
            int LefO=_map->getObstacle(i)->getX();
            int RigO=LefO+_map->getObstacle(i)->getWidth();
            if(((X+Width+Speed>=LefO && X+Width+Speed<=RigO) && !(Y+Height<=TopO || Y>=BotO)) || (X+Width+Speed>=_map->getWidth()))
            {
                return true;
            }
        }
    }
    Creature *tmp;
    for(int i=0; i<_map->getNumberOfMobiles();i++)
    {
        tmp=dynamic_cast<Creature*>(_map->getMobile(i));
        if(tmp)
        {
            int TopC=_map->getMobile(i)->getY();
            int BotC=TopC+_map->getMobile(i)->getHeight();
            int LefC=_map->getMobile(i)->getX();
            int RigC=LefC+_map->getMobile(i)->getWidth();
            if(((X+Width+Speed>=LefC && X+Width+Speed<=RigC) && !(Y+Height<=TopC || Y>=BotC)))
            {
                return true;
            }
        }
    }
    return false;
}

bool Mobile::isOn(float _xc, float _yc, Object *_field)
{
    Obstacle *obst;
    Creature *crea;
    crea=dynamic_cast<Creature*>(_field);
    obst=dynamic_cast<Obstacle*>(_field);
    if(crea || obst)
    {
        float TopO=_field->getY();
        float BotO=TopO+_field->getHeight();
        float LefO=_field->getX();
        float RigO=LefO+_field->getWidth();
        if( ( _xc>=LefO && _xc<=RigO ) && ( _yc>=TopO && _yc<=BotO ) )
        {
            return true;
        }
    }
    return false;
}
