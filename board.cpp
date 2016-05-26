#include "board.h"

Board::Board()
{

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
