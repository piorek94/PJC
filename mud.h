#ifndef MUD_H
#define MUD_H
#include "obstacle.h"

class Mud : public Obstacle
{
private:
    float Slowness;
public:
    Mud(float _x, float _y, float _slowness);
    ~Mud();
    virtual bool CanPass();
    virtual void affect(Creature* _creature);
    void setSlowness(float _slowness);
    float getSlowness();
};

#endif // MUD_H
