#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"

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
    {1,0,0,0,0,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,21,0,0,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,15,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,16,16,16,16,16,16,16,16,16,16,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,19,0,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,17,0,18,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,16,16,16,16,16,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,0,0,0,0,0,0,0,0,0,1},
    {1,16,16,16,16,16,16,16,16,0,0,0,0,0,0,0,0,0,0,0,0,16,16,16,16,16,16,16,16,16,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,16,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,16,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,16,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,16,16,16,16,16,16,16,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,16,16,16,16,16,16,16,16,16,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
 {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

class Player{
  public:
    float dx,dy;
    sf::FloatRect character;
    bool onGround;
    sf::Sprite sprite;
    float currentFrame;
    Player(sf::Texture &image )
    {
        sprite.setTexture(image);
        character = sf::FloatRect(sizeTail,0,size_char_x,size_char_y); // wall?
        dx = 0;
        dy = 0;
        onGround = 0;
        currentFrame = 0;
    }
    void update(float time)
    {
        character.left += dx*time;
        if(character.left < 0)
            character.left = sizeTail;
        if(character.left > ((W-1)*sizeTail-size_char_x))
            character.left = ((W-1)*sizeTail-size_char_x);
        Collision(0);
        if(!onGround)
            dy = dy+0.0005*time;
        onGround = false;
        character.top += dy*time;
        if(character.top < 0)
            character.top = size_char_y;
        if(character.top > (screen_height-size_char_y-1*sizeTail))
        {
            character.top = (screen_height-size_char_y-1*sizeTail);
            dy = 0;
            onGround = true;
        }
        Collision(1);
        currentFrame += 0.005*time;
        if(currentFrame > 6)
            currentFrame -=6;
        if(dx > 0)
            sprite.setTextureRect(sf::IntRect(40*int(currentFrame),244,size_char_x,size_char_y));
        if(dx < 0)
            sprite.setTextureRect(sf::IntRect(40*int(currentFrame)+40,244,-size_char_x,size_char_y));

        sprite.setPosition(character.left-offsetX, character.top-offsetY);
        dx = 0;
    }
private:
    void Collision( int dir)
    {
        for(unsigned   i = character.top/sizeTail;    i < (character.top   + character.height)/sizeTail; i++)
          for(unsigned j = character.left/sizeTail; j < (character.width + character.left)/sizeTail;   j++)
          {
              if(i > H)
                  continue;
              if(j > W)
                  continue;
              if(TileMap[i][j] == 1 || (TileMap[i][j] == 16))
              {
                  if(dx > 0 && dir == 0)
                      character.left = j*sizeTail - character.width;
                  if(dx < 0 && dir == 0)
                      character.left = j*sizeTail + sizeTail;
                  if(dy > 0 && dir == 1)
                  {
                      character.top = i*sizeTail - character.height;
                      dy = 0;
                      onGround = true;
                  }
                  if(dy < 0 && dir == 1)
                  {
                      character.top = i*sizeTail + sizeTail;
                      dy = 0;
                  }
              }
              if(TileMap[i][j] == '0')
                  TileMap[i][j] = ' ';
          }
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(340,340),"SFFL");

    sf::Texture tPlayer;
    sf::Texture tileSet;
    tPlayer.loadFromFile("D:\\project_QT\\mini_project\\mario\\fang.png");
    tileSet.loadFromFile("D:\\project_QT\\mini_project\\mario\\Mario_Tileset.png");
    sf::Sprite tile(tileSet);

    Player p(tPlayer);
    sf::Clock clock;
    sf::RectangleShape rectangle; // buffer for brick of the map
    rectangle.setSize(sf::Vector2f(sizeTail,sizeTail));
    while(window.isOpen())
    {
         float time = clock.getElapsedTime().asMicroseconds();
         clock.restart();
         time = time/800;
         sf::Event event;
         while(window.pollEvent(event))
         {
             if(event.type == sf::Event::Closed)
                 window.close();
             if(event.type == sf::Event::MouseButtonPressed)
             {
                 std::cout<<"Click on button"<<std::endl;
                 int pos_h = 0;
                 int pos_w = 0;
                 pos_h = p.character.top/sizeTail;  // i
                 pos_w = p.character.left/sizeTail; //j
                 TileMap[pos_h][pos_w] = 4;
             }
         }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
         {
             p.dx = -0.1;
         }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
         {
             p.dx = 0.1;
         }
         if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
         {
             if(p.onGround)
             {
                 p.dy = -0.25;
                 p.onGround = false;
             }
         }
         p.update(time);

         offsetX = p.character.left-340/2;
         offsetY = p.character.top -340/2;

         if(p.character.left > 340/2)
            offsetX = p.character.left - 340/2;
         if(p.character.top > 340/2)
            offsetY = p.character.top - 340/2;

         window.clear(sf::Color::White);
         for(int i = 0; i < H; i++)
           for(int j = W-1; j >= 0; j--)
           {
               int is = 0;
               if(TileMap[i][j] == 0)
                   continue;
               if(TileMap[i][j] == 1)
               {
                   rectangle.setFillColor(sf::Color::Black);
                   is = 1;
               }
               if(TileMap[i][j] == 2)
               {
                   rectangle.setFillColor(sf::Color::Green);
                   is = 1;
               }
               if(TileMap[i][j] == 4)
               {
                   is = 1;
                   rectangle.setFillColor(sf::Color::Red);
                   //TileMap[i][j] = 0;
                   if((j < (W-2)))
                        TileMap[i][j+1] = 4;
               }
               rectangle.setPosition(j*sizeTail-offsetX,i*sizeTail-offsetY);
               if(is)
                    window.draw(rectangle);
               //--------------------------------------
                is = 0;
               if (TileMap[i][j]==15)
               {
                   tile.setTextureRect( sf::IntRect(143-16*3,112,16,16) );
                   is = 1;
               }

               if (TileMap[i][j]==16)
               {
                   tile.setTextureRect( sf::IntRect(143,112,16,16) );
                   is = 1;
               }
               if (TileMap[i][j]==17)
               {
                   tile.setTextureRect( sf::IntRect(143-16,112,16,16) );
                   is = 1;
               }
                if (TileMap[i][j]==18)
                {
                    tile.setTextureRect( sf::IntRect(0,47,32,95-47) );
                    is = 1;
                }
                if (TileMap[i][j]==19)
                 {
                    tile.setTextureRect( sf::IntRect(0,16*9-5,3*16,16*2+5) );
                    is = 1;
                }
                if (TileMap[i][j]==20)
                 {
                    tile.setTextureRect( sf::IntRect(145,222,222-145,255-222) );
                    is = 1;
                }
                if (TileMap[i][j]==21)
                 {
                    tile.setTextureRect( sf::IntRect(0,106,74,127-106) );
                    is = 1;
                }
                if (TileMap[i][j]==22)
                {
                    tile.setTextureRect( sf::IntRect(99,224,140-99,255-224) );
                    is = 1;
                }
                if (TileMap[i][j]==23)
                 {
                    tile.setTextureRect( sf::IntRect(143-32,112,16,16) );
                    is = 1;
                }
                if(is)
                {
                    tile.setPosition(j*sizeTail-offsetX,i*sizeTail-offsetY);
                    window.draw(tile);
                }
               //--------------------------------------
           }
         window.draw(p.sprite);
         window.display();
    }
    return 0;
}
