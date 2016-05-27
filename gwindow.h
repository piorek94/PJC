#ifndef GWINDOW_H
#define GWINDOW_H

#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <board.h>

class GWindow
{
private:
    Board* mapa;
    SDL_Window *window;
    SDL_Surface *screenSurface;
    SDL_Surface *background;
    SDL_Surface *player;
    SDL_Surface *enemy;
    SDL_Surface *wall;
    void showObstacles(/*std::string _imgObstacle*/);
    void showCreatures(std::string _imgCreature);
    void showBackGround(std::string _imgBackground);
public:
    GWindow(std::string _plik);
    void timerUpdate();
    ~GWindow();
};

#endif // GWINDOW_H
