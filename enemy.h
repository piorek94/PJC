#ifndef ENEMY_H
#define ENEMY_H
#include "creature.h"

class Enemy : public Creature
{
protected:
    enum move_dir{up,right,down,left};
    int dst_X;
    int dst_Y;
    bool CanSee(Board *_map);
public:
    Enemy(Board *_map, float _speed, int _maxHp, int _width, int _height);
    virtual ~Enemy();
    int virtual direction(Board* _map)=0;
    void virtual move(Board *_map)=0;
    void shoot();
    void setWeapon();
};

#endif // ENEMY_H
