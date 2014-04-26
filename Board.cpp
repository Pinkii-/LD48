#include "Board.hpp"
#include "LD48.hpp"

Board::Board(){
}

Board::Board(LD48* g, int w){
    game = g;

    height = pWindow->getSize().y - TOP_MARGIN;
    width = w;

    collisionLayer.create(width, height, sf::Color(0,0,0));
    whiteImage.create(width, height, sf::Color(255,255,255));

    bgDirt.setTexture(Resources::textureDirt);
    bgTunnel.setTexture(Resources::textureTunnel);
}

inline sf::IntRect getProperRectangle(sf::Vector2f current, sf::Vector2f prev) {
    float playerSpriteWidth, playerSpriteHeight;

    if (current.y < prev.y) {
        return sf::IntRect(current.x, current.y, playerSpriteWidth, prev.y + playerSpriteHeight - current.x);
    }
    else if (current.y > prev.y) {
        return sf::IntRect(prev.x, prev.y, playerSpriteWidth, current.y + playerSpriteHeight - prev.x);
    }
    else if (current.x < prev.x) {
        return sf::IntRect(current.x, current.y, prev.x + playerSpriteWidth - current.x, playerSpriteHeight);
    }
    else if (current.x > prev.x) {
        return sf::IntRect(prev.x, prev.y, current.x + playerSpriteWidth - prev.x, playerSpriteHeight);
    }
    else {
        return sf::IntRect(0,0,0,0);
    }
}

void Board::init () {
    prevPlayerPos[0] = game->getPlayer(0)->getPosition();
    prevPlayerPos[1] = game->getPlayer(1)->getPosition();
    pWindow = game->getWindow();
}

void Board::update() {
    sf::IntRect rectPlayerMovement[2];

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
    sf::Image tunnelTextImage;

    tunnelTextImage = bgTunnel.getTexture()->copyToImage();
    collisionLayer.createMaskFromColor(sf::Color::White);
    tunnelTextImage.copy(collisionLayer,0,0,sf::IntRect(0, 0, collisionLayer.getSize().x, collisionLayer.getSize().y));
    tunnelTextImage.createMaskFromColor(sf::Color::Black);
    Resources::textureTunnel.loadFromImage(tunnelTextImage, sf::IntRect(0, 0, tunnelTextImage.getSize().x, tunnelTextImage.getSize().y));

    bgTunnel.setTexture(Resources::textureTunnel);

    pWindow->draw(bgDirt);
    pWindow->draw(bgTunnel);
}

boardType Board::getBoardType(sf::Vector2f pos) {
    //full digged blocked qtt_boardType

    if(pos.x > width || pos.x < 0 || pos.y < 0 || pos.y > height) {
        return blocked;
    }

    sf::Color pixelColor = collisionLayer.getPixel(pos.x, pos.y);

    if(pixelColor == sf::Color::Black){
        return full;
    }
    else if(pixelColor == sf::Color::White){
        return digged;
    }
}
