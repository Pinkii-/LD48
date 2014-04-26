#include <Resources.hpp>
#include <LD48.hpp>

int main() {
    Resources::load();
    LD48 mygame(sf::VideoMode::getFullscreenModes()[0].width,sf::VideoMode::getFullscreenModes()[0].height
            ,"LD48"
            ,sf::Style::Default);
    mygame.run();
    return 0;
}

