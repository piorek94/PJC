#ifndef GAME_H
#define GAME_H

#include <board.h>
#include <obstacle.h>
#include <player.h>
class Game
{
public:
    Game();
    ~Game();
    Board *getMapPtr();
//    int getNumberOfCreatures();
//    void setNumberOfCreatures();
//    Creature* getCreaturePtr (int numer);

private:
    Board *map;
//    std::vector<Creature*> osoby;
//    int numberOfCreatures;

};
//chyba w konstruktorze bede tworzył playera jako jednego i dodawał do vektora a reszte(przeciwnicy) wprowadzał
#endif // GAME_H
