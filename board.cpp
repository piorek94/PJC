#include "board.h"
#include "wall.h"
#include "barbwire.h"
#include "mud.h"
#include <fstream>

Board::Board(std::string _file)
{
    this->loadBoard(_file);
}

Board::~Board()
{
    for(size_t i=0;i<obstacles.size();i++)
    {
        delete getObstacle(i);
    }
    obstacles.clear();
}

Mobile *Board::getMobile(int c)
{
    return mobiles.at(c);
}

Obstacle* Board::getObstacle(int o)
{
    return obstacles.at(o);
}

bool Board::loadBoard(std::string _pathBoard)
{
    std::fstream source;
    source.open(_pathBoard,std::ios::in);
    if ( !source.is_open() )
    {
        return false;
    }
    int numOfObs,tmp,posX,posY;
    source >> Width;
    source >> Height;

    source >> numOfObs;

    for(int i=0;i<numOfObs;i++)
    {
            Obstacle* obs;
            source >> tmp;
            source >> posX;
            source >> posY;
       if(tmp==wall)
       {
           obs = new Wall(posX,posY);
       }
       if(tmp==mud)
       {
           obs = new Mud(posX,posY,2);
       }
       if(tmp==barbwire)
       {
           obs = new Barbwire(posX,posY,2);
       }
       obstacles.push_back(obs);
    }
    source.close();

    return true;
}

void Board::addMobile(Mobile *_mobile)
{
    mobiles.push_back(_mobile);
}

int Board::getNumberOfObstacle()
{
    return (int)obstacles.size();
}

int Board::getNumberOfMobiles()
{
    return (int)mobiles.size();
}

void Board::clearMobiles()
{
    mobiles.clear();
}

void Board::removeMobile(int i)
{
    mobiles.erase(mobiles.begin()+i);
}
