#include "Resources.hpp"

sf::Texture     Resources::texture;
sf::Texture     Resources::textureTunnel;
sf::Texture     Resources::textureDirt;
sf::Font        Resources::font;

void Resources::load() {
    texture.loadFromFile("resources/test1.png");
    font.loadFromFile("resources/font.ttf");
    textureTunnel.loadFromFile("resources/test1.png");
    textureDirt.loadFromFile("resources/test1.png");
}
