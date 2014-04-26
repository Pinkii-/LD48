#include "Game.hpp"

Game::Game(int scrwidth, int scrheight, std::string title, int style)
    : window(sf::VideoMode(scrwidth,scrheight),title,style) {
    window.setMouseCursorVisible(true); //Config as you want
    window.setVerticalSyncEnabled(true); //Config as you want
}

Game::~Game() {}

void Game::run() {
    sf::Clock c;
    srand(time(0));
    while(window.isOpen()) {
        float deltaTime = c.restart().asSeconds();

        processEvents();
        update(deltaTime);
        render();
    }
}

void Game::render() {
    window.clear();
    draw();
    window.display();
}
