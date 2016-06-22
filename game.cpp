#include "game.h"
#include "player.h"
#include "pistoler.h"
#include "bazooker.h"
#include "sniper.h"
Game::Game()
{
    map = new Board("mapa.txt");
    map->addMobile(new Player(map,3,500, 20, 30));
    numberOfBazookers=1;
    numberOfPistolers=1;
    numberOfSnipers=1;
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
    for(int i=0;i<numberOfBazookers;i++)
    {
        map->addMobile(new Bazooker(map,1,600, 30, 40));
    }
    for(int i=0;i<numberOfPistolers;i++)
    {
        map->addMobile(new Pistoler(map,2,1000, 20, 30));
    }
    for(int i=0;i<numberOfSnipers;i++)
    {
        map->addMobile(new Sniper(map,0,400, 20, 30));
    }
}

void Game::updateGame()
{
    Player* tmpPlayer;
    for (int i=0; i<map->getNumberOfMobiles(); i++)
    {
        if(map->getMobile(i)->getToRemove())
        {
            delete (map->getMobile(i));
            map->removeMobile(i);
        }
        else
        {
            map->getMobile(i)->move(map);
            map->getMobile(i)->checkField(map);
            tmpPlayer=dynamic_cast<Player*>(map->getMobile(i));
            if(tmpPlayer)
            {
                tmpPlayer->ChangeWeapon();
            }
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
