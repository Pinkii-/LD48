#include "LD48.hpp"

LD48::LD48(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style), board() {
    players = std::vector<Player>(2);
    isKeyPressed = std::vector<dir>(2);
}

LD48::~LD48() {}

void LD48::init() {
    for (unsigned i = 0; i < players.size(); ++i) {
        players[i] = Player(i,pos,this);
    }
}

void LD48::update(float deltaTime){
    for (unsigned i = 0; i < players.size(); ++i) players[i].update(deltaTime);
    board.update();
}

void LD48::draw(){
    for (unsigned i = 0; i < players.size(); ++i) players[i].draw(window);
    board.draw(window);
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
    if (event.key.code == sf::Keyboard::Escape) window.close();
}

void LD48::keyReleased(sf::Event event) {

}
