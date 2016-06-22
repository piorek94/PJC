#ifndef BULLETBAZOOKA_H
#define BULLETBAZOOKA_H
#include "bullet.h"

class BulletBazooka : public Bullet
{
public:
    BulletBazooka(float _speed, int _width, int _height, float _aimX, float _aimY, float _startX, float _startY, int _range);
    virtual ~BulletBazooka();
    void checkField(Board *_map);
};

#endif // BULLETBAZOOKA_H
