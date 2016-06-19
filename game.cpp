#include "game.h"

Game::Game()
{
    map = new Board("mapa.txt");
    map->addMobile(new Player(map,3,500, 20, 30));
    numberOfEnemies=2;
    setEnemies();
}

Game::~Game()
{    
    for(int i=0;i<map->getNumberOfMobiles();i++)
    {
        delete (map->getMobile(i));
    }
    map->clearMobiles();
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
        map->addMobile(new Enemy(map,2,200, 20, 30));
    }
}

void Game::updateGame()
{
    for (int i=0; i<map->getNumberOfMobiles(); i++)
    {
        if(map->getMobile(i)->getToRemove())
        {
            map->removeMobile(i);
        }
        else
        {
            map->getMobile(i)->move(map);
            map->getMobile(i)->checkField(map);
        }
    }
}

bool Game::lose()
{
    bool lose=true;
    Player *tmp;
    for (int i=0; i<map->getNumberOfMobiles(); i++)
    {
        tmp = dynamic_cast<Player*> (map->getMobile(i));
        if(tmp)
        {
            lose=false;
        }
    }
    return lose;
}

bool Game::win()
{
    bool win=true;
    Enemy *tmp;
    for (int i=0; i<map->getNumberOfMobiles(); i++)
    {
        tmp = dynamic_cast<Enemy*> (map->getMobile(i));
        if(tmp)
        {
            win=false;
        }
    }
    return win;
}
