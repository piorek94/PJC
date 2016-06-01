#include "gwindow.h"
#include <typeinfo>
GWindow::GWindow()
{
    game=new Game();
    if( SDL_Init( SDL_INIT_EVERYTHING) < 0 )
    {
        std::cout<< "SDL could not initialize! SDL_Error: %s\n"<< SDL_GetError();
    }
    else
    {
        window = NULL;
        screenSurface = NULL;
        wall = SDL_LoadBMP("wall.bmp");
        barbwire = SDL_LoadBMP("barbwire.bmp");
        mud = SDL_LoadBMP("mud.bmp");
        background=SDL_LoadBMP("trawa.bmp");
        player=SDL_LoadBMP("player.bmp");
        enemy=SDL_LoadBMP("enemy.bmp");
        if(background==NULL || wall == NULL || player == NULL || enemy == NULL)
        {
            std::cout<<"SDL could not load bmp files:"<< SDL_GetError();
        }
        else
        {
            SDL_SetColorKey(player, SDL_TRUE, SDL_MapRGB(enemy->format, 255, 255, 255));
            SDL_SetColorKey(enemy, SDL_TRUE, SDL_MapRGB(enemy->format, 255, 255, 255));
            SDL_SetColorKey(barbwire, SDL_TRUE, SDL_MapRGB(barbwire->format, 255, 255, 255));
//----------------------------------------------------------------------------------------------------------------------
            if(game->getMapPtr()->getHeight()>background->h)
            {
                game->getMapPtr()->setHeight(background->h);
            }
            if(game->getMapPtr()->getWidth()>background->w)
            {
                game->getMapPtr()->setWidth(background->w);
            }
            std::cout<<game->getMapPtr()->getWidth()<<"x"<<game->getMapPtr()->getHeight();
//----------------------------------------------------------------------------------------------------------------------
            window = SDL_CreateWindow( "Obrona stalingradu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, game->getMapPtr()->getWidth(),game->getMapPtr()->getHeight(), SDL_WINDOW_SHOWN );
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
    delete game;
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
    showBackground();
    showObstacles();
    showCreatures();
    SDL_UpdateWindowSurface(window);
}

void GWindow::showObstacles()
{
    SDL_Rect dst;
    for(int i=0;i<game->getMapPtr()->getNumberOfObstacle();i++)
    {
        dst.x=game->getMapPtr()->getObstacle(i)->getX();
        dst.y=game->getMapPtr()->getObstacle(i)->getY();
        if(typeid(*(game->getMapPtr()->getObstacle(i)))== typeid(Wall))
        {
        game->getMapPtr()->getObstacle(i)->setHeight(wall->h);
        game->getMapPtr()->getObstacle(i)->setWidth(wall->w);
        SDL_BlitSurface(wall,NULL,screenSurface,&dst);
        }
        if(typeid(*(game->getMapPtr()->getObstacle(i)))== typeid(Barbwire))
        {
        game->getMapPtr()->getObstacle(i)->setHeight(barbwire->h);
        game->getMapPtr()->getObstacle(i)->setWidth(barbwire->w);
        SDL_BlitSurface(barbwire,NULL,screenSurface,&dst);
        }
        if(typeid(*(game->getMapPtr()->getObstacle(i)))== typeid(Mud))
        {
        game->getMapPtr()->getObstacle(i)->setHeight(mud->h);
        game->getMapPtr()->getObstacle(i)->setWidth(mud->w);
        SDL_BlitSurface(mud,NULL,screenSurface,&dst);
        }
    }



//    SDL_Rect docelowy;
//    docelowy.w = sciana->w;
//    docelowy.h = sciana->h;

//    //std::cout<< "ok";
//    for (int i=0; i<gra1->getMapaWsk()->getRozmiarMapyY(); i++)
//    {
//        docelowy.y = i*docelowy.h;
//        for (int j=0; j<gra1->getMapaWsk()->getRozmiarMapyX(); j++)
//        {
//            docelowy.x = j*docelowy.w;

//            if ( typeid(*(gra1->getMapaWsk()->getElementMapy(j,i))) == typeid (CSciana) )
//            {
//                SDL_BlitSurface( sciana, NULL, sdl_screen_surface, &docelowy );
//            }
//            else if (typeid(*(gra1->getMapaWsk()->getElementMapy(j,i))) == typeid (CWolnePole))
//            {
//                SDL_BlitSurface( wolne_pole, NULL, sdl_screen_surface, &docelowy );
//            }
//        }
//    }



}

void GWindow::showCreatures()
{
    SDL_Rect dts;
    dts.x=300;
    dts.y=350;
    SDL_BlitSurface(player,NULL,screenSurface,&dts);
}

void GWindow::showBackground()
{
    SDL_BlitSurface( background, NULL, screenSurface, NULL );
}
