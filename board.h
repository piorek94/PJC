#ifndef BOARD_H
#define BOARD_H

#include "isize.h"
#include "creature.h"
#include "obstacle.h"
#include <vector>

class Board : public ISize
{
private:
    int Width;
    int Height;
public:
    std::vector <Creature*> creatures;
    std::vector <Obstacle*> obstacles;
    Board();
    ~Board();
    int getHeight();
    int getWidth();
    void setHeight(int _height);
    void setWidth(int _width);
};

#endif // BOARD_H
