/******************************Player.hpp**********************************/
#ifndef PLAYER
#define PLAYER

#include "utils.hpp"
#include <SFML/Graphics.hpp>

//                         sp   st
const float dBdigged[2] = { 0.8,   1 };
const float dBfull[2]   = {   1, 0.8 };

//              		  N  S   E   W
const int movx[4] = { 0,  0,  1, -1};
const int movy[4] = {-1,  1,  0,  0};

//                        sp    st   ph
const float pUdigged[3] = {  1.2,   1,  1 };
const float pUfull[3]   = {    1, 1.2,  1 };

class LD48;
class Player {

	public:
		//Constructor
        Player();
        Player(int identifier, sf::Vector2f pos, LD48* p);

		//Destructor
		~Player();

		//draw the player
        void draw(sf::RenderWindow &window);

		//set powerup or debuf
		void setDeBuff(deBuff dB, float time);
        void setPowerUp(powerUp pU, float time);
		
		//return the position
		sf::Vector2f getPosition();

		//recieve deltatime
		void update(float deltaTime);

        //get the size of the sprite
        sf::Vector2f getSize();


	private:
		//FUNCTIONS
		void updateTimes();

		//VARIABLES
		//number variables
		int id;
        float speed;
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
