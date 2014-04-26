/******************************Player.hpp**********************************/
#ifndef PLAYER
#define PLAYER

#include "utils.hpp"
#include <SFML/Graphics.hpp>

class LD48;

class Player {

	public:
		//Constructor
		Player();

		//Destructor
		~Player();

		//recieve deltatime
		void update();

		//draw the player
		void draw();

		//return the position
		sf::Vector2f getPosition();
		
        void setDeBuff(deBuff dB);
        void setPowerUp(powerUp pU);

	private:
		//Punter al pare (HAX)
		LD48* pare;

		//Position of the player
		sf::Vector2f position;

		//deBuffs and powerUps of the player 
		std::vector<bool> deBuffs;
		std::vector<bool> powerUps;

};


#endif
