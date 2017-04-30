#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include<windows.h>
#include "SFML/Graphics.hpp"
#include "animationmanager.h"
#include "player.h"
#include "entity.h"

const int H = 30;
const int W = 40;
const int sizeTail = 16;
const int screen_height = H*sizeTail;
const int screen_width  = W*sizeTail;
const int size_char_x  = 40;
const int size_char_y  = 50;
float offsetX = 0;
float offsetY = 0;
int TileMap[H][W] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,16,16,16,16,16,16,16,16,16,16,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,16,16,16,16,16,16,16,0,0,0,0,0,0,0,0,0,0,16,16,16,16,16,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,16,16,16,16,16,16,16,16,16,0,0,0,0,0,0,0,0,0,1},
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

class Bullet:public Entity{
  public:
    Bullet(game::AnimationManager* a, int aX, int aY, int direct)
    {
        an = a;
        a->set("move");
        x = aX;
        y = aY;
        dx = 0.005;
        this->dir = direct;
        if(this->dir == 1)
            dx = -0.005;
        w=h=18;
        std::cout<<"Constructor BULLET\n";
        life = true;
    }
    ~Bullet()
    {
        std::cout<<"Destructor BULLET\n";
    }
    void update(float time)
    {
        x += dx*time;
        for(int i = y/16; i < (y+h)/16; i++)
            for(int j = x/16; j < (x+w)/16; j++)
                if(TileMap[i][j] == 1)
                {
                    an->set("explode");
                    dx = 0;
                    life = false;
                }
        an->tick(time);
    }
};
// ----------------------------------------------------------------------
int main()
{
     sf::RenderWindow window(sf::VideoMode(340,340),"SFFL");
     sf::Texture tPlayer;
     sf::Texture aBulet;
     game::AnimationManager listAnim;
     game::AnimationManager animBullet;
     std::list<Entity*> entity;
     std::list<Entity*>::iterator it;
     game::Player Mario(&listAnim);
     aBulet.loadFromFile("D:\\project_QT\\mini_project\\mario\\bullet.png");
     tPlayer.loadFromFile("D:\\project_QT\\mini_project\\mario\\fang.png");
     listAnim.create("walk", tPlayer,0,244,40,50,6);
     listAnim.create("jump", tPlayer,0,528,29,30,4);
     listAnim.create("duck", tPlayer,0,436,80,20,1);
     listAnim.create("stay", tPlayer,0,187,42,52,3);
     listAnim.create("shoot",tPlayer,0,572,45,52,5);
     animBullet.create("move",   aBulet,7,10,8,8,1);
     animBullet.create("explode",aBulet,27,7,18,18,4);
     while(window.isOpen())
     {
         window.clear(sf::Color::White);
         sf::Event event;
         while(window.pollEvent(event))
         {
             if(event.type == sf::Event::Closed)
                 window.close();
             if(event.type == sf::Event::KeyPressed)
                 if(event.key.code == sf::Keyboard::Space)
                     entity.push_back(new Bullet(&animBullet,20,50,1));
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
         for(it=entity.begin(); it != entity.end(); )
         {
             Entity *b = *it;
             b->update(3);
             b->draw(window);
             if(b->life == false)
             {
                 it = entity.erase(it);
                 delete b;
             }
             else
                 it++;
         }
         draw_map(window);
         Mario.update(1.2);
         Mario.draw(window);
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
