#include <iostream>

#include "gwindow.h"

int main( int argc, char* args[] )
{


    //The window we'll be rendering to
    SDL_Window* window = NULL;

    //The surface contained by the window
    SDL_Surface* screenSurface = NULL;

    SDL_Surface *aa=SDL_LoadBMP("trawa.bmp");

    //Initialize SDL
    if( SDL_Init( SDL_INIT_EVERYTHING) < 0 )
    {
        std::cout<< "SDL could not initialize! SDL_Error: %s\n"<< SDL_GetError();
    }
    else
    {
        //Create window
        window = SDL_CreateWindow( "Obrona stalingradu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            std::cout<<"Window could not be created! SDL_Error: %s\n"<<SDL_GetError();
        }
        else
        {
            //Get window surface
            screenSurface = SDL_GetWindowSurface( window );

            SDL_BlitSurface( aa, NULL, screenSurface, NULL );

            //Update the surface
            SDL_UpdateWindowSurface( window );

            //Wait two seconds
            SDL_Delay( 2000 );
        }
    }

    //Destroy window
    SDL_DestroyWindow( window );

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}
