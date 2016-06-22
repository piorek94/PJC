#ifndef BULLETPISTOL_H
#define BULLETPISTOL_H
#include "bullet.h"

class BulletPistol : public Bullet
{
public:
    BulletPistol(float _speed, int _width, int _height, float _aimX, float _aimY, float _startX, float _startY, int _range);
    virtual ~BulletPistol();
    void checkField(Board *_map);
};

#endif // BULLETPISTOL_H
