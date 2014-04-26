#include "Resources.hpp"

sf::Texture     Resources::textureTunnel;
sf::Texture     Resources::textureDirt;
sf::Texture     Resources::menuTexture;
sf::Font        Resources::menuFont;

void Resources::load() {
    textureTunnel.loadFromFile("resources/test1.png");
    textureDirt.loadFromFile("resources/test1.png");
    menuTexture.loadFromFile("resources/otono-bosque-hojas.jpg");
    menuFont.loadFromFile("resources/Call_me_maybe.ttf");
}
