#ifndef GWINDOW_H
#define GWINDOW_H

#include <SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

//Screen dimension constants
const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 1024;

class GWindow
{
private:
    SDL_Window *window;
    SDL_Surface *screenSurface;
    SDL_Surface *background;
    SDL_Surface *player;
    SDL_Surface *enemy;
    SDL_Surface *wall;
    void wyswietlMape ();
public:
    GWindow(std::string _plik);
    void timerUpdate();
    ~GWindow();
};

#endif // GWINDOW_H
