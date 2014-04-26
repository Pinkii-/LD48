#ifndef BOARD_H
#define BOARD_H

#define TOP_MARGIN 50

#include "utils.hpp"
#include "Resources.hpp"

class LD48;

class Board {
private:
    LD48* game;

    sf::Vector2f BoardPosition;
    int height;
    int width;

    sf::Image collisionLayer;
    sf::Image whiteImage;

    sf::Sprite bgDirt;
    sf::Sprite bgTunnel;

    sf::Vector2f currPlayerPos[2];
    sf::Vector2f prevPlayerPos[2];

    sf::RenderWindow* pWindow;
public:
    Board();
    void update();
    void draw();
    void init();

    boardType getBoardType(sf::Vector2f pos);
};

#endif // BOARD_H

