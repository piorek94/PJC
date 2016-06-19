#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"

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
    virtual ~Player();
//    void setActuallWeapon(TypeWeapon* _typeWeapon);
    void move(Board *_map);
    void shoot();
    void setWeapon();
};
#endif // PLAYER_H
