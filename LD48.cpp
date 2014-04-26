#include "LD48.hpp"

LD48::LD48(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style) {
    //Create the components of the game and init them
}

LD48::~LD48() {}

void LD48::update(float deltaTime){
    // Update the game
}

void LD48::draw(){
    // Draw the game
}

void LD48::processEvents(){
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            keyPressed(event);
            break;
        case sf::Event::KeyReleased:
            keyReleased(event);
        default:
            break;
        }
    }
}

void LD48::keyPressed(sf::Event event) {

}

void LD48::keyReleased(sf::Event event) {

}
