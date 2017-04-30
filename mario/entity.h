#ifndef ENTITY_H
#define ENTITY_H

class Entity{
    public:
    float x,y,dx,dy,w,h;
    game::AnimationManager* an;
    bool life;
    bool dir;
    /*Entity(game::AnimationManager* a, int aX, int aY,int direct)
    {
        an = a;
        x = aX;
        y = aY;
        dir = direct;
        std::cout<<x<<" Constructor entity\n";
        life = true;
    }*/
    Entity()
    {
        an = nullptr;
        x = 0;
        y = 0;
        dir = 0;
        std::cout<<"Constructor entity empty\n";
        life = true;
    }
    virtual ~Entity()
    {
        std::cout<<"Destructor entity virtual\n";
    }
    virtual void update(float time) = 0;
    void draw(sf::RenderWindow &window)
    {
        an->draw(window,x,y+h);
    }
};
#endif // ENTITY_H
