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

typedef std::vector<bool> VBool;

enum powerUp {
  pU_Speed, pU_Strength, pU_Phantom, qtt_powerUp
};

enum deBuff {
  dB_Speed, dB_Strength, dB_Phantom, qtt_deBuff
};

#endif // UTILS_HPP
