#ifndef GWINDOW_H
#define GWINDOW_H

#include <SDL.h>
#include "game.h"

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
    Game* game;
    SDL_Surface* loadSurface( std::string path );
    void showObstacles();
    void showCreatures();
    void showBackground();
public:
    bool init();
    bool loadMedia();
    GWindow();
    void timerUpdate();
    ~GWindow();
};
#endif // GWINDOW_H
