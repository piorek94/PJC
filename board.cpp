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

Creature* Board::getCreature()
{

}

Obstacle* Board::getObstacle()
{

}

bool Board::loadBoard(std::string _pathBoard)
{
    std::fstream source;
    source.open(_pathBoard,std::ios::in);
    if ( !source.is_open() )
    {
        return false;
    }
    int pomH,pomW;
    source >> pomH;
    source >> pomW;

    this->setHeight(pomH);
    this->setWidth(pomW);

    source.close();

    return true;
}
