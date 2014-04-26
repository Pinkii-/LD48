#include "Board.hpp"

Board::Board() {
    // Tamany temporal fins que el calculem
    collisionLayer = sf::Image.create(800, 800, sf::Color(0,0,0));
    whiteImage = sf::Image.create(800,800,sf::Color(255,255,255));
}

sf::Rect getProperRectangle(sf::Vector2f current, sf::Vector2f prev) {

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
