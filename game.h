#ifndef GAME_H
#define GAME_H

#include "board.h"

class Game
{
public:
    Game(int Enemies);
    ~Game();
    Board *getMapPtr();
    void setEnemies();
    void updateGame();
    bool win();
    bool lose();

private:
    Board *map;
    int numberOfEnemies;

};

#endif // GAME_H
