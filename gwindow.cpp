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
        player=SDL_LoadBMP("czolg.bmp");
        enemy=SDL_LoadBMP("enemy.bmp");
        if(background==NULL || wall == NULL || player == NULL || enemy == NULL || mud==NULL || barbwire==NULL)
        {
            std::cout<<"SDL could not load bmp files:"<< SDL_GetError();
        }
        else
        {
            SDL_SetColorKey(player, SDL_TRUE, SDL_MapRGB(player->format, 255, 255, 255));
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
    for (int i=0; i<game->getMapPtr()->getNumberOfCreature(); i++)
    {
        game->getMapPtr()->getCreature(i)->move();
    }

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
}

void GWindow::showCreatures()
{
    SDL_Rect dts;
    for(int i=0;i<game->getMapPtr()->getNumberOfCreature();i++)
    {
        dts.x=game->getMapPtr()->getCreature(i)->getX();
        dts.y=game->getMapPtr()->getCreature(i)->getY();
        if(typeid(*(game->getMapPtr()->getCreature(i)))==typeid(Player))
        {
            game->getMapPtr()->getCreature(i)->setHeight(player->h);
            game->getMapPtr()->getCreature(i)->setWidth(player->w);
            SDL_BlitSurface(player,NULL,screenSurface,&dts);
        }
        if(typeid(*(game->getMapPtr()->getCreature(i)))==typeid(Enemy))
        {
            game->getMapPtr()->getCreature(i)->setHeight(enemy->h);
            game->getMapPtr()->getCreature(i)->setWidth(enemy->w);
            SDL_BlitSurface(enemy,NULL,screenSurface,&dts);
        }
    }
}
void GWindow::showBackground()
{
    SDL_BlitSurface( background, NULL, screenSurface, NULL );
}




//GWindow::GWindow()
//{
//    game=new Game();
//    Window=NULL;
//    Renderer=NULL;
//    wall1 = NULL;
//    barbwire1 = NULL;
//    mud1 = NULL;
//    background1=NULL;
//    player1=NULL;
//    enemy1=NULL;
//    if(!init())
//    {
//        std::cout<<"Failed to initialize\n";
//    }
//    else
//    {
//        if( !loadMedia() )
//        {
//            std::cout<< "Failed to load media!\n";
//        }
//        else
//        {
//            SDL_RenderClear( Renderer );
//        }
//    }
//}

//GWindow::~GWindow()
//{
//    delete game;
//    SDL_DestroyTexture(background1);
//    background1=NULL;
//    SDL_DestroyTexture(player1);
//    player1=NULL;
//    SDL_DestroyTexture(enemy1);
//    enemy1=NULL;
//    SDL_DestroyTexture(wall1);
//    wall1=NULL;
//    SDL_DestroyTexture(mud1);
//    mud1=NULL;
//    SDL_DestroyTexture(barbwire1);
//    barbwire1=NULL;

//    SDL_DestroyRenderer( Renderer );
//    SDL_DestroyWindow( Window );
//    Window = NULL;
//    Renderer = NULL;

//    SDL_Quit();
//}

//bool GWindow::init()
//{
//    bool success = true;

//    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
//    {
//        std::cout<< "SDL could not initialize! SDL Error: %s\n", SDL_GetError();
//        success = false;
//    }
//    else
//    {
//        //Set texture filtering to linear
//        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
//        {
//            std::cout<< "Warning: Linear texture filtering not enabled!";
//        }
//        Window = SDL_CreateWindow( "Obrona stalingradu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, game->getMapPtr()->getWidth(),game->getMapPtr()->getHeight(), SDL_WINDOW_SHOWN );
//        if( Window == NULL )
//        {
//            std::cout<<"Window could not be created! SDL Error: %s\n", SDL_GetError();
//            success = false;
//        }
//        else
//        {
//            Renderer = SDL_CreateRenderer( Window, -1, SDL_RENDERER_ACCELERATED );
//            if( Renderer == NULL )
//            {
//                std::cout<<"Renderer could not be created! SDL Error: %s\n", SDL_GetError();
//                success = false;
//            }
//            else
//            {
//                SDL_SetRenderDrawColor( Renderer, 0, 0, 0, 0 );
//            }
//        }
//    }
//    return success;
//}

