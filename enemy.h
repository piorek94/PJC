#ifndef ENEMY_H
#define ENEMY_H
#include "creature.h"
#include "player.h"

class Enemy : public Creature
{
protected:
    enum move_dir{up,right,down,left};
    float dst_X;
    float dst_Y;
    bool CanSee(Board *_map, Player *_player);
    bool inRange(Player *_player);
    Player *getPlayerPtr(Board* _map);
public:
    Enemy(Board *_map, float _speed, int _maxHp, int _width, int _height);
    virtual ~Enemy();
    int virtual direction(Board* _map)=0;
    void virtual move(Board *_map)=0;
    void shoot();
};

#endif // ENEMY_H
