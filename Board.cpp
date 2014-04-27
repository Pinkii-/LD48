#include "Board.hpp"
#include "LD48.hpp"

Board::Board(){
}

Board::Board(LD48* g, int w) : game(g), pWindow(g->getWindow()){
    height = pWindow->getSize().y;
    width = w;

    collisionLayer.create(width, height, sf::Color::Black);
    whiteImage.create(width, height, sf::Color::White);

    TunnelMask = sf::Texture(Resources::textureTunnel);

    bgDirt.setTexture(Resources::textureDirt);
    bgTunnel.setTexture(Resources::textureTunnel);

    horOffset = (pWindow->getSize().x >> 1) - (width >> 1);

    bgDirt.setPosition(sf::Vector2f(horOffset - 590, 0));
    bgTunnel.setPosition(sf::Vector2f(horOffset, TOP_MARGIN));

    int rodonesX = Resources::rodones.getSize().x >> 2;
    int rodonesY = Resources::rodones.getSize().y >> 1;

    spDBSpeed.setTexture(Resources::rodones);
    spDBSpeed.setTextureRect(sf::IntRect(rodonesX, rodonesY, rodonesX, rodonesY));
    spDBStrength.setTexture(Resources::rodones);
    spDBStrength.setTextureRect(sf::IntRect(0, rodonesY, rodonesX, rodonesY));

    spPUSpeed.setTexture(Resources::rodones);
    spPUSpeed.setTextureRect(sf::IntRect(rodonesX, 0, rodonesX, rodonesY));
    spDBStrength.setTexture(Resources::rodones);
    spDBStrength.setTextureRect(sf::IntRect(0, 0, rodonesX, rodonesY));

    spPOOne.setTexture(Resources::rodones);
    spPOOne.setTextureRect(sf::IntRect(rodonesX << 1, 0, rodonesX, rodonesY));
    spPOTwo.setTexture(Resources::rodones);
    spPOTwo.setTextureRect(sf::IntRect(rodonesX << 1 + rodonesX, 0, rodonesX, rodonesY));
    spPOThree.setTexture(Resources::rodones);
    spPOThree.setTextureRect(sf::IntRect(rodonesX << 1, rodonesY, rodonesX, rodonesY));
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
    //sf::IntRect rectPlayerMovement[2];

    currPlayerPos[0] = game->getPlayer(0)->getPosition();
    currPlayerPos[1] = game->getPlayer(1)->getPosition();

    //rectPlayerMovement[0] = getProperRectangle(currPlayerPos[0], prevPlayerPos[0]);
    //rectPlayerMovement[1] = getProperRectangle(currPlayerPos[1], prevPlayerPos[1]);

    collisionLayer.copy(whiteImage, currPlayerPos[0].x - horOffset, currPlayerPos[0].y - TOP_MARGIN, sf::IntRect(0,0,15,15));
    collisionLayer.copy(whiteImage, currPlayerPos[1].x - horOffset, currPlayerPos[1].y - TOP_MARGIN, sf::IntRect(0,0,15,15));

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

    if(pos.x + 15 > width + horOffset || pos.x < 0 + horOffset || pos.y < TOP_MARGIN || pos.y > height) {
        return blocked;
    }
    int sumColorType = 0;
    if(collisionLayer.getPixel(pos.x - horOffset, pos.y - TOP_MARGIN) == sf::Color::Black) sumColorType++;
    if(collisionLayer.getPixel(pos.x - horOffset, pos.y + 15 - TOP_MARGIN) == sf::Color::Black) sumColorType++;
    if(collisionLayer.getPixel(pos.x + 15 - horOffset, pos.y + 15 - TOP_MARGIN) == sf::Color::Black) sumColorType++;
    if(collisionLayer.getPixel(pos.x + 15 - horOffset, pos.y - TOP_MARGIN) == sf::Color::Black) sumColorType++;
    if(collisionLayer.getPixel(pos.x + 7 - horOffset, pos.y - TOP_MARGIN) == sf::Color::Black) sumColorType++;
    if(collisionLayer.getPixel(pos.x + 7 - horOffset, pos.y + 15 - TOP_MARGIN) == sf::Color::Black) sumColorType++;
    if(collisionLayer.getPixel(pos.x - horOffset, pos.y + 7 - TOP_MARGIN) == sf::Color::Black) sumColorType++;
    if(collisionLayer.getPixel(pos.x + 15 - horOffset, pos.y + 7 - TOP_MARGIN) == sf::Color::Black) sumColorType++;

    if(sumColorType >= 4) return full;
    else return digged;
}

void Board::SpawnDebuff() {
    int x, y;

    x = rand()%800;
    y = rand()%800;

    listDebuff.push_back((deBuff)(rand()%2));
}
