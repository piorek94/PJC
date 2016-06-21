#ifndef SNIPER_H
#define SNIPER_H
#include "enemy.h"

class Sniper : public Enemy
{
private:
    int direction(Board* _map);
public:
    Sniper(Board *_map, float _speed, int _maxHp, int _width, int _height);
    virtual ~Sniper();
    void move(Board *_map);
};

#endif // SNIPER_H
