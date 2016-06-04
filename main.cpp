#include <ctime>
#include "gwindow.h"

Uint32 callback( Uint32 interval, void* param );
GWindow* mainWindow;
SDL_TimerID timer;

bool move_up = false;
bool move_down = false;
bool move_right = false;
bool move_left = false;

const Uint8 * keystate = SDL_GetKeyboardState( NULL );

int main( int argc, char* args[] )
{    
    srand(time(0));
    mainWindow = new GWindow();
    timer = SDL_AddTimer(70, callback, NULL );
    SDL_Event e;
    bool game=1;
    while (game)
    {
        while ((SDL_PollEvent(&e)) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                game = false;
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
    mainWindow->timerUpdate();
    return interval;
}
