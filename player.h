#ifndef PLAYER_H
#define PLAYER_H

#include "creature.h"
#include <vector>

extern bool move_up;
extern bool move_down;
extern bool move_right;
extern bool move_left;
extern bool pistolOn;
extern bool sniperrifleOn;
extern bool bazookaOn;
extern bool PlayerShootOn;
extern int PlayerDstX;
extern int PlayerDstY;

class Player : public Creature
{
private:
    std::vector <TypeWeapon*> Weapons;
public:
    Player(Board *_map, float _speed, int _maxHp, int _width, int _height);
    virtual ~Player();
    void move(Board *_map);
    void shoot(Board *_map);
    void ChangeWeapon();
};
#endif // PLAYER_H
