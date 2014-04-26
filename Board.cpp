#include "Board.hpp"

Board::Board() {
    // Tamany temporal fins que el calculem
    collisionLayer = sf::Image.create(800, 800, sf::Color(0,0,0));
    whiteImage = sf::Image.create(800,800,sf::Color(255,255,255));
}

inline sf::Rect getProperRectangle(sf::Vector2f current, sf::Vector2f prev) {
    float playerSpriteWidth, playerSpriteHeight;

    if (current.y < prev.y) {
        return sf::Rect(current.x, current.y, playerSpriteWidth, prev.y + playerSpriteHeight - current.x);
    }
    else if (current.y > prev.y) {
        return sf::Rect(prev.x, prev.y, playerSpriteWidth, current.y + playerSpriteHeight - prev.x);
    }
    else if (current.x < prev.x) {
        return sf::Rect(current.x, current.y, prev.x + playerSpriteWidth - current.x, playerSpriteHeight);
    }
    else if (current.x > prev.x) {
        return sf::Rect(prev.x, prev.y, current.x + playerSpriteWidth - prev.x, playerSpriteHeight);
    }
    else {
        return sf::Rect(0,0,0,0);
    }
}

void Board::init () {
    prevPlayerPos[0] = game->getPlayer(0)->getPosition();
    prevPlayerPos[1] = game->getPlayer(1)->getPosition();
}

void Board::update() {
    sf::Rect rectPlayerMovement[2];

    currPlayerPos[0] = game->getPlayer(0)->getPosition();
    currPlayerPos[1] = game->getPlayer(1)->getPosition();

    rectPlayerMovement[0] = getProperRectangle(currPlayerPos[0], prevPlayerPos[0]);
    rectPlayerMovement[1] = getProperRectangle(currPlayerPos[1], prevPlayerPos[1]);

    collisionLayer.copy(whiteImage, rectPlayerMovement[0].left, rectPlayerMovement[0].top, rectPlayerMovement[0]);
    collisionLayer.copy(whiteImage, rectPlayerMovement[1].left, rectPlayerMovement[1].top, rectPlayerMovement[1]);

    prevPlayerPos[0] = currPlayerPos[0];
    prevPlayerPos[1] = currPlayerPos[1];
}

void Board::draw() {

}
