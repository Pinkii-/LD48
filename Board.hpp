#ifndef BOARD_H
#define BOARD_H

#define TOP_MARGIN 220

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
    void SpawnDebuff();
    void SpawnPowerUp();
    void SpawnPointObject(int points);
private:
    struct Object {
        int typeObject;
        sf::Vector2f pos;
    };

    LD48* game;

    sf::Vector2f BoardPosition;
    int height;
    int width;

    int horOffset;
    sf::Image collisionLayer;
    sf::Image whiteImage;

    sf::Texture TunnelMask;
    // Board sprites
    sf::Sprite bgDirt;
    sf::Sprite bgTunnel;

    // Power Up sprites
    sf::Sprite spPUSpeed;
    sf::Sprite spPUStrength;

    // Debuff sprites
    sf::Sprite spDBSpeed;
    sf::Sprite spDBStrength;

    // PointObject sprites
    sf::Sprite spPOOne;
    sf::Sprite spPOTwo;
    sf::Sprite spPOThree;

    sf::Vector2f currPlayerPos[2];
    sf::Vector2f prevPlayerPos[2];

    std::list<Object> listDebuff;
    std::list<Object> listPowerUp;
    std::list<Object> listPointObject;

    sf::RenderWindow* pWindow;

    bool colisionRectangle(sf::Vector2f p, sf::Vector2f q);
    sf::IntRect getProperRectangle(sf::Vector2f current, sf::Vector2f prev);
};

#endif // BOARD_H

