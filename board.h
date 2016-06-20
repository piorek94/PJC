#ifndef BOARD_H
#define BOARD_H

#include "player.h"
#include "enemy.h"
#include "mobile.h"
#include "wall.h"
#include "barbwire.h"
#include "mud.h"
#include "obstacle.h"
#include "mobile.h"
#include <vector>
#include <iostream>

class Board : public Object
{
private:
    enum obst{wall,mud,barbwire};
    std::vector <Mobile*> mobiles;
    std::vector <Obstacle*> obstacles;
    bool loadBoard(std::string _pathBoard);
public:
    Board(std::string _file);
    virtual ~Board();
    Mobile* getMobile(int c);
    Obstacle* getObstacle(int o);
    void addMobile(Mobile* _mobile);
    void removeMobile(int i);
    void clearMobiles();
    int getNumberOfObstacle();
    int getNumberOfMobiles();
};

#endif // BOARD_H
