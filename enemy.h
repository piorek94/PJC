#ifndef ENEMY_H
#define ENEMY_H
#include "creature.h"

class Enemy : public Creature
{
protected:
    int direction();
    enum move_dir{up,right,down,left};
public:
    Enemy(Board *_map, float _speed, int _maxHp, int _width, int _height);
    virtual ~Enemy();
    void virtual move(Board *_map);
    void shoot();
    void setWeapon();
};

#endif // ENEMY_H
