#include "Board.hpp"
#include "LD48.hpp"

Board::Board(){
}

Board::Board(LD48* g, int w) : game(g), pWindow(g->getWindow()){
    height = pWindow->getSize().y - TOP_MARGIN;
    width = w;

    collisionLayer.create(width, height, sf::Color::Black);
    whiteImage.create(width, height, sf::Color::White);

    TunnelMask = sf::Texture(Resources::textureTunnel);

    bgDirt.setTexture(Resources::textureDirt);
    bgTunnel.setTexture(Resources::textureTunnel);

    horOffset = (pWindow->getSize().x >> 1) - (width >> 1);

    bgDirt.setPosition(sf::Vector2f(horOffset, TOP_MARGIN));
    bgTunnel.setPosition(sf::Vector2f(horOffset, TOP_MARGIN));
}

inline sf::IntRect Board::getProperRectangle(sf::Vector2f current, sf::Vector2f prev) {
    float playerSpriteWidth, playerSpriteHeight;

    playerSpriteWidth = game->getPlayer(0)->getSize().x;
    playerSpriteHeight = game->getPlayer(0)->getSize().y;

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
        return sf::IntRect(current.x,current.y,1,1);
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

    //rectPlayerMovement[0] = getProperRectangle(currPlayerPos[0], prevPlayerPos[0]);
    //rectPlayerMovement[1] = getProperRectangle(currPlayerPos[1], prevPlayerPos[1]);

    collisionLayer.copy(whiteImage, currPlayerPos[0].x, currPlayerPos[0].y, sf::IntRect(0,0,15,15));
    collisionLayer.copy(whiteImage, currPlayerPos[1].x, currPlayerPos[1].y, sf::IntRect(0,0,15,15));

    prevPlayerPos[0] = currPlayerPos[0];
    prevPlayerPos[1] = currPlayerPos[1];
}

void Board::draw() {
    sf::Image tunnelTextImage;

    tunnelTextImage = Resources::textureTunnel.copyToImage();

    collisionLayer.createMaskFromColor(sf::Color::White);

    tunnelTextImage.copy(collisionLayer, 0, 0, sf::IntRect(0, 0, 0, 0), true);
    tunnelTextImage.createMaskFromColor(sf::Color::Black);

    TunnelMask.loadFromImage(tunnelTextImage);

    bgTunnel.setTexture(TunnelMask);

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
