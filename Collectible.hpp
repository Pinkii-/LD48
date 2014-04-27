#ifndef COLLECTIBLE_HPP
#define COLLECTIBLE_HPP
#include "Object.hpp"

class Collectible : public Object
{
public:
    Collectible(LD48* game, collectible type, sf::Vector2f position);
    collectible type;
};

#endif // COLLECTIBLE_HPP
