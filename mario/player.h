#ifndef PLAYER_H
#define PLAYER_H


namespace game{
    class Player
    {
        public:
            game::AnimationManager* am;
            std::map<std::string,bool> key;
            int dir;
            bool onLadder, shoot, hit;
            bool onGround;
            float  dx,dy,
                   x,y,
                   w,h;
            void keyboard();
            void setAnimation();
        public:
            Player(game::AnimationManager* pA);
            void update(float time);
            void draw(sf::RenderWindow &aWindow);
    };
}

#endif // PLAYER_H
