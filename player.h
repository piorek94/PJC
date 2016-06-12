#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"
//#include <vector>

extern bool move_up;
extern bool move_down;
extern bool move_right;
extern bool move_left;

class Player : public Creature
{
private:
//    vector <TypeWeapon*> Weapons;
//    TypeWeapon ActuallWeapon;
public:
    Player(Board *_map, float _speed, int _maxHp);
    ~Player();
//    void setActuallWeapon(TypeWeapon* _typeWeapon);
    void virtual move(Board *_map);
    void virtual shoot();
    void virtual rotate(float _angle);
    virtual void setWeapon();
};
#endif // PLAYER_H
