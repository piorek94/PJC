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
    bool loadBoard(std::string _pathBoard);
    void loadBackground(std::string _pathBackground);
    std::vector <Creature*> creatures;
    std::vector <Obstacle*> obstacles;
public:
    Creature* getCreature();
    Obstacle* getObstacle();
    Board(std::string _plik);
    ~Board();
    int getHeight();
    int getWidth();
    void setHeight(int _height);
    void setWidth(int _width);
};

#endif // BOARD_H
