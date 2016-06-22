#ifndef MUD_H
#define MUD_H
#include "obstacle.h"

class Mud : public Obstacle
{
private:
    float Slowness;
public:
    Mud(float _x, float _y);
    virtual ~Mud();
    bool CanPass();
    void affect(Creature* _creature,bool condition);
};

#endif // MUD_H
