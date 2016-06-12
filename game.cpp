#include "game.h"

Game::Game()
{
    map = new Board("mapa.txt");
    map->addCreature(new Player(map,2,200));
    numberOfEnemies=2;
    setEnemies();
}

Game::~Game()
{    
    for(int i=0;i<map->getNumberOfCreature();i++)
    {
        delete (map->getCreature(i));
    }
    map->clearCreature();
    delete map;
}

Board* Game::getMapPtr()
{
    return map;
}

void Game::setEnemies()
{
    for(int i=0;i<numberOfEnemies;i++)
    {
        map->addCreature(new Enemy(map,1,100));
    }
}
