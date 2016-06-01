#ifndef MUD_H
#define MUD_H
#include<obstacle.h>
#include<creature.h>

class Mud : public Obstacle
{
private:
    float Slowness;
public:
    Mud();
    ~Mud();
    virtual bool CanPass();
    void reduceSpeed(Creature* _creature);
    void setSlowness(float _slowness);
    float getSlowness();//??
};

#endif // MUD_H
