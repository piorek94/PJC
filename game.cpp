#include "game.h"

Game::Game()
{
    map = new Board("mapa.txt");
    map->addCreature(new Player(map));
    numberOfEnemies=0;
}

Game::~Game()
{    
    for(int i=0;i<map->getNumberOfCreature();i++)
    {
        delete (map->getCreature(i));
    }
    delete map;
}

Board* Game::getMapPtr()
{
    return map;
}

void Game::setNumberOfEnemies()
{
    for(int i=0;i<numberOfEnemies;i++)
    {
       // map->addCreature();
    }
}
