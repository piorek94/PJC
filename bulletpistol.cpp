#include "bulletpistol.h"
#include "board.h"
#include "creature.h"
#include "math.h"

BulletPistol::BulletPistol(float _speed, int _width, int _height, int _damage, float _aimX, float _aimY, float _startX, float _startY, int _range)
    :Bullet(_speed,_width,_height,_damage,_aimX,_aimY,_startX,_startY,_range)
{

}

BulletPistol::~BulletPistol()
{

}

void BulletPistol::checkField(Board *_map)
{
    if(X<=0||Y<=0||Y+Height>=_map->getHeight()||X+Width>=_map->getWidth())
    {
       ToRemove=true;
       return;
    }
    else if( BulletRange <= sqrt( pow((X-StartX),2) + pow((Y-StartY),2)) )
    {
        ToRemove=true;
        return;
    }
    else
    {
        float X_c=X+Width/2;
        float Y_c=Y+Height/2;
        Object *obj=NULL;
        Creature *cre=NULL;

        for(int i=0;i<_map->getNumberOfObstacle();i++)
        {
            if(_map->getObstacle(i)->CanPass()==false)
            {
                obj=_map->getObstacle(i);
                if( this->isOn(X_c,Y_c,obj) )
                {
                    ToRemove=true;
                    return;
                }
            }
        }
        for(int i=0;i<_map->getNumberOfMobiles();i++)
        {
            cre=dynamic_cast<Creature*>(_map->getMobile(i));
            if(cre)
            {
                obj=_map->getMobile(i);
                if( this->isOn(X_c,Y_c,obj) )
                {
                    //reduceHp(cre);//?????????????????????????????????????????
                    ToRemove=true;
                    return;
                }
                cre=NULL;
            }
        }
    }
}
