#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game
{
public:
    Game();
    ~Game();
    Board *getMapPtr();
    void setEnemies();

private:
    Board *map;
    int numberOfEnemies;

};

#endif // GAME_H
