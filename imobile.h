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
    virtual void setStartPosition(Board *_map)=0;
};

#endif // IMOBILE_H
