#include <Resources.hpp>
#include <MyGame.hpp>

int main() {
    Resources::load();
    MyGame mygame(sf::VideoMode::getFullscreenModes()[0].width,sf::VideoMode::getFullscreenModes()[0].height // Size of the window <width,height>
            ,"MyGame" // Title of the window
            ,sf::Style::Default); // Style of the window
    mygame.run();
    return 0;
}

