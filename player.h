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
    Player(Board *_map, float _speed, int _maxHp, int _width, int _height);
    ~Player();
//    void setActuallWeapon(TypeWeapon* _typeWeapon);
    void virtual move(Board *_map);
    void virtual shoot();
    virtual void setWeapon();
};
#endif // PLAYER_H
