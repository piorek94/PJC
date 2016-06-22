#ifndef BULLETSNIPER_H
#define BULLETSNIPER_H
#include "bullet.h"

class BulletSniper : public Bullet
{
public:
    BulletSniper(float _speed, int _width, int _height, float _aimX, float _aimY, float _startX, float _startY, int _range);
    virtual ~BulletSniper();
    void checkField(Board *_map);
};

#endif // BULLETSNIPER_H
