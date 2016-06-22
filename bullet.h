#ifndef BULLET_H
#define BULLET_H
#include "mobile.h"
class Creature;
class Bullet : public Mobile
{
private:
    float calculateAngle(float _aimX, float _aimY, float _startX, float _startY);
protected:
    int Damage;
    float StartX;
    float StartY;
    float AimX;
    float AimY;
    int BulletRange;
    float Angle;
public:
    Bullet(float _speed, int _width, int _height, int _damage, float _aimX, float _aimY, float _startX, float _startY, int _range);
    virtual ~Bullet();
    void reduceHp(Creature* _creature);
};

#endif // BULLET_H
