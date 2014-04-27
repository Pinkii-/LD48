#include "Resources.hpp"

sf::Texture     Resources::textureTunnel;
sf::Texture     Resources::textureDirt;
sf::Texture     Resources::menuTexture;
sf::Texture     Resources::playingTexture;
sf::Texture     Resources::player;
sf::Font        Resources::menuFont;

void Resources::load() {
    textureTunnel.loadFromFile("resources/dirt2.png");
    textureDirt.loadFromFile("resources/dirt.png");
    menuTexture.loadFromFile("resources/otono-bosque-hojas.jpg");
    playingTexture.loadFromFile("resources/playingTexture.png");
    player.loadFromFile("resources/sprite.png");
    menuFont.loadFromFile("resources/Call_me_maybe.ttf");
}
