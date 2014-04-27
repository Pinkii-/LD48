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

    int rodonesX = Resources::rodones.getSize().x >> 2;
    int rodonesY = Resources::rodones.getSize().y >> 1;

    spDBSpeed.setTexture(Resources::rodones);
    spDBSpeed.setTextureRect(sf::IntRect(rodonesX, rodonesY, rodonesX, rodonesY));
    spDBSpeed.setScale((float)rodonesX/pWindow->getSize().x * 3, (float)rodonesX/pWindow->getSize().x * 3);
    spDBStrength.setTexture(Resources::rodones);
    spDBStrength.setTextureRect(sf::IntRect(0, rodonesY, rodonesX, rodonesY));
    spDBStrength.setScale((float)rodonesX/pWindow->getSize().x * 3, (float)rodonesX/pWindow->getSize().x  * 3);

    spPUSpeed.setTexture(Resources::rodones);
    spPUSpeed.setTextureRect(sf::IntRect(rodonesX, 0, rodonesX, rodonesY));
    spPUSpeed.setScale((float)rodonesX/pWindow->getSize().x * 3, (float)rodonesX/pWindow->getSize().x * 3);
    spPUStrength.setTexture(Resources::rodones);
    spPUStrength.setTextureRect(sf::IntRect(0, 0, rodonesX, rodonesY));
    spPUStrength.setScale((float)rodonesX/pWindow->getSize().x * 3, (float)rodonesX/pWindow->getSize().x * 3);

    spPOOne.setTexture(Resources::rodones);
    spPOOne.setTextureRect(sf::IntRect(rodonesX << 1, 0, rodonesX, rodonesY));
    spPOOne.setScale((float)rodonesX/pWindow->getSize().x * 3, (float)rodonesX/pWindow->getSize().x * 3);
    spPOTwo.setTexture(Resources::rodones);
    spPOTwo.setTextureRect(sf::IntRect(rodonesX * 3, 0, rodonesX, rodonesY));
    spPOTwo.setScale((float)rodonesX/pWindow->getSize().x * 3, (float)rodonesX/pWindow->getSize().x * 3);
    spPOThree.setTexture(Resources::rodones);
    spPOThree.setTextureRect(sf::IntRect(rodonesX << 1, rodonesY, rodonesX, rodonesY));
    spPOThree.setScale((float)rodonesX/pWindow->getSize().x * 3, (float)rodonesX/pWindow->getSize().x * 3);
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

bool Board::colisionRectangle(sf::Vector2f p, sf::Vector2f q){
    sf::Vector2f sizep = game->getPlayer(0)->getSize();
    sf::Vector2f sizeq (Resources::rodones.getSize().x/4 * Resources::rodones.getSize().x/4 /pWindow->getSize().x * 3
                        , Resources::rodones.getSize().x/2 * Resources::rodones.getSize().x/4 /pWindow->getSize().x * 3);

    if (p.x >= q.x+sizeq.x || p.x+sizep.x <= q.x ||
        p.y >= q.y+sizeq.y || p.y+sizep.y <= q.y) {
       return false;
    } else {
      return true;
    }
}

