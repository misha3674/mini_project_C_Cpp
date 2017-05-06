#include <vector>
#include <iostream>
#include <map>
#include "../external_libs/SFML/Graphics.hpp"
#include <TinyXML/tinyxml.h>
#include "animationmanager.h"

class Animation_my{
  private:
    std::vector<sf::IntRect>  frame,flip_frame;
    float currentFrame;
    int step;
    float speed;//  setSpeed();
 public:
    sf::Sprite sprite;
    bool isFlip, isPlay;
    Animation_my()
    {
        std::cout<<"empty constructor animation\n";
    }
    Animation_my(sf::Texture &image,int x, int y, int w, int h,int count)
    {
       currentFrame = 0;
       step = 40;
       speed = 0.0025;
       sprite.setTexture(image);
       isPlay = true;
       isFlip = false;
       for(int i = 0; i < count; i++)
       {
           frame.push_back(sf::IntRect(x+i*step,y,w,h));
           flip_frame.push_back(sf::IntRect(x+i*step+w,y,-w,h));
       }
       std::cout<<"constructor animation\n";
    }
    void tick(float time)
    {
       if(!isPlay)
           return;
       currentFrame += speed*time;
       if(currentFrame > frame.size())
           currentFrame -= frame.size();
       int i = currentFrame;
       if(!isFlip)
            sprite.setTextureRect(frame[i]);
       else
           sprite.setTextureRect(flip_frame[i]);

    }
};

std::map<std::string, Animation_my> animList;

game::AnimationManager::AnimationManager()
{
    std::cout<< "Animation manange conttructor\n";
}
void game::AnimationManager:: create(std::string name, sf::Texture &qimage,
            int qx, int qy,
            int qw, int qh,
            int qcount)
{
    animList[name] = Animation_my(qimage,qx,qy,qw,qh,qcount);
    this->currentAnamation = name;
}
void game::AnimationManager::draw(sf::RenderWindow &aWindow, int x, int y)
{
    animList[this->currentAnamation].sprite.setPosition(x,y);
    aWindow.draw(animList[this->currentAnamation].sprite);
}
void game::AnimationManager::set(std::string name)
{
    this->currentAnamation = name;
}
void game::AnimationManager::flip(bool b)
{
    animList[this->currentAnamation].isFlip = b;
}
void game::AnimationManager::tick(float time)
{
    animList[this->currentAnamation].tick(time);
}
void game::AnimationManager::pause()
{
    animList[this->currentAnamation].isPlay = false;
}
void game::AnimationManager::play()
{
    animList[this->currentAnamation].isPlay = true;
}
