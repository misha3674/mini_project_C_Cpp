#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H


namespace game{
    class AnimationManager
    {
    public:
        AnimationManager();
        std::string currentAnamation;
        void create(std::string name, sf::Texture &qimage,
                    int x, int y,
                    int w, int h,
                    int count);
        void draw(sf::RenderWindow &aWindow, int x, int y);
        void set(std::string name);
        void flip(bool b);
        void tick(float time);
        void pause();
        void play();
    };
}
#endif // ANIMATIONMANAGER_H
