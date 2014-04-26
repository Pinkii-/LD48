#include "Board.hpp"

Board::Board() {
    // Tamany temporal fins que el calculem
    collisionLayer = sf::Image.create(800, 800, sf::Color(0,0,0));
    whiteImage = sf::Image.create(800,800,sf::Color(255,255,255));
}

void Update() {
    currPlayerPos[0] = game->getPlayer(0)->getPosition();
    currPlayerPos[1] = game->getPlayer(1)->getPosition();

    sf::Rect rect

    prevPlayerPos[0] = currPlayerPos[0];
    prevPlayerPos[1] = currPlayerPos[1];
}

void Draw() {

}
