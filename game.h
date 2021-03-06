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
    void PistolShoot();
    void SniperShoot();
    void BazookaShoot();

private:
    Board *map;
    int numberOfBazookers;
    int numberOfPistolers;
    int numberOfSnipers;
    void setEnemies();
};

#endif // GAME_H
