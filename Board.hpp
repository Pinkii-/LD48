#ifndef BOARD_H
#define BOARD_H

#include "utils.hpp"

class LD48;

class Board {
private:
    LD48* game;

    sf::Image collisionLayer;
    sf::Image whiteImage;

    sf::Vector2f currPlayerPos[2];
    sf::Vector2f prevPlayerPos[2];
public:
    Board();
    void update();
    void draw();
    void init();
};

#endif // BOARD_H
