#include "Board.hpp"
#include "LD48.hpp"
#include<algorithm>
#include<iostream>

using namespace std;

Board::Board(){
}

Board::Board(LD48* g, int w) : game(g), pWindow(g->getWindow()){
    height = pWindow->getSize().y;
    width = w;

	collisionLayer.create(width, height, sf::Color::Black);
	collisionLayer2.create(width, height, sf::Color::Transparent);
	whiteImage.create(width, height, sf::Color::White);

	bgDirt.setTexture(Resources::textureDirt);

    horOffset = (pWindow->getSize().x >> 1) - (width >> 1);

    bgDirt.setPosition(sf::Vector2f(horOffset - 590, 0));
	bgTunnel.setPosition(sf::Vector2f(horOffset, TOP_MARGIN));

}


void Board::init () {
    prevPlayerPos[0] = game->getPlayer(0)->position;
    prevPlayerPos[1] = game->getPlayer(1)->position;
    pWindow = game->getWindow();
}


void Board::updateCollisionLayer2(int xx, int yy, int tx, int ty)
{
    int itx = (int)collisionLayer.getSize().x;
	int ity = (int)collisionLayer.getSize().y;
	tx = min(itx, xx+tx);
	ty = min(ity, yy+ty);
	xx = max(0, xx);
	yy = max(0, yy);

	for(int x = xx; x < tx; x++)
		for(int y = yy; y < ty; y++)
		{
			int ct = 0;
			for(int x2 = max(0, x-6); x2 < min(itx, x+7); x2++)
				for(int y2 = max(0, y-6); y2 < min(ity, y+7); y2++)
					if(collisionLayer.getPixel(x2, y2).r == 255)
						ct += rand()%4;

			ct/= 2;
			sf::Color c = sf::Color::Transparent;
			if(ct > 45) c = sf::Color::Black;
			if(ct > 65) c = Resources::textureTunnel.getPixel(x, y);
			collisionLayer2.setPixel(x, y, c);

        }
}

void Board::update() {
    //sf::IntRect rectPlayerMovement[2];

    currPlayerPos[0] = game->getPlayer(0)->position;
    currPlayerPos[1] = game->getPlayer(1)->position;

    //rectPlayerMovement[0] = getProperRectangle(currPlayerPos[0], prevPlayerPos[0]);
    //rectPlayerMovement[1] = getProperRectangle(currPlayerPos[1], prevPlayerPos[1]);

    collisionLayer.copy(whiteImage, currPlayerPos[0].x - horOffset, currPlayerPos[0].y - TOP_MARGIN, sf::IntRect(0,0,15,15));
	updateCollisionLayer2(currPlayerPos[0].x - horOffset-10, currPlayerPos[0].y - TOP_MARGIN-10, 35, 35);
    collisionLayer.copy(whiteImage, currPlayerPos[1].x - horOffset, currPlayerPos[1].y - TOP_MARGIN, sf::IntRect(0,0,15,15));
	updateCollisionLayer2(currPlayerPos[1].x - horOffset-10, currPlayerPos[1].y - TOP_MARGIN-10, 35, 35);

    prevPlayerPos[0] = currPlayerPos[0];
    prevPlayerPos[1] = currPlayerPos[1];

}

void Board::draw() {
	TunnelMask.loadFromImage(collisionLayer2);
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
