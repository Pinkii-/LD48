#include <LD48.hpp>
#include <Resources.hpp>

int main() {
    LD48 mygame(sf::VideoMode::getFullscreenModes()[0].width,sf::VideoMode::getFullscreenModes()[0].height
            ,"LD48"
            ,sf::Style::Default);
    mygame.run();
    return 0;
}

