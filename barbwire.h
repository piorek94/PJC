#ifndef BARBWIRE_H
#define BARBWIRE_H
#include "obstacle.h"
//#include "creature.h"//?????
class Barbwire : public Obstacle
{
private:
    int Damage;
public:
    Barbwire(int _x, int _y);
    ~Barbwire();
//    void reduceHp(Creature* _creature);
    void setDamage(int _damage);
    int getDamage();//??
    virtual bool CanPass();
};

#endif // BARBWIRE_H
