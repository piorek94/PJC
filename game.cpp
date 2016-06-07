#include "game.h"

Game::Game()
{
    map = new Board("mapa.txt");
    map->addCreature(new Player(map));
    numberOfEnemies=1;
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
    int x=40;
    int y=100;
    int c=20;
    for(int i=0;i<numberOfEnemies;i++)
    {
        Enemy *enemy=new Enemy(map);
        x+=c;
        y+=c;
        enemy->setX(x);
        enemy->setY(y);
        map->addCreature(enemy);
    }
}
