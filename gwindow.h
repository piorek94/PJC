#ifndef GWINDOW_H
#define GWINDOW_H

#include <SDL.h>
#include "game.h"
#include <iostream>
class Creature;
class GWindow
{
private:
    SDL_Window *window;
    SDL_Surface *screenSurface;
    SDL_Surface *background;
    SDL_Surface *player;
    SDL_Surface *enemy;
    SDL_Surface *wall;
    SDL_Surface *barbwire;
    SDL_Surface *mud;
    SDL_Surface *lose;
    SDL_Surface *win;
    SDL_Surface *sniper;
    SDL_Surface *bazooka;
    SDL_Surface *pistol;
    SDL_Surface *sniperrifle;
//    SDL_Surface *bullet;
    Game* game;
    SDL_Surface* loadSurface( std::string path );
    void showObstacles();
    void showMobiles();
    void showBackground();
    void showWin();
    void showLose();
    void showHp(Creature *_creature);
    void ShowWeapons(Creature *_creature);
public:
    Game *getGamePtr();
    bool init();
    bool loadMedia();
    GWindow();
    void timerUpdate();
    ~GWindow();
};
#endif // GWINDOW_H
