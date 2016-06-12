#ifndef BARBWIRE_H
#define BARBWIRE_H
#include "obstacle.h"
class Creature;
class Barbwire : public Obstacle
{
private:
    int Damage;
public:
    Barbwire(float _x, float _y);
    ~Barbwire();
    void reduceHp(Creature* _creature);
    void setDamage(int _damage);
    int getDamage();
    virtual bool CanPass();
};

#endif // BARBWIRE_H
