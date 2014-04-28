#include "Collectible.hpp"
#include "Resources.hpp"

Collectible::Collectible(LD48* game, collectible type, sf::Vector2f position)
    : Object(game, sf::Vector2f(15, 15), Resources::rodones, sf::Vector2i(4, 2)),
      type(type)

{
    this->position = position;

    switch(type)
    {
    case pO_one:        spriteNum = sf::Vector2i(2, 0); break;
    case pO_two:        spriteNum = sf::Vector2i(3, 0); break;
    case pO_three:      spriteNum = sf::Vector2i(2, 1); break;
    case pU_Speed:      spriteNum = sf::Vector2i(1, 0); break;
    case dB_Speed:      spriteNum = sf::Vector2i(1, 1); break;
    case dB_Strength:   spriteNum = sf::Vector2i(0, 1); break;
    case pU_Strength:   spriteNum = sf::Vector2i(0, 0); break;
    default:                                            break;
    }
}
