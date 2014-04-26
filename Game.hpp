#ifndef GAME_H
#define GAME_H

#include "utils.hpp"

class Game {
public:
    Game(int scrwidth, int scrheight, std::string title, int style);
    virtual ~Game();
    void run();
    virtual void update(float deltaTime) = 0;
    virtual void draw() = 0;
    virtual void processEvents() = 0;
protected:
    sf::RenderWindow window;
private:
    void render();

};

#endif // GAME_H
