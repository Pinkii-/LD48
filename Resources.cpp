#include "Resources.hpp"

sf::Texture     Resources::textureTunnel;
sf::Texture     Resources::textureDirt;
sf::Texture     Resources::menuTexture;
sf::Texture     Resources::player;
sf::Texture     Resources::rodones;
sf::Font        Resources::menuFont;
sf::Shader      Resources::tunnelShader;
sf::Shader      Resources::waterShader;

void Resources::load() {
    textureTunnel.loadFromFile("resources/dirt.png");
    textureDirt.loadFromFile("resources/background.png");
    menuTexture.loadFromFile("resources/Portada_hormigas_LD48.jpeg");
    player.loadFromFile("resources/sprite.png");
    rodones.loadFromFile("resources/rodones.png");
    menuFont.loadFromFile("resources/Call_me_maybe.ttf");
    tunnelShader.loadFromFile("shaders/tunnel.frag", sf::Shader::Fragment);
    waterShader.loadFromFile("shaders/water.frag", sf::Shader::Fragment);
}
