#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game
{
public:
    Game();
    ~Game();
    Board *getMapPtr();    
    void updateGame();
    bool win();
    bool lose();

private:
    Board *map;
    int numberOfEnemies;
    void setEnemies();
};

#endif // GAME_H
