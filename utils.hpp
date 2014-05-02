#ifndef UTILS_HPP
#define UTILS_HPP

//STL (Standard Toolkit Library)
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <time.h>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <stdlib.h>

//SFML (Simple Fast Media Library)
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

//Constant variables
const int N_STARTING_OBJECTS = 5;

//Typedefinitions
typedef std::vector<bool> VBool;
typedef std::vector<float> VFloat;

//Game States
enum state {
    menu, help, credits, playing, unstarted, winned, selectMaxPoints, qtt_state
};

/* Per afegir un debuff, afegirlo despres del dB_speed
 o es trenca massa </3 */
//Collectibles -> PowerUps, DeBuffs and Points
enum collectible {
    pU_Speed, pU_Strength, pU_Phantom, dB_Speed, dB_Strength, qtt_buff,
    pO_one, pO_two, pO_three, qtt_collectible
};

//Directions that players can take
enum dir {
    up, down, right, left, none, qtt_dir
};

//States that the board can have
enum boardType {
    full, digged, blocked, qtt_boardType
};

#endif // UTILS_HPP
