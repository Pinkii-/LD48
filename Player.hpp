/******************************Player.hpp**********************************/
#ifndef PLAYER
#define PLAYER

#include "LD48.hpp"
#include "utils.hpp"
#include <SFML/Graphics.hpp>

class LD48;

class Player {

	public:
		//Constructor
		Player();

		//Destructor
		~Player();

		//draw the player
		void draw();

		//set powerup or debuf
		void setDeBuff(deBuff dB, float time);
		void setPowerUp(powerUp pU. float time);
		
		//return the position
		sf::Vector2f getPosition();

		//recieve deltatime
		void update(float deltaTime);

	private:
		//FUNCTIONS
		void updateTimes();

		//VARIABLES
		//number variables
		int id;
		float digSpeed;
		float walkSpeed;
		float spriteTimeCounter;
		float time_between_sprites;

		//special objects variables
		LD48* pare;
		sf::Clock timer;
		sf::Sprite player;
		sf::Texture pTexture;

		//vector and vector2 with float variables
		VFloat deBuffs;
		VFloat powerUps;
		sf::Vector2f position;
		sf::Vector2f spriteSize;
		sf::Vector2f spriteSource;

};


#endif