#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"
#include <vector>

class Player : public Creature
{
private:
//    vector <TypeWeapon*> Weapons;
//    TypeWeapon ActuallWeapon;
public:
    Player(Board* _map);
    ~Player();
//    void setActuallWeapon(TypeWeapon* _typeWeapon);
    void virtual move();
    void virtual shoot();
    void virtual rotate(float _angle);
    virtual void setWeapon();
};
#endif // PLAYER_H
