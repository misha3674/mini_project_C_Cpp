#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include "animationmanager.h"
#include "player.h"

enum eState
{
    STAY,
    WALK,
    DUCK,
    JUMP,
    CLIMP,
    SWIM
};
eState  state;
const int gH = 30;
const int gW = 40;
game::Player::Player(game::AnimationManager* pA)
{
    this->am = pA;
    state=STAY;
    this->hit      =false;
    this->onLadder = false;
    this->shoot    = false;
    this->onGround = false;
    this->am->play();
    this->dx  = 0;
    this->dy  = 0;
    this->w   = 40;
    this->h   = 50;
    this->x   = 0;
    this->y   = 0;
    this->dir = 0;
}
//-------------------------------------------------------------------------------
void game::Player::keyboard()
{
    state = STAY;
    this->shoot=false;
    if (this->key["L"])
    {
        dir=1;
        dx = -0.1;
        state=WALK;
    }
    if (this->key["R"])
    {
        dir=0;
        dx = 0.1;
        state=WALK;
    }
    if (this->key["Up"])
    {
        state = JUMP;
        onGround = false;
    }
    if (this->key["Down"])
    {
        state = DUCK;
    }
    if (this->key["Space"])
        shoot=true;
}
//-------------------------------------------------------------------------------
void game::Player::setAnimation()
{
    if (state==STAY)
        am->set("stay");
    if (state==WALK)
        am->set("walk");
    if (state==JUMP)
       am->set("jump");
    if (state==DUCK)
        am->set("duck");
    if(shoot)
       am->set("shoot");
    am->flip(dir);
}
//-------------------------------------------------------------------------------
void game::Player::update(float time)
{
        this->keyboard();
        x += dx;
        if(!onGround)
        {
            onGround = true;
            dy = -0.8;
        }
        else
            dy = 0.1;
        y += dy; // gravity
        this->setAnimation();
        am->tick(time);
        key["R"]=key["L"]=key["Up"]=key["Down"]=key["Space"]=false;
        dx = 0;
        dy = 0;
}
//-------------------------------------------------------------------------------
void game::Player::colision(int direct)
{
        float lJ = (x+40)/16;
        float lI = (y+50)/16;
        for(int i = this->y/16;     i < lI; i++)
            for(int j = lJ - 1; j >= this->x/16; j--)
            {
                if( (gTileMap[i][j] == 1) || (gTileMap[i][j] == 16))
                {
                    if(direct)
                    {
                        if(i == 0)
                            continue; // top wall
                        if(i == (gH-1))
                            continue; // bottom wall
                        if(dx > 0)
                            x = j*16 - w; //sizeTail, Why size_char_x???
                        if(dx < 0)
                            x = j*16 + 16;
                    }
                    else
                    {
                        if(j == 0)
                            continue; // left wall
                        if(j == (gW-1))
                            continue; // left wall
                        if(dy > 0)
                        {
                            y = i*16 - h;
                        }
                        if(dy < 0)
                        {
                            y = i*16 + 16;
                        }
                    }
                }
            }
}
void game::Player::draw(sf::RenderWindow &aWindow)
{
    am->draw(aWindow,this->x,this->y);
}
