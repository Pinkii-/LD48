#ifndef MYGAME_H
#define MYGAME_H
#include "Game.hpp"

class LD48 : public Game {
public:
    LD48(int scrwidth, int scrheight, std::string title, int style);
    ~LD48();
    void update(float deltaTime);
    void draw();
    void processEvents();
    void keyPressed(sf::Event event);
    void keyReleased(sf::Event event);
private:
    Board board;
    std::vector<Player> players;
    std::vector<bool>   isKeyPressed;
};

#endif // MYGAME_H
