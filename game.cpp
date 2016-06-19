#include "game.h"

Game::Game(int Enemies)
{
    map = new Board("mapa.txt");
    map->addCreature(new Player(map,3,500, 20, 30));
    numberOfEnemies=Enemies;
    setEnemies();
}

Game::~Game()
{    
    for(int i=0;i<map->getNumberOfCreature();i++)
    {
        delete (map->getCreature(i));
    }
    map->clearCreatures();
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
        map->addCreature(new Enemy(map,2,200, 20, 30));
    }
}

void Game::updateGame()
{
    for (int i=0; i<map->getNumberOfCreature(); i++)
    {
        if(map->getCreature(i)->isDead())
        {
            map->removeCreature(i);
        }
        else
        {
            map->getCreature(i)->move(map);
            map->getCreature(i)->checkField(map);
        }
    }
}

bool Game::lose()
{
    bool lose=true;
    Player *tmp;
    for (int i=0; i<map->getNumberOfCreature(); i++)
    {
        tmp = dynamic_cast<Player*> (map->getCreature(i));
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
    for (int i=0; i<map->getNumberOfCreature(); i++)
    {
        tmp = dynamic_cast<Enemy*> (map->getCreature(i));
        if(tmp)
        {
            win=false;
        }
    }
    return win;
}
