#include "board.h"
#include <fstream>

Board::Board(std::string _plik)
{
    this->loadBoard(_plik);
}

Board::~Board()
{
    for(size_t i=0;i<obstacles.size();i++)
    {
        delete getObstacle(i);
    }
    clearObstacle();
}

int Board::getHeight()
{
    return Height;
}

int Board::getWidth()
{
    return Width;
}

void Board::setHeight(int _height)
{
    Height=_height;
}

void Board::setWidth(int _width)
{
    Width=_width;
}

Creature* Board::getCreature(int c)
{
    return creatures.at(c);
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
    int pomH,pomW,numOfObs,tmp,posX,posY;
    source >> pomW;
    source >> pomH;
    setHeight(pomH);
    setWidth(pomW);

    source >> numOfObs;

    for(int i=0;i<numOfObs;i++)
    {
            Obstacle* obs;
            source >> tmp;
            source >> posX;
            source >> posY;
       if(tmp==1)
       {
           obs = new Wall(posX,posY);
       }
       if(tmp==2)
       {
           obs = new Mud(posX,posY,1);
       }
       if(tmp==3)
       {
           obs = new Barbwire(posX,posY,1);
       }
            addObstacle(obs);
    }
    source.close();

    return true;
}

void Board:: addCreature(Creature* _creature)
{
    creatures.push_back(_creature);
}

void Board::addObstacle(Obstacle* _obstacle)
{
    obstacles.push_back(_obstacle);
}

int Board::getNumberOfObstacle()
{
    return (int)obstacles.size();
}

int Board::getNumberOfCreature()
{
    return (int)creatures.size();
}

void Board::clearCreature()
{
    creatures.clear();
}

void Board::clearObstacle()
{
    obstacles.clear();
}
