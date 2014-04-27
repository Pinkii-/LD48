#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "utils.hpp"

class LD48;
class Object
{
public:
    Object(LD48* game, sf::Vector2f size, sf::Texture& tex, sf::Vector2i spriteCount );

    LD48* game;

    sf::Vector2f position;
    sf::Vector2f size;
    sf::Texture& tex;
    sf::Vector2i spriteCount;
    sf::Vector2i spriteNum;
    sf::Sprite sprite;

    virtual void update(float deltaTime);
    virtual void draw();

    bool receivesCollisions;
    bool dead;
    virtual void collidedWith(Object* b);
    bool collidesWith(Object* b);
};

#endif // OBJECT_HPP
