#ifndef BOARD_H
#define BOARD_H

#include "utils.hpp"

class LD48;

class Board {
private:
    sf::Image collision_layer;
    sf::Image white_image;
    LD48* game;

    sf::Vector2f currPlayerPos[2];
    sf::Vector2f prevPlayerPos[2];
public:
    Board();
    void Update();
    void Draw();
};

#endif // BOARD_H
