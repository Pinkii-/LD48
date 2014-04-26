#ifndef BOARD_H
#define BOARD_H

#include "utils.hpp"
#include "Resources.hpp"

class LD48;

class Board {
private:
    LD48* game;

    int height;
    int width;

    sf::Image collisionLayer;
    sf::Image whiteImage;

    sf::Vector2f currPlayerPos[2];
    sf::Vector2f prevPlayerPos[2];

    sf::Window* pWindow;
public:
    Board();
    void update();
    void draw();
    void init();

    boardType getBoardType(sf::Vector2f pos);
};

#endif // BOARD_H

