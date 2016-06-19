#ifndef BOARD_H
#define BOARD_H

#include "object.h"
#include "player.h"
#include "enemy.h"
#include "wall.h"
#include "barbwire.h"
#include "mud.h"
#include <vector>
#include <iostream>

class Board : public Object
{
private:
//    int Width;
//    int Height;
//    int X;
//    int Y;
    enum obst{wall,mud,barbwire};
    std::vector <Creature*> creatures;
    std::vector <Obstacle*> obstacles;
    bool loadBoard(std::string _pathBoard);
public:
    Board(std::string _file);
    virtual ~Board();
//    int getHeight();
//    int getWidth();
//    float getX();
//    float getY();
    Creature* getCreature(int c);
    Obstacle* getObstacle(int o);
    void addCreature(Creature* _creature);
    void removeCreature(int i);
    void clearCreatures();
    int getNumberOfObstacle();
    int getNumberOfCreature();
};

#endif // BOARD_H
