#ifndef IMOBILE_H
#define IMOBILE_H

class Board;
class IMobile
{
public:
    IMobile();
    virtual ~IMobile();
    virtual void move(Board *_map)=0;
    virtual void checkField(Board *_map)=0;
    virtual bool getToRemove()=0;
    virtual bool checkCollisionUp(Board *_map)=0;
    virtual bool checkCollisionDown(Board *_map)=0;
    virtual bool checkCollisionRight(Board *_map)=0;
    virtual bool checkCollisionLeft(Board *_map)=0;
};

#endif // IMOBILE_H
