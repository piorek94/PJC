#include "board.h"
#include <fstream>
Board::Board(std::string _plik)
{
    this->loadBoard(_plik);
}

Board::~Board()
{

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
    int pomH,pomW,numOfObs,posX,posY;
    source >> pomH;
    source >> pomW;

    this->setHeight(pomH);
    this->setWidth(pomW);

    source >> numOfObs;

    for(int i=0;i<numOfObs;i++)
    {
            Obstacle* obs=new Obstacle;
            source >> posX;
            source >> posY;
            obs->setX(posX);
            obs->setY(posY);
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