void Board::updateCollisionLayer2(int xx, int yy, int tx, int ty)
{
	int itx = (int)collisionLayer.getSize().y;
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

    currPlayerPos[0] = game->getPlayer(0)->getPosition();
    currPlayerPos[1] = game->getPlayer(1)->getPosition();

    //rectPlayerMovement[0] = getProperRectangle(currPlayerPos[0], prevPlayerPos[0]);
    //rectPlayerMovement[1] = getProperRectangle(currPlayerPos[1], prevPlayerPos[1]);

    collisionLayer.copy(whiteImage, currPlayerPos[0].x - horOffset, currPlayerPos[0].y - TOP_MARGIN, sf::IntRect(0,0,15,15));
	updateCollisionLayer2(currPlayerPos[0].x - horOffset-10, currPlayerPos[0].y - TOP_MARGIN-10, 35, 35);
    collisionLayer.copy(whiteImage, currPlayerPos[1].x - horOffset, currPlayerPos[1].y - TOP_MARGIN, sf::IntRect(0,0,15,15));
	updateCollisionLayer2(currPlayerPos[1].x - horOffset-10, currPlayerPos[1].y - TOP_MARGIN-10, 35, 35);

    prevPlayerPos[0] = currPlayerPos[0];
    prevPlayerPos[1] = currPlayerPos[1];

    const float temps = 3.1;
    for(std::list<Object>::iterator it = listDebuff.begin(); it != listDebuff.end(); it++) {
        //el que agafa el debuff sels emenja de moment!!!
        for(int i= 0; i < game->getNplayer(); ++i){
            if(colisionRectangle(currPlayerPos[i], it->pos)){
                if(it->typeObject == (int)dB_Speed) {
                    game->getPlayer(i)->setDeBuff(dB_Speed, temps);
                }
                else {
                    game->getPlayer(i)->setDeBuff(dB_Strength, temps);
                }
                it = listDebuff.erase(it);
            }
        }
    }

    for(std::list<Object>::iterator it = listPowerUp.begin(); it != listPowerUp.end(); it++) {
        for(int i= 0; i < game->getNplayer(); ++i){
            if(colisionRectangle(currPlayerPos[i], it->pos)){
                if(it->typeObject == (int)pU_Speed) {
                    game->getPlayer(i)->setPowerUp(pU_Speed, temps);
                }
                else {
                    game->getPlayer(i)->setPowerUp(pU_Strength, temps);
                }
               it = listPowerUp.erase(it);
            }
        }
    }

    for(std::list<Object>::iterator it = listPointObject.begin(); it != listPointObject.end(); it++) {
        for(int i= 0; i < game->getNplayer(); ++i){
            if(colisionRectangle(currPlayerPos[i], it->pos)){
                if(it->typeObject == (int) pO_one ) {
                    //passar al player els punts
                }
                else if(it->typeObject == (int) pO_two) {
                    //passar al player els punts
                }
                else { // pO_three
                    //passar al player els punts
                }
                it = listPointObject.erase(it);
            }
        }
    }
}

void Board::draw() {/*
    sf::Image tunnelTextImage;

    tunnelTextImage = Resources::textureTunnel.copyToImage();

    collisionLayer.createMaskFromColor(sf::Color::White);

    tunnelTextImage.copy(collisionLayer, 0, 0, sf::IntRect(0, 0, 0, 0), true);
    tunnelTextImage.createMaskFromColor(sf::Color::Black);
*/
	TunnelMask.loadFromImage(collisionLayer2);

	bgTunnel.setTexture(TunnelMask);

    pWindow->draw(bgDirt);
    pWindow->draw(bgTunnel);

    for(std::list<Object>::iterator it = listDebuff.begin(); it != listDebuff.end(); it++) {
        if(it->typeObject == (int)dB_Speed) {
            spDBSpeed.setPosition(it->pos);
            pWindow->draw(spDBSpeed);
        }
        else {
            spDBStrength.setPosition(it->pos);
            pWindow->draw(spDBStrength);
        }
    }

    for(std::list<Object>::iterator it = listPowerUp.begin(); it != listPowerUp.end(); it++) {
        if(it->typeObject == (int)pU_Speed) {
            spPUSpeed.setPosition(it->pos);
            pWindow->draw(spPUSpeed);
        }
        else {
            spPUStrength.setPosition(it->pos);
            pWindow->draw(spPUStrength);
        }
    }

    for(std::list<Object>::iterator it = listPointObject.begin(); it != listPointObject.end(); it++) {
        if(it->typeObject == (int)pO_one) {
            spPOOne.setPosition(it->pos);
            pWindow->draw(spPOOne);
        }
        else if(it->typeObject == (int)pO_two) {
            spPOTwo.setPosition(it->pos);
            pWindow->draw(spPOTwo);
        }
        else {
            spPOThree.setPosition(it->pos);
            pWindow->draw(spPOThree);
        }
    }
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

    x = rand()%800 + horOffset;
    y = rand()%800 + TOP_MARGIN;

    Object tmp;
    tmp.typeObject = rand()%2;
    tmp.pos = sf::Vector2f(x, y);

    listDebuff.push_back(tmp);
}

void Board::SpawnPowerUp() {
    int x, y;

    x = rand()%800 + horOffset;
    y = rand()%800 + TOP_MARGIN;

    Object tmp;
    tmp.typeObject = rand()%2;
    tmp.pos = sf::Vector2f(x, y);

    listPowerUp.push_back(tmp);
}

void Board::SpawnPointObject(int points) {
    int x, y;

    x = rand()%800 + horOffset;
    y = rand()%800 + TOP_MARGIN;

    Object tmp;
    tmp.typeObject = points - 1;
    tmp.pos = sf::Vector2f(x, y);
    listPointObject.push_back(tmp);
}
