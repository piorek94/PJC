#ifndef BARBWIRE_H
#define BARBWIRE_H
#include "obstacle.h"

class Barbwire : public Obstacle
{
private:
    int Damage;
public:
    Barbwire(float _x, float _y, int _damage);
    ~Barbwire();
    virtual void affect(Creature* _creature);
    void setDamage(int _damage);
    int getDamage();
    virtual bool CanPass();
};

#endif // BARBWIRE_H
