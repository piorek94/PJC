#include "gwindow.h"
#include <vector>

GWindow::GWindow(std::string _plik)
{
    mapa=new Board(_plik.c_str());
    window = NULL;
    screenSurface = NULL;
    wall = SDL_LoadBMP("wall.bmp");
    background=SDL_LoadBMP("trawa.bmp");
    player=SDL_LoadBMP("player.bmp");
    enemy=SDL_LoadBMP("enemy.bmp");
    if( SDL_Init( SDL_INIT_EVERYTHING) < 0 )
    {
        std::cout<< "SDL could not initialize! SDL_Error: %s\n"<< SDL_GetError();
    }
    else
    {
        if(background==NULL || wall == NULL || player == NULL || enemy == NULL)
        {
            std::cout<<"SDL could not load bmp files:"<< SDL_GetError();
        }
        else
        {
            SDL_SetColorKey(player, SDL_TRUE, SDL_MapRGB(enemy->format, 255, 255, 255));
            SDL_SetColorKey(enemy, SDL_TRUE, SDL_MapRGB(enemy->format, 255, 255, 255));

            if(mapa->getHeight()>background->h)
            {
                mapa->setHeight(background->h);
            }
            if(mapa->getWidth()>background->w)
            {
                mapa->setWidth(background->w);
            }
            window = SDL_CreateWindow( "Obrona stalingradu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, mapa->getWidth(),mapa->getWidth(), SDL_WINDOW_SHOWN );
            if( window == NULL )
            {
                std::cout<<"Window could not be created! SDL_Error: %s\n"<<SDL_GetError();
            }
            else
            {
                screenSurface = SDL_GetWindowSurface( window );
            }

        }
    }

}

GWindow::~GWindow()
{
    delete mapa;
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
    showBackGround();
    showObstacles();
    showCreatures();
    SDL_UpdateWindowSurface(window);
}

void GWindow::showObstacles()
{
    SDL_Rect dst;
    for(int i=0;i<mapa->getNumberOfObstacle();i++)
    {
        mapa->getObstacle(i)->setHeight(wall->h);
        mapa->getObstacle(i)->setWidth(wall->w);
        dst.x=mapa->getObstacle(i)->getX();
        dst.y=mapa->getObstacle(i)->getY();
        SDL_BlitSurface(wall,NULL,screenSurface,&dst);
    }
}

void GWindow::showCreatures()
{
//    SDL_Rect dts;
//    dts.x=300;
//    dts.y=350;
//    SDL_BlitSurface(player,NULL,screenSurface,&dts);
}

void GWindow::showBackGround()
{
    SDL_BlitSurface( background, NULL, screenSurface, NULL );
}
