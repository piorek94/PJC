#include "game.h"

Game::Game()
{
    map = new Board("mapa.txt");
}

Game::~Game()
{
    delete map;
}

Board* Game::getMapPtr()
{
    return map;
}

//int Game::getNumberOfCreatures()
//{
//    return numberOfCreatures;
//}

//Creature *Game::getCreaturePtr(int numer)
//{
//    return osoby.at(numer);
//}

//void Game::setNumberOfCreatures(int _num)
//{
//    numberOfCreatures=_num;
//    for(int i=0; i<=numberOfCreatures;i++)
//    {
//        map->addCreature(new Player());//ale tu bedzie new Enemy
//    }
//}
