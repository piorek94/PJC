﻿#include "gwindow.h"

Uint32 callback( Uint32 interval, void* param );
Uint32 callbackPistol( Uint32 interval, void* param );
Uint32 callbackBazooka( Uint32 interval, void* param );
Uint32 callbackSniper( Uint32 interval, void* param );

GWindow* mainWindow;
SDL_TimerID timerGame;
SDL_TimerID timerPistol;
SDL_TimerID timerBazooka;
SDL_TimerID timerSniper;

bool move_up = false;
bool move_down = false;
bool move_right = false;
bool move_left = false;
bool pistolOn = false;
bool sniperrifleOn = false;
bool bazookaOn = false;
bool PlayerShootOn = false;
int PlayerDstX = 0;
int PlayerDstY = 0;

const Uint8 * keystate = SDL_GetKeyboardState( NULL );
void handleEvent(SDL_Event *e);
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
            timerGame = SDL_AddTimer(60, callback, NULL);
            timerPistol = SDL_AddTimer(500, callbackPistol, NULL);
            timerBazooka = SDL_AddTimer(1500, callbackBazooka, NULL);
            timerSniper = SDL_AddTimer(2000, callbackSniper, NULL);

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
                    handleEvent(&e);
                }
            }
        }
    }
    SDL_RemoveTimer(timerGame);
    delete mainWindow;
    return 0;
}

Uint32 callback(Uint32 interval, void *param)
{
    if( keystate[ SDL_SCANCODE_D ] )
    {
        move_right = true;
    }
    else{
        move_right = false;
    }

    if( keystate[ SDL_SCANCODE_A ] )
    {
        move_left = true;
    }
    else{
        move_left = false;
    }

    if( keystate[ SDL_SCANCODE_W ] )
    {
        move_up = true;
    }
    else{
        move_up = false;
    }

    if( keystate[ SDL_SCANCODE_S ] )
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

Uint32 callbackPistol(Uint32 interval, void *param)
{
    mainWindow->getGamePtr()->PistolShoot();
    return interval;
}

Uint32 callbackBazooka(Uint32 interval, void *param)
{
    mainWindow->getGamePtr()->BazookaShoot();
    return interval;
}

Uint32 callbackSniper(Uint32 interval, void *param)
{
    mainWindow->getGamePtr()->SniperShoot();
    return interval;
}

void handleEvent(SDL_Event *e)
{
    if(e->type == SDL_MOUSEMOTION)
    {
        SDL_GetMouseState( &PlayerDstX, &PlayerDstY );
    }
    if(e->type == SDL_MOUSEBUTTONDOWN)
    {
        PlayerShootOn=true;
        SDL_GetMouseState( &PlayerDstX, &PlayerDstY );
    }
    if(e->type == SDL_MOUSEBUTTONUP)
    {
        PlayerShootOn=false;
    }
}
