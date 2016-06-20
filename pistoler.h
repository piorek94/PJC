#ifndef PISTOLER_H
#define PISTOLER_H
#include "enemy.h"

class Pistoler : public Enemy
{
private:
    int virtual direction(Board *_map);
public:
    Pistoler(Board *_map, float _speed, int _maxHp, int _width, int _height);
    virtual ~Pistoler();
    void move(Board *_map);
};

#endif // PISTOLER_H