//SDL_Texture* GWindow::loadTexture( std::string path )
//{
//    SDL_Texture* newTexture = NULL;

//    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str() );
//    if( loadedSurface == NULL )
//    {
//        std::cout<<"Unable to load BMP %s! SDL_LoadBMP Error: %s\n", path.c_str(), SDL_GetError();
//    }
//    else
//    {
//        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 255, 255, 255));
//        newTexture = SDL_CreateTextureFromSurface( Renderer, loadedSurface );
//        if( newTexture == NULL )
//        {
//            std::cout<<"Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError();
//        }
//        SDL_FreeSurface( loadedSurface );
//    }

//    return newTexture;
//}

//bool  GWindow::loadMedia()
//{
//    bool success = true;
//    background1=loadTexture("trawa.bmp");
//    wall1 =loadTexture("wall.bmp");
//    player1=loadTexture("czolg.bmp");
//    enemy1=loadTexture("enemy.bmp");
//    mud1 = loadTexture("mud.bmp");
//    barbwire1 = loadTexture("barbwire.bmp");

//    if(background1==NULL || wall1 == NULL || player1 == NULL || enemy1 == NULL || mud1==NULL || barbwire1==NULL)
//    {
//        std::cout<<"Failed to load texture image!\n";
//        success =false;
//    }

//    return success;
//}

//void GWindow::timerUpdate()
//{
//    for (int i=0; i<game->getMapPtr()->getNumberOfCreature(); i++)
//    {
//        game->getMapPtr()->getCreature(i)->move();
//    }

////    showBackground();
////    showObstacles();
////    showCreatures();
////    SDL_RenderPresent(Renderer);
//}

//void GWindow::UpdateImage()
//{
//        showBackground();
//        showObstacles();
//        showCreatures();
//        SDL_RenderPresent(Renderer);
//}

//void GWindow::showObstacles()
//{
//    SDL_Rect dst;
//    for(int i=0;i<game->getMapPtr()->getNumberOfObstacle();i++)
//    {
//        dst.x=game->getMapPtr()->getObstacle(i)->getX();
//        dst.y=game->getMapPtr()->getObstacle(i)->getY();
//        dst.h=game->getMapPtr()->getObstacle(i)->getHeight();
//        dst.w=game->getMapPtr()->getObstacle(i)->getWidth();
//        if(typeid(*(game->getMapPtr()->getObstacle(i)))== typeid(Wall))
//        {
//            SDL_RenderCopy(Renderer,wall1,NULL,&dst);
//        }
//        if(typeid(*(game->getMapPtr()->getObstacle(i)))== typeid(Barbwire))
//        {
//            SDL_RenderCopy(Renderer,barbwire1,NULL,&dst);
//        }
//        if(typeid(*(game->getMapPtr()->getObstacle(i)))== typeid(Mud))
//        {
//            SDL_RenderCopy(Renderer,mud1,NULL,&dst);
//        }
//    }
//}

//void GWindow::showCreatures()
//{
//    SDL_Rect dts;
//    for(int i=0;i<game->getMapPtr()->getNumberOfCreature();i++)
//    {
//        dts.x=game->getMapPtr()->getCreature(i)->getX();
//        dts.y=game->getMapPtr()->getCreature(i)->getY();
//        dts.h=game->getMapPtr()->getCreature(i)->getHeight();
//        dts.w=game->getMapPtr()->getCreature(i)->getWidth();
//        if(typeid(*(game->getMapPtr()->getCreature(i)))==typeid(Player))
//        {
//            SDL_RenderCopy(Renderer,player1,NULL,&dts);
//        }
//        if(typeid(*(game->getMapPtr()->getCreature(i)))==typeid(Enemy))
//        {
//            SDL_RenderCopy(Renderer,enemy1,NULL,&dts);
//        }
//    }
//}
//void GWindow::showBackground()
//{
//    SDL_RenderCopy(Renderer,background1,NULL,NULL);
//}

