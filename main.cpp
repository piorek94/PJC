#include <iostream>
#include <ctime>
#include "gwindow.h"

Uint32 callback( Uint32 interval, void* param );
GWindow* mainWindow;
int main( int argc, char* args[] )
{
    SDL_TimerID timer;
    srand(time(0));
    const char *a="trawa.bmp";
    mainWindow = new GWindow(a);
    timer = SDL_AddTimer( 15, callback, NULL );
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
