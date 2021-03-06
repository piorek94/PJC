#include "gwindow.h"
#include <typeinfo>
#include "player.h"
#include "sniper.h"
#include "pistol.h"
#include "bazooka.h"
#include "sniperrifle.h"
#include "wall.h"
#include "barbwire.h"
#include "mud.h"
#include "bullet.h"

GWindow::GWindow()
{
    game=new Game();
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
    sniper=NULL;
    bazooka=NULL;
    pistol=NULL;
    sniperrifle=NULL;
//    bullet=NULL;
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
        window = SDL_CreateWindow( "Obrona stalingradu", game->getMapPtr()->getX(), game->getMapPtr()->getY(), game->getMapPtr()->getWidth(),game->getMapPtr()->getHeight(), SDL_WINDOW_SHOWN );
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
    SDL_FreeSurface(sniper);
    SDL_FreeSurface(bazooka);
    SDL_FreeSurface(pistol);
    SDL_FreeSurface(sniperrifle);
//    SDL_FreeSurface(bullet);
    screenSurface=NULL;
    background=NULL;
    player=NULL;
    enemy=NULL;
    wall=NULL;
    barbwire=NULL;
    mud=NULL;
    lose=NULL;
    win=NULL;
    sniper=NULL;
    bazooka=NULL;
    pistol=NULL;
    sniperrifle=NULL;
//    bullet=NULL;
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
        showMobiles();
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

void GWindow::showMobiles()
{
    Creature *tmpCreature;
    Player *tmpPlayer;
    Enemy *tmpEnemy;
    Sniper *tmpSniper;
    Bullet *tmpBullet;
    SDL_Rect dts;
    for(int i=0;i<game->getMapPtr()->getNumberOfMobiles();i++)
    {
        dts.x=game->getMapPtr()->getMobile(i)->getX();
        dts.y=game->getMapPtr()->getMobile(i)->getY();
        dts.w=game->getMapPtr()->getMobile(i)->getWidth();
        dts.h=game->getMapPtr()->getMobile(i)->getHeight();

        tmpCreature=dynamic_cast<Creature*>(game->getMapPtr()->getMobile(i));
        tmpBullet=dynamic_cast<Bullet*>(game->getMapPtr()->getMobile(i));
        if(tmpCreature)
        {
            tmpPlayer=dynamic_cast<Player*>(game->getMapPtr()->getMobile(i));
            tmpEnemy=dynamic_cast<Enemy*>(game->getMapPtr()->getMobile(i));
            if(tmpPlayer)
            {
                SDL_BlitScaled(player,NULL,screenSurface,&dts);
            }
            else if(tmpEnemy)
            {
                tmpSniper=dynamic_cast<Sniper*>(game->getMapPtr()->getMobile(i));
                if(tmpSniper)
                {
                    SDL_BlitScaled(sniper,NULL,screenSurface,&dts);
                }
                else
                {
                    SDL_BlitScaled(enemy,NULL,screenSurface,&dts);
                }
            }
            showHp(tmpCreature);
            ShowWeapons(tmpCreature);
        }
        else if(tmpBullet)
        {
            SDL_BlitScaled(wall,NULL,screenSurface,&dts);
        }
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
    wall =loadSurface("wall1.bmp");
    player=loadSurface("soilder.bmp");
    enemy=loadSurface("enemy1.bmp");
    mud = loadSurface("mud1.bmp");
    barbwire = loadSurface("barbwire.bmp");
    lose = loadSurface("lose.bmp");
    win = loadSurface("win.bmp");
    sniper = loadSurface("sniper.bmp");
    bazooka = loadSurface("bazooka.bmp");
    pistol = loadSurface("pistol.bmp");
    sniperrifle = loadSurface("sniperrifle.bmp");
//    bullet = loadSurface("bullet.bmp");

    if(background==NULL || wall == NULL || player == NULL || enemy == NULL || mud==NULL || barbwire==NULL || lose == NULL || win == NULL
            || sniper == NULL || bazooka == NULL ||pistol == NULL || sniperrifle == NULL)
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

void GWindow::ShowWeapons(Creature *_creature)
{
    SniperRifle* snip;
    Bazooka* baz;
    Pistol* pis;
    snip=dynamic_cast<SniperRifle*>(_creature->getWeponPtr());
    baz=dynamic_cast<Bazooka*>(_creature->getWeponPtr());
    pis=dynamic_cast<Pistol*>(_creature->getWeponPtr());
    SDL_Rect tmp;
    tmp.w=_creature->getWeponPtr()->getWidth();
    tmp.h=_creature->getWeponPtr()->getHeight();
    tmp.x=_creature->getX()+_creature->getWidth()/2;
    tmp.y=_creature->getY()+5;
    if(snip)
    {
        tmp.x=_creature->getX()+_creature->getWidth()/2-4;
        tmp.y=_creature->getY()+5;
        SDL_BlitScaled(sniperrifle,NULL,screenSurface,&tmp);
    }
    if(baz)
    {
        tmp.x=_creature->getX();
        tmp.y=_creature->getY();
        SDL_BlitScaled(bazooka,NULL,screenSurface,&tmp);
    }
    if(pis)
    {
        tmp.x=_creature->getX()+_creature->getWidth()-4;
        tmp.y=_creature->getY()+_creature->getHeight()/2-6;
        SDL_BlitScaled(pistol,NULL,screenSurface,&tmp);
    }
}

Game* GWindow::getGamePtr()
{
    return game;
}

