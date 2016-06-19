#ifndef MOBILE_H
#define MOBILE_H
#include "imobile.h"
#include "object.h"

class Mobile : public IMobile, public Object
{
protected:
    float Speed;
    bool ToRemove;
    bool checkCollisionUp(Board *_map);
    bool checkCollisionDown(Board *_map);
    bool checkCollisionRight(Board *_map);
    bool checkCollisionLeft(Board *_map);
public:
    Mobile(float _speed, int _width, int _height);
    virtual ~Mobile();
    bool getToRemove();
    virtual void move(Board *_map)=0;
    virtual void checkField(Board *_map)=0;
};

#endif // MOBILE_H

