#include "gwindow.h"
#include <typeinfo>
GWindow::GWindow()
{
    game=new Game(1);
    window=NULL;
    screenSurface=NULL;
    background=NULL;
    player=NULL;
    enemy=NULL;
    wall=NULL;
    barbwire=NULL;
    mud=NULL;
    lose=NULL;
    win=NULL;
}

bool GWindow::init()
{
    bool success = true;
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        std::cout<< "SDL could not initialize! SDL_Error: %s\n"<< SDL_GetError();
        success = false;
    }
    else
    {
        window = SDL_CreateWindow( "Obrona stalingradu", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, game->getMapPtr()->getWidth(),game->getMapPtr()->getHeight(), SDL_WINDOW_SHOWN );
        if( window == NULL )
        {
            std::cout<<"Window could not be created! SDL_Error: %s\n"<<SDL_GetError();
            success = false;
        }
        else
        {
            screenSurface = SDL_GetWindowSurface( window );
        }
    }

    return success;
}

GWindow::~GWindow()
{
    delete game;
    SDL_FreeSurface(screenSurface);
    SDL_FreeSurface(background);
    SDL_FreeSurface(player);
    SDL_FreeSurface(enemy);
    SDL_FreeSurface(wall);
    SDL_FreeSurface(barbwire);
    SDL_FreeSurface(mud);
    SDL_FreeSurface(lose);
    SDL_FreeSurface(win);
    screenSurface=NULL;
    background=NULL;
    player=NULL;
    enemy=NULL;
    wall=NULL;
    barbwire=NULL;
    mud=NULL;
    lose=NULL;
    win=NULL;
    SDL_DestroyWindow( window );
    SDL_Quit();
}

void GWindow::timerUpdate()
{
    if( !(game->lose() || game->win()) )
    {
    game->updateGame();
    showBackground();
    showObstacles();
    showCreatures();
    }
    else if(game->win())
    {
        showWin();
    }
    else if(game->lose())
    {
        showLose();
    }
    SDL_UpdateWindowSurface(window);
}

void GWindow::showObstacles()
{
    SDL_Rect dst;
    for(int i=0;i<game->getMapPtr()->getNumberOfObstacle();i++)
    {
        dst.x=game->getMapPtr()->getObstacle(i)->getX();
        dst.y=game->getMapPtr()->getObstacle(i)->getY();
        dst.w=game->getMapPtr()->getObstacle(i)->getWidth();
        dst.h=game->getMapPtr()->getObstacle(i)->getHeight();
        if(typeid(*(game->getMapPtr()->getObstacle(i)))== typeid(Wall))
        {
        SDL_BlitScaled(wall,NULL,screenSurface,&dst);
        }
        if(typeid(*(game->getMapPtr()->getObstacle(i)))== typeid(Barbwire))
        {
        SDL_BlitScaled(barbwire,NULL,screenSurface,&dst);
        }
        if(typeid(*(game->getMapPtr()->getObstacle(i)))== typeid(Mud))
        {
        SDL_BlitScaled(mud,NULL,screenSurface,&dst);
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
        dts.w=game->getMapPtr()->getCreature(i)->getWidth();
        dts.h=game->getMapPtr()->getCreature(i)->getHeight();
        if(typeid(*(game->getMapPtr()->getCreature(i)))==typeid(Player))
        {
            SDL_BlitScaled(player,NULL,screenSurface,&dts);
        }
        if(typeid(*(game->getMapPtr()->getCreature(i)))==typeid(Enemy))
        {
            SDL_BlitScaled(enemy,NULL,screenSurface,&dts);
        }
        showHp(game->getMapPtr()->getCreature(i));
    }
}

void GWindow::showHp(Creature *_creature)
{
    SDL_Rect max,current;
    max.x=_creature->getX();
    max.w=_creature->getWidth();
    max.y=_creature->getY()-8;
    max.h=7;
    SDL_FillRect(screenSurface,&max,SDL_MapRGB(screenSurface->format, 0, 0, 0));
    current.x=max.x+1;
    current.y=max.y+1;
    current.h=max.h-2;
    current.w=((max.w*_creature->getHp())/_creature->getMaxHp())-2;
    SDL_FillRect(screenSurface,&current,SDL_MapRGB(screenSurface->format, 255, 0, 0));
}

void GWindow::showBackground()
{
    SDL_BlitScaled( background, NULL, screenSurface, NULL );
}

void GWindow::showWin()
{
    SDL_BlitScaled( win, NULL, screenSurface, NULL );
}

void GWindow::showLose()
{
    SDL_BlitScaled( lose, NULL, screenSurface, NULL );
}

bool  GWindow::loadMedia()
{
    bool success = true;
    background=loadSurface("trawa.bmp");
    wall =loadSurface("wall.bmp");
    player=loadSurface("soilder.bmp");
    enemy=loadSurface("enemy1.bmp");
    mud = loadSurface("mud.bmp");
    barbwire = loadSurface("barbwire.bmp");
    lose = loadSurface("lose.bmp");
    win = loadSurface("win.bmp");

    if(background==NULL || wall == NULL || player == NULL || enemy == NULL || mud==NULL || barbwire==NULL || lose == NULL || win == NULL)
    {
        std::cout<<"Failed to load texture image!\n";
        success =false;
    }

    return success;
}

SDL_Surface* GWindow::loadSurface( std::string path )
{
    SDL_Surface* newSurface = NULL;
    newSurface=SDL_LoadBMP(path.c_str());
    if(newSurface==NULL)
    {
        std::cout<<"Unable to load BMP %s! SDL_LoadBMP Error: %s\n", path.c_str(), SDL_GetError();
    }
    else
    {
        SDL_SetColorKey(newSurface, SDL_TRUE, SDL_MapRGB(newSurface->format,255,255,255));
    }
    return newSurface;
}
