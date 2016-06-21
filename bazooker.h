#ifndef BAZOOKER_H
#define BAZOOKER_H
#include "enemy.h"

class Bazooker :public Enemy
{
private:
    int direction(Board *_map);
public:
    Bazooker(Board *_map, float _speed, int _maxHp, int _width, int _height);
    virtual ~Bazooker();
    void move(Board *_map);
};

#endif // BAZOOKER_H
