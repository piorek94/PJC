#include "gwindow.h"

Uint32 callback( Uint32 interval, void* param );
GWindow* mainWindow;
SDL_TimerID timer;

bool move_up = false;
bool move_down = false;
bool move_right = false;
bool move_left = false;
bool pistolOn = false;
bool sniperrifleOn = false;
bool bazookaOn = false;

const Uint8 * keystate = SDL_GetKeyboardState( NULL );
SDL_Event change;
int main( int argc, char* args[] )
{
    mainWindow=new GWindow();
    if(!mainWindow->init())
    {
        std::cout<<"Failed to initialize!\n";
    }
    else
    {
        if(!mainWindow->loadMedia())
        {
            std::cout<<"Failed to load media!\n";
        }
        else
        {
            timer = SDL_AddTimer(60, callback, NULL);
            bool quit=false;
            SDL_Event e;
            while (!quit)
            {
                while ((SDL_PollEvent(&e)) != 0)
                {
                    if (e.type == SDL_QUIT)
                    {
                        quit = true;
                    }
                }
            }
        }
    }
    SDL_RemoveTimer(timer);
    delete mainWindow;
    return 0;
}

Uint32 callback(Uint32 interval, void *param)
{
    if( keystate[ SDL_SCANCODE_RIGHT ] )
    {
        move_right = true;
    }
    else{
        move_right = false;
    }

    if( keystate[ SDL_SCANCODE_LEFT ] )
    {
        move_left = true;
    }
    else{
        move_left = false;
    }

    if( keystate[ SDL_SCANCODE_UP ] )
    {
        move_up = true;
    }
    else{
        move_up = false;
    }

    if( keystate[ SDL_SCANCODE_DOWN ] )
    {
        move_down = true;
    }
    else{
        move_down = false;
    }
    if ( keystate[ SDL_SCANCODE_1 ] )
    {
        pistolOn=true;
        bazookaOn=false;
        sniperrifleOn=false;
    }
    if ( keystate[ SDL_SCANCODE_2 ] )
    {
        pistolOn=false;
        bazookaOn=true;
        sniperrifleOn=false;
    }
    if ( keystate[ SDL_SCANCODE_3 ] )
    {
        pistolOn=false;
        bazookaOn=false;
        sniperrifleOn=true;
    }
    mainWindow->timerUpdate();
    return interval;
}
