#include "Resources.hpp"


sf::Texture     Resources::texture;
sf::Font        Resources::font;

void Resources::load() {
    texture.loadFromFile("resources/test1.png");
    font.loadFromFile("resources/font.ttf");
}
