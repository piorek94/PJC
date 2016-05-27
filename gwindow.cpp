#include "gwindow.h"

GWindow::GWindow(std::string _plik)
{
    window = NULL;
    screenSurface = NULL;
    background=SDL_LoadBMP(_plik.c_str());
    if( SDL_Init( SDL_INIT_EVERYTHING) < 0 )
    {
        std::cout<< "SDL could not initialize! SDL_Error: %s\n"<< SDL_GetError();
    }
    else
    {
        if(background!=NULL)
        {
            window = SDL_CreateWindow( "Obrona stalingradu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, background->w, background->h, SDL_WINDOW_SHOWN );
            if( window == NULL )
            {
                std::cout<<"Window could not be created! SDL_Error: %s\n"<<SDL_GetError();
            }
            else
            {
                screenSurface = SDL_GetWindowSurface( window );
                SDL_BlitSurface( background, NULL, screenSurface, NULL );
            }
        }
        else
        {
            std::cout<<"SDL could not load bmp map:"<< SDL_GetError();
        }
    }

}
GWindow::~GWindow()
{
    SDL_FreeSurface(screenSurface);
    SDL_FreeSurface(background);
    SDL_FreeSurface(player);
    SDL_FreeSurface(enemy);
    SDL_FreeSurface(wall);
    screenSurface=NULL;
    background=NULL;
    player=NULL;
    enemy=NULL;
    wall=NULL;
    SDL_DestroyWindow( window );
    SDL_Quit();
}

void GWindow::timerUpdate()
{
    SDL_UpdateWindowSurface(window);
}
