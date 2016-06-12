#ifndef MUD_H
#define MUD_H
#include "obstacle.h"

class Creature;
class Mud : public Obstacle
{
private:
    float Slowness;
public:
    Mud(float _x, float _y);
    ~Mud();
    virtual bool CanPass();
    void reduceSpeed(Creature* _creature);
    void setSlowness(float _slowness);
    float getSlowness();
};

#endif // MUD_H
