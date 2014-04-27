#ifndef BOARD_H
#define BOARD_H

#define TOP_MARGIN 50

#include "Resources.hpp"

class LD48;
class Board {
public:
    Board();
    Board(LD48* g, int w);
    void update();
    void draw();
    void init();

    boardType getBoardType(sf::Vector2f pos);
private:
    LD48* game;

    sf::Vector2f BoardPosition;
    int height;
    int width;

    int horOffset;
    sf::Image collisionLayer;
    sf::Image whiteImage;

    sf::Texture TunnelMask;

    sf::Sprite bgDirt;
    sf::Sprite bgTunnel;

    sf::Vector2f currPlayerPos[2];
    sf::Vector2f prevPlayerPos[2];

    sf::RenderWindow* pWindow;

    sf::IntRect getProperRectangle(sf::Vector2f current, sf::Vector2f prev);
};

#endif // BOARD_H

