#include "Board.hpp"
#include "LD48.hpp"
#include<algorithm>
#include<iostream>

using namespace std;

Board::Board(){
}
sf::RenderTexture rt;

Board::Board(LD48* g, int w) : game(g), pWindow(g->getWindow()){
    height = pWindow->getSize().y;
    width = w;

    collisionLayer.create(800, 800, sf::Color::Black);
    waterLayer.create(200, 200, sf::Color::White);
    rt.create(200, 200);

	bgDirt.setTexture(Resources::textureDirt);

    horOffset = (pWindow->getSize().x >> 1) - (width >> 1);

    bgDirt.setPosition(sf::Vector2f(horOffset - 590, 0));
	bgTunnel.setPosition(sf::Vector2f(horOffset, TOP_MARGIN));

}

void fillRect(sf::Image& i, sf::Color c, int x, int y, int w, int h)
{
    for(int xx = 0; xx < w; xx++)
        for(int yy = 0; yy < h; yy++)
            i.setPixel(x+xx, y+yy, c);
}

void Board::init () {
    prevPlayerPos[0] = game->getPlayer(0)->position;
    prevPlayerPos[1] = game->getPlayer(1)->position;
    pWindow = game->getWindow();
}

float timelol = 0;
void Board::update(float deltaTime) {

    timelol += deltaTime;
    currPlayerPos[0] = game->getPlayer(0)->position;
    currPlayerPos[1] = game->getPlayer(1)->position;

    fillRect(collisionLayer, sf::Color::White, currPlayerPos[0].x - horOffset, currPlayerPos[0].y - TOP_MARGIN, 15, 15);
    fillRect(collisionLayer, sf::Color::White, currPlayerPos[1].x - horOffset, currPlayerPos[1].y - TOP_MARGIN, 15, 15);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        fillRect(waterLayer, sf::Color::Blue, (currPlayerPos[1].x - horOffset)/4, (currPlayerPos[1].y - TOP_MARGIN)/4, 3, 3);

    prevPlayerPos[0] = currPlayerPos[0];
    prevPlayerPos[1] = currPlayerPos[1];

}

void Board::draw() {
    collisionLayerTexture.loadFromImage(collisionLayer);
    waterLayerTexture.loadFromImage(waterLayer);

    sf::Sprite spr;
    spr.setTexture(waterLayerTexture);
    Resources::waterShader.setParameter("time", timelol);
    Resources::waterShader.setParameter("collisionTex", collisionLayerTexture);
    rt.draw(spr/*, &Resources::waterShader*/);
    rt.display();
    waterLayer = rt.getTexture().copyToImage();

    pWindow->draw(bgDirt);

    Resources::tunnelShader.setParameter("collisionTex", collisionLayerTexture);
    Resources::tunnelShader.setParameter("waterTex", waterLayerTexture);
    bgTunnel.setTexture(Resources::textureTunnel);
    pWindow->draw(bgTunnel/*, &Resources::tunnelShader*/);
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
