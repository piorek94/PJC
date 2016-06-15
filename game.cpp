#include "game.h"

Game::Game()
{
    map = new Board("mapa.txt");
    map->addCreature(new Player(map,3,500));
    numberOfEnemies=2;
    setEnemies();
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

void Game::setEnemies()
{
    for(int i=0;i<numberOfEnemies;i++)
    {
        map->addCreature(new Enemy(map,2,500));
    }
}

void Game::updateGame()
{
    for (int i=0; i<map->getNumberOfCreature(); i++)
    {
        if(map->getCreature(i)->isDead())
        {
            map->removeCreature(i);
        }else{
        map->getCreature(i)->move(map);
        map->getCreature(i)->checkField(map);
        }
    }
}
