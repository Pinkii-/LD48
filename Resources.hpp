#ifndef RESOURCES_HPP
#define RESOURCES_HPP
#include "utils.hpp"

class Resources {
public:
    static void load();
    static sf::Texture textureTunnel;
    static sf::Texture textureDirt;
    static sf::Texture menuTexture;
    static sf::Texture playingTexture;
    static sf::Texture player;
    static sf::Texture rodones;
    static sf::Font menuFont;
    static sf::Shader tunnelShader;
};

#endif // RESOURCES_HPP
