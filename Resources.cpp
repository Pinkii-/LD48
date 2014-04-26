#include "Resources.hpp"

sf::Texture     Resources::textureTunnel;
sf::Texture     Resources::textureDirt;
sf::Font        Resources::menuFont;

void Resources::load() {
    textureTunnel.loadFromFile("resources/dirt2.png");
    textureDirt.loadFromFile("resources/dirt.png");
    menuFont.loadFromFile("resources/Call_me_maybe.ttf");
}
