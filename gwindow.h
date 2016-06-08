#ifndef GWINDOW_H
#define GWINDOW_H

#include <SDL.h>
//#include <SDL2/SDL_image.h>
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
    void showObstacles();
    void showCreatures();
    void showBackground();

//    SDL_Window* Window;
//    SDL_Renderer* Renderer;
//    SDL_Texture* wall1;
//    SDL_Texture* barbwire1;
//    SDL_Texture* mud1;
//    SDL_Texture* background1;
//    SDL_Texture* player1;
//    SDL_Texture* enemy1;
//    bool init();
//    SDL_Texture* loadTexture( std::string path );
//    bool loadMedia();
public:
//    void UpdateImage();//jesli textury
    GWindow();
    void timerUpdate();
    ~GWindow();
};
#endif // GWINDOW_H
