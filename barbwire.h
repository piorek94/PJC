#ifndef BARBWIRE_H
#define BARBWIRE_H
#include "obstacle.h"
#include "creature.h"//?????
class Barbwire : public Obstacle
{
private:
    int Damage;
public:
    Barbwire();
    ~Barbwire();
    void reduceHp(Creature* _creature);
    void setDamage(int _damage);
    int getDamage();//??
    virtual bool CanPass();
};

#endif // BARBWIRE_H
