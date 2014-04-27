#include "Resources.hpp"

sf::Image     Resources::textureTunnel;
sf::Texture     Resources::textureDirt;
sf::Texture     Resources::menuTexture;
sf::Texture     Resources::playingTexture;
sf::Texture     Resources::player;
sf::Texture     Resources::rodones;
sf::Font        Resources::menuFont;

void Resources::load() {
    textureTunnel.loadFromFile("resources/dirt.png");
    textureDirt.loadFromFile("resources/background.png");
    menuTexture.loadFromFile("resources/otono-bosque-hojas.jpg");
    playingTexture.loadFromFile("resources/playingTexture.png");
    player.loadFromFile("resources/sprite.png");
    rodones.loadFromFile("resources/rodones.png");
    menuFont.loadFromFile("resources/Call_me_maybe.ttf");
}
