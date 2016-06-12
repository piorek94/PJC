#ifndef ENEMY_H
#define ENEMY_H
#include "creature.h"



class Enemy : public Creature
{
private:
    static int direction();
    enum ruch{up,right,down,left};
public:
    Enemy(Board *_map, float _speed, int _maxHp);
    ~Enemy();
    void virtual move(Board *_map);
    void virtual shoot();
    void virtual rotate(float _angle);
    virtual void setWeapon();
};

#endif // ENEMY_H
