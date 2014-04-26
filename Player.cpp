/******************************Player.cpp**********************************/
#include "Player.hpp"

//Constructor
Player::Player(int identifier, sf::Vector2f pos, LD48* p, ) {

	pare = p;
	position = pos;
	id = identifier;
	deBuff qttdB = qtt_deBuff;
	powerUp qttpU = qtt_powerUp;
	deBuffs = VFloat(qttdB, false);
	powerUps = VFloat(qttpU, false);
	spriteSource.x = spriteSource.y = 0.0;
	/***SPEED VALUE***/	float speed = 180;
	time_between_sprites = 0.09;
	spriteTimeCounter = 0.0;
	digSpeed = speed*0.8;
	walkSpeed = speed;
	
	if(!pTexture.loadFromFile("pics/sprites.png")) std::cout << "personatge Not Loaded " << std::endl;
	spriteSize.x = originalSpriteSize.x = pTexture.getSize().x/4;
	spriteSize.y = originalSpriteSize.y = pTexture.getSize().y/4;
	player.setTexture(pTexture);
}

sf::Vector2f getPosition(){
	return position;
}

//Destructor
Player::~Player() {

}

void Player::updateTimes(){
	float time = deltaClock.restart().asSeconds();
	for(int i = 0; i < deBuffs.size(); ++i){
		if(deBuffs[i] > 0) {
			if(deBuffs[i] <= time) deBuffs[i] = 0;
			else deBuffs[i] -= time;
		}
	}
	for(int i = 0; i < powerUps.size(); ++i){
		if(powerUps[i] > 0) {
			if(powerUps[i] <= time) powerUps[i] = 0;
			else powerUps[i] -= time;
		}
	}
}

//Update function
void Player::update(float deltaTime){
	
	dir direction = pare->getDirection(id);
	int actSpeed = speed;

	spriteTimeCounter += deltaTime;
	if(dir != none){

		sf::Vector2f desti;
		desti.x = position.x + digSpeed*movx[dir]*deltaTime;
		desti.y = position.y + digSpeed*movy[dir]*deltaTime;
		bardType bT = getBoardType(desti);

		if(bT == digged) {
			actSpeed = digSpeed;
			for(int i = 0; i < powerUps.size(); ++i){
				if(powerUps[i] > 0) actSpeed *= pUdigged[powerUps[i]]; 
			}
			for(int i = 0; i < deBuffs.size(); ++i){
				if(powerUps[i] > 0) actSpeed *= dBdigged[powerUps[i]]; 
			}
		}
		else if(bT == full) {
			actSpeed = walkSpeed;
			for(int i = 0; i < powerUps.size(); ++i){
				if(powerUps[i] > 0) actSpeed *= pUfull[powerUps[i]]; 
			}
			for(int i = 0; i < deBuffs.size(); ++i){
				if(powerUps[i] > 0) actSpeed *= dBfull[powerUps[i]]; 
			}
		}
		else actSpeed = 0;
	
		//Set value to movement variables and update spritesource
		if(spriteSource.y == dir){
			position.x += actSpeed*movx[dir]*deltaTime;
			position.y += actSpeed*movy[dir]*deltaTime;
		}
		else spriteSource.y = dir;
		if (spriteTimeCounter >= time_between_sprites){
			spriteTimeCounter = 0;
			++spriteSource.x;
		}
	}
	//Checking the sprite sources to be ok
	if(spriteSource.x >= 4) spriteSource.x = 0;
}

void setDeBuff(deBuff dB, float time){
	deBuffs[dB] = time;
}

void setPowerUp(powerUp pU. float time){
	powerUps[pU] = time;
}

//draw the player
void Player::draw(sf::RenderWindow* window){
	player.setTextureRect(sf::IntRect(spriteSource.x*spriteSize.x, 
			spriteSource.y*spriteSize.y, spriteSize.x, spriteSize.y));
	player.setPosition(position);
	window->draw(player);
}

