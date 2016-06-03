#ifndef GWINDOW_H
#define GWINDOW_H

#include <SDL.h>
//#include <SDL2/SDL_image.h>
#include "game.h"

class GWindow
{
private:
    Game* game;
    SDL_Window *window;
    SDL_Surface *screenSurface;
    SDL_Surface *background;
    SDL_Surface *player;
    SDL_Surface *enemy;
    SDL_Surface *wall;
    SDL_Surface *barbwire;
    SDL_Surface *mud;
    void showObstacles();
    void showCreatures();
    void showBackground();
public:
    GWindow();
    void timerUpdate();
    ~GWindow();
};
#endif // GWINDOW_H
