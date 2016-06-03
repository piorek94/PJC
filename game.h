#ifndef GAME_H
#define GAME_H

#include "board.h"
//#include "player.h"
class Game
{
public:
    Game();
    ~Game();
    Board *getMapPtr();
    void setNumberOfEnemies();

private:
    Board *map;
    int numberOfEnemies;

};
//chyba w konstruktorze bede tworzył playera jako jednego i dodawał do vektora a reszte(przeciwnicy) wprowadzał
#endif // GAME_H
