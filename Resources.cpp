#include "Resources.hpp"

sf::Font        Resources::menuFont;

void Resources::load() {
    menuFont.loadFromFile("resources/Call_me_maybe.ttf");
}
