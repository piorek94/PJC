#ifndef ENEMY_H
#define ENEMY_H
#include "creature.h"

class Enemy : public Creature
{
private:
    enum ruch{up,right,down,left};
public:
    Enemy(Board* _map);
    ~Enemy();
    void virtual move();
    void virtual shoot();
    void virtual rotate(float _angle);
    virtual void setWeapon();
};

#endif // ENEMY_H
