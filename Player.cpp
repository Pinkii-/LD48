/******************************Player.cpp**********************************/
#include "Player.hpp"
#include "LD48.hpp"

Player::Player() {

}
//Constructor
Player::Player(int identifier, sf::Vector2f pos, LD48* p) {

	pare = p;
	position = pos;
	id = identifier;
	deBuff qttdB = qtt_deBuff;
	powerUp qttpU = qtt_powerUp;
	deBuffs = VFloat(qttdB, false);
	powerUps = VFloat(qttpU, false);
	spriteSource.x = spriteSource.y = 0.0;
    /***SPEED VALUE***/	speed = 180;
	time_between_sprites = 0.09;
	spriteTimeCounter = 0.0;
	digSpeed = speed*0.8;
	walkSpeed = speed;
	
	if(!pTexture.loadFromFile("pics/sprites.png")) std::cout << "personatge Not Loaded " << std::endl;
    spriteSize.x =  pTexture.getSize().x/4;
    spriteSize.y =  pTexture.getSize().y/4;
	player.setTexture(pTexture);
}

sf::Vector2f Player::getPosition(){
	return position;
}
//Destructor
Player::~Player() {

}

void Player::updateTimes(){
    float time = timer.restart().asSeconds();
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
    if(direction != none){

		sf::Vector2f desti;
        desti.x = position.x + digSpeed*movx[direction]*deltaTime;
        desti.y = position.y + digSpeed*movy[direction]*deltaTime;
        boardType bT = pare->getBoard()->getBoardType(desti);

		if(bT == digged) {
			actSpeed = digSpeed;
			for(int i = 0; i < powerUps.size(); ++i){
                if(powerUps[i] > 0) actSpeed *= pUdigged[(int)powerUps[i]];
			}
			for(int i = 0; i < deBuffs.size(); ++i){
                if(powerUps[i] > 0) actSpeed *= dBdigged[(int)powerUps[i]];
			}
		}
		else if(bT == full) {
			actSpeed = walkSpeed;
			for(int i = 0; i < powerUps.size(); ++i){
                if(powerUps[i] > 0) actSpeed *= pUfull[(int)powerUps[i]];
			}
			for(int i = 0; i < deBuffs.size(); ++i){
                if(powerUps[i] > 0) actSpeed *= dBfull[(int)powerUps[i]];
			}
		}
		else actSpeed = 0;
	
		//Set value to movement variables and update spritesource
        if(spriteSource.y == direction){
            position.x += actSpeed*movx[direction]*deltaTime;
            position.y += actSpeed*movy[direction]*deltaTime;
		}
        else spriteSource.y = direction;
		if (spriteTimeCounter >= time_between_sprites){
			spriteTimeCounter = 0;
			++spriteSource.x;
		}
	}
	//Checking the sprite sources to be ok
	if(spriteSource.x >= 4) spriteSource.x = 0;
}

void Player::setDeBuff(deBuff dB, float time){
	deBuffs[dB] = time;
}

void Player::setPowerUp(powerUp pU, float time){
	powerUps[pU] = time;
}

//draw the player
void Player::draw(sf::RenderWindow* window){
	player.setTextureRect(sf::IntRect(spriteSource.x*spriteSize.x, 
			spriteSource.y*spriteSize.y, spriteSize.x, spriteSize.y));
	player.setPosition(position);
	window->draw(player);
}

