#include "Resources.hpp"

sf::Texture     Resources::textureTunnel;
sf::Texture     Resources::textureDirt;
sf::Texture     Resources::menuTexture;
sf::Texture     Resources::player;
sf::Font        Resources::menuFont;

void Resources::load() {
    textureTunnel.loadFromFile("resources/dirt.png");
    textureDirt.loadFromFile("resources/dirt2.png");
    menuTexture.loadFromFile("resources/otono-bosque-hojas.jpg");
    player.loadFromFile("resources/sprite.png");
    menuFont.loadFromFile("resources/Call_me_maybe.ttf");
}
