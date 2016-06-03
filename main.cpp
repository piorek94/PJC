#include <ctime>
#include "gwindow.h"

Uint32 callback( Uint32 interval, void* param );
GWindow* mainWindow;
SDL_TimerID timer;
//const Uint8 * keystate = SDL_GetKeyboardState( NULL ); do ruchu
int main( int argc, char* args[] )
{    
    srand(time(0));
    mainWindow = new GWindow();
    timer = SDL_AddTimer(50, callback, NULL );
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
    mainWindow->timerUpdate();
    return interval;
}
