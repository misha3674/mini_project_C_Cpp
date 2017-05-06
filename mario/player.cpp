#include <iostream>
#include <map>
#include "../external_libs/SFML/Graphics.hpp"
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
        y += dy; // gravity
        this->setAnimation();
        am->tick(time);
        key["R"]=key["L"]=key["Up"]=key["Down"]=key["Space"]=false;
        dx = 0;
        dy = 0;
}
//-------------------------------------------------------------------------------
void game::Player::draw(sf::RenderWindow &aWindow)
{
    am->draw(aWindow,this->x,this->y);
}
