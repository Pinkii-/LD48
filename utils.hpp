#ifndef UTILS_HPP
#define UTILS_HPP

//SFML (Simple Fast Media Library)
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

//STL (Standard Toolkit Library)
#include <cmath>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

const int N_STARTING_OBJECTS = 5;
typedef std::vector<bool> VBool;
typedef std::vector<float> VFloat;

enum state {
    menu, help, credits, playing, unstarted, winned, selectMaxPoints
};

// Per afegir un debuff, afegirlo despres del dB_speed o es
// trenca massa <3
enum collectible {
    pU_Speed, pU_Strength, pU_Phantom,
    dB_Speed, dB_Strength, qtt_buff,
    pO_one, pO_two, pO_three, qtt_collectible
};

enum dir {
    up, down, right, left, none
};

enum boardType {
    full, digged, blocked, qtt_boardType
};

#endif // UTILS_HPP
