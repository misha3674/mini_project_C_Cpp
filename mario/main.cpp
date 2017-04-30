#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "SFML/Graphics.hpp"
#include "animationmanager.h"

const int H = 30;
const int W = 40;
const int sizeTail = 16;
const int screen_height = H*sizeTail;
const int screen_width  = W*sizeTail;
const int size_char_x  = 40;
const int size_char_y  = 50;
float offsetX = 0;
float offsetY = 0;
enum obj{
  EMPTY = 0,
  WALL,
  TRE,
  BONUS
};
int TileMap[H][W] = {
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,19,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,16,16,16,16,16,16,16,16,16,16,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,16,16,16,16,16,16,16,0,0,0,0,0,0,0,0,0,0,16,16,16,16,16,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,1},
    {1,16,16,16,16,16,16,16,16,0,0,0,0,0,0,0,0,0,0,0,0,16,16,16,16,16,16,16,16,16,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,16,16,16,16,16,16,16,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,16,16,16,16,16,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,16,16,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,16,16,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
void draw_map(sf::RenderWindow& window);
// ----------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------
class PLAYER
{
public:
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
    anima::AnimationManager* an;
    std::map<std::string,bool> key;
    int dir;
    bool onLadder, shoot, hit;
    float top;
    float left;
    float  dx,dy,
         x,y,
         w,h;
    PLAYER(anima::AnimationManager* a)
    {
        an = a;
        state=STAY;
        hit=false;
        an->play();
        dx=dy=x=y=h=w= 0;
        dir = 0;
        top  = 0;
        left = 0;
    }
    void Keyboard()
    {
        state = STAY;
        shoot=false;
        if (key["L"])
        {
            dir=1;
            dx = -0.1;
            state=WALK;
        }
        if (key["R"])
        {
            dir=0;
            dx = 0.1;
            state=WALK;
        }
        if (key["Up"])
        {
            state = JUMP;
            dy = -0.25;
        }
        if (key["Down"])
        {
            state = DUCK;
        }
        if (key["Space"])
            shoot=true;
    }
    void setAnimation()
    {
        if (state==STAY)
            an->set("stay");
        if (state==WALK)
            an->set("walk");
        if (state==JUMP)
            an->set("jump");
        if (state==DUCK)
            an->set("duck");
        if(shoot)
            an->set("shoot");
        an->flip(dir);
    }
    void update(float time)
    {
        Keyboard();
        top  += dy;
        left += dx;
        setAnimation();
        an->tick(time);
        key["R"]=key["L"]=key["Up"]=key["Down"]=key["Space"]=false;
        dx = 0;
        dy = 0;
    }
};
// ----------------------------------------------------------------------
// ----------------------------------------------------------------------
int main()
{
     sf::RenderWindow window(sf::VideoMode(340,340),"SFFL");
     sf::Texture tPlayer;
     tPlayer.loadFromFile("D:\\project_QT\\mini_project\\mario\\fang.png");
     anima::AnimationManager listAnim;
     listAnim.create("walk", tPlayer,0,244,40,50,6);
     listAnim.create("jump", tPlayer,0,528,29,30,4);
     listAnim.create("duck", tPlayer,0,436,80,20,1);
     listAnim.create("stay", tPlayer,0,187,42,52,3);
     listAnim.create("shoot",tPlayer,0,572,45,52,5);
     PLAYER Mario(&listAnim);
     listAnim.set("walk");
     while(window.isOpen())
     {
         window.clear(sf::Color::White);
         sf::Event event;
         while(window.pollEvent(event))
         {
             if(event.type == sf::Event::Closed)
                 window.close();
             if(event.type == sf::Event::MouseButtonPressed)
             {
                 std::cout<<"Click on mouse button"<<std::endl;
             }
         }
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  Mario.key["L"]     = true;
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) Mario.key["R"]     = true;
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    Mario.key["Up"]    = true;
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  Mario.key["Down"]  = true;
         if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) Mario.key["Space"] = true;

         offsetX = Mario.left;
         //offsetY = Mario.top;
         draw_map(window);
         Mario.update(1.2);
         listAnim.draw(window,0,0);//screen_width/2 ,screen_height/2);
         window.display();
    }
    return 0;
}
void draw_map(sf::RenderWindow& window)
{
    sf::RectangleShape s(sf::Vector2f(float(16),float(16)));
    for(int i = 0; i < H; i++)
        for(int j = 0; j < W; j++)
        {
            switch(TileMap[i][j])
            {
                case 0:
                   continue;
                break;
                case 16:
                    s.setFillColor(sf::Color::Red);
                break;
                case 1:
                    s.setFillColor(sf::Color::Blue);
                break;
            }
            s.setPosition(sf::Vector2f(j*16 - offsetX,
                                       i*16 - offsetY ));
            window.draw(s);
        }
}
