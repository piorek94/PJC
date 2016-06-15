#ifndef BOARD_H
#define BOARD_H

#include "isize.h"
#include "player.h"
#include "enemy.h"
#include "wall.h"
#include "barbwire.h"
#include "mud.h"
#include <vector>
#include <iostream>

class Board : public ISize
{
private:
    int Width;
    int Height;
    bool loadBoard(std::string _pathBoard);
    std::vector <Creature*> creatures;
    std::vector <Obstacle*> obstacles;
public:
    Creature* getCreature(int c);
    Obstacle* getObstacle(int o);
    void addCreature(Creature* _creature);
    void removeCreature(int i);
    void addObstacle(Obstacle* _obstacle);
    void clearCreature();
    void clearObstacle();
    int getNumberOfObstacle();
    int getNumberOfCreature();
    Board(std::string _plik);
    ~Board();
    int getHeight();
    int getWidth();
    void setHeight(int _height);
    void setWidth(int _width);
};

#endif // BOARD_H
