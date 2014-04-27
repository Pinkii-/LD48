/******************************Player.cpp**********************************/
#include "Player.hpp"
#include "LD48.hpp"
#include "Collectible.hpp"

#include<iostream>
using namespace std;


//Constructor
Player::Player(int identifier, LD48* p) : Object(p, sf::Vector2f(15, 15), Resources::player, sf::Vector2i(4, 4))
{

	id = identifier;
    buffs = VFloat(qtt_buff, 0);

    /***SPEED VALUE***/
    speed = 180;
	time_between_sprites = 0.09;
	spriteTimeCounter = 0.0;
    digSpeed = speed*0.4;
	walkSpeed = speed;
	

    receivesCollisions = true;
}



void Player::collidedWith(Object *b)
{
    Collectible* c = dynamic_cast<Collectible*> (b);
    if(c)
    {
        if(c->type < qtt_buff)
            setBuff(c->type, 3);
        else
        {
            //blabla
        }
        b->dead = true;
    }
}

//Update function
void Player::update(float deltaTime){

    for(int i = 0; i < buffs.size(); ++i)
        buffs[i] -= deltaTime;

    dir direction = game->getDirection(id);
    float actSpeed = speed;

	spriteTimeCounter += deltaTime;
    if(direction != none){

		sf::Vector2f desti;
        desti.x = position.x + digSpeed*movx[direction]*deltaTime;
        desti.y = position.y + digSpeed*movy[direction]*deltaTime;
        boardType bT = game->getBoard()->getBoardType(desti);

		if(bT == digged) {
            actSpeed = walkSpeed;
            for(int i = 0; i < buffs.size(); ++i)
                if(buffs[i] > 0) actSpeed *= bDigged[i];
		}
		else if(bT == full) {
            actSpeed = digSpeed;
            for(int i = 0; i < buffs.size(); ++i)
                if(buffs[i] > 0) actSpeed *= bFull[i];
		}
		else actSpeed = 0;

        position.x += actSpeed*movx[direction]*deltaTime;
        position.y += actSpeed*movy[direction]*deltaTime;

        spriteNum.y = direction;
        if (spriteTimeCounter >= time_between_sprites){
			spriteTimeCounter = 0;
            ++spriteNum.x;
            //Checking the sprite sources to be ok
            if(spriteNum.x >= 4) spriteNum.x = 0;
        }
	}
}

void Player::setBuff(collectible b, float time){
    buffs[b] = time;
}


