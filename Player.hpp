/******************************Player.hpp**********************************/
#ifndef PLAYER
#define PLAYER

#include "utils.hpp"
#include "Object.hpp"
#include <SFML/Graphics.hpp>

//              		  N  S   E   W
const int movx[4] = { 0,  0,  1, -1};
const int movy[4] = {-1,  1,  0,  0};

//                        sp    st   ph    sp    st
const float bDigged[] = {  3,   1,  1,  0.1,   1 };
const float bFull[]   = {    1, 3,  1,    1, 0.1 };

class LD48;

class Player : public Object {

	public:
		//Constructor
        Player(int identifier, LD48* p);

        //recieve deltatime
        virtual void update(float deltaTime);
        virtual void collidedWith(Object *b);
		//set powerup or debuf
        void setBuff(collectible b, float time);

        int getPoints();

	private:

		//VARIABLES
		//number variables
		int id;
        int points;
        float speed;
		float digSpeed;
		float walkSpeed;
		float spriteTimeCounter;
		float time_between_sprites;

		//vector and vector2 with float variables
        VFloat buffs;
};


#endif
