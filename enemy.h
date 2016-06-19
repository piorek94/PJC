#ifndef ENEMY_H
#define ENEMY_H
#include "creature.h"



class Enemy : public Creature
{
private:
    static int direction();
    enum move_dir{up,right,down,left};
public:
    Enemy(Board *_map, float _speed, int _maxHp, int _width, int _height);
    virtual ~Enemy();
    void virtual move(Board *_map);
    void virtual shoot();
    virtual void setWeapon();
};

#endif // ENEMY_H
