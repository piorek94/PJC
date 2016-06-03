#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include "imobile.h"

class Creature : public IMobile
{
protected:
    Board* Map;
    int Hp;
    int MaxHp;
    int X;
    int Y;
    int Height;
    int Width;
    std::string Name;
    float Speed;
public:
    Creature(Board *_map);
    virtual ~Creature();
    virtual void move()=0;
    virtual void rotate(float _angle)=0;
    virtual void shoot()=0;
    virtual void setWeapon()=0;
    bool checkCollision(Board *map);
    int getX();
    int getY();
    void setX(int _x);
    void setY(int _y);
    int getWidth();
    int getHeight();
    void setWidth(int _width);
    void setHeight(int _height);
    bool isDead();
    int getHp();
    void setHp(int _hp);
    int getMaxHp();
    void setMaxHp(int _maxhp);
    void setName(std::string _name);
    std::string getName();
    void setSpeed(float _speed);
    float getSpeed();
};
//tutaj jeszcze kolizje przydałoby sie sprawdzac i tu mozna dac mape a w innych wywołuywac kontruktor tej klasy z mapa
//mapa jako pole, ewentualnie dac jako argument funkcji poruszanie, która
//bedzie przekazywała ten argument do funkcji kolizji- góra, doł, lewo, prawo
#endif // CREATURE_H
