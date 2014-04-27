#include "LD48.hpp"

LD48::LD48(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style)
    , gameState(playing)
    , ui(this){
    ui.changeState(gameState);
    init();
}

LD48::~LD48() {}

void LD48::init() {
    nPlayers = 2;
    players = std::vector<Player>(nPlayers);
    for (unsigned i = 0; i < players.size(); ++i) {
        sf::Vector2f pos(800,2);
        players[i] = Player(i,pos,this);
    }
    isKeyPressed = std::vector<dir>(nPlayers);
    float boardWidth = 800;
    board = Board(this, boardWidth);
}

void LD48::update(float deltaTime){
    if (gameState == playing) {
        for (unsigned i = 0; i < players.size(); ++i) players[i].update(deltaTime);
        board.update();
    }
}

void LD48::draw(){
    board.draw();
    if (gameState == playing) {
        for (unsigned i = 0; i < players.size(); ++i) players[i].draw(window);
    }
    ui.draw();
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
    switch (event.key.code) {
    case sf::Keyboard::Escape:
        window.close();
        break;
    case sf::Keyboard::A:
        isKeyPressed[0] = left;
        break;
    case sf::Keyboard::W:
        isKeyPressed[0] = up;
        break;
    case sf::Keyboard::S:
        isKeyPressed[0] = down;
        break;
    case sf::Keyboard::D:
        isKeyPressed[0] = right;
        break;
    case sf::Keyboard::Left:
        isKeyPressed[1] = left;
        break;
    case sf::Keyboard::Up:
        isKeyPressed[1] = up;
        break;
    case sf::Keyboard::Down:
        isKeyPressed[1] = down;
        break;
    case sf::Keyboard::Right:
        isKeyPressed[1] = right;
        break;
    case sf::Keyboard::P:
        gameState = playing;
    default:
        break;
    }
}

void LD48::keyReleased(sf::Event event) {
    switch (event.key.code) {
    case sf::Keyboard::A:
        if(isKeyPressed[0] == left) isKeyPressed[0] = none;
        break;
    case sf::Keyboard::W:
        if(isKeyPressed[0] == up) isKeyPressed[0] = none;
        break;
    case sf::Keyboard::S:
        if(isKeyPressed[0] == down) isKeyPressed[0] = none;
        break;
    case sf::Keyboard::D:
        if(isKeyPressed[0] == right) isKeyPressed[0] = none;
        break;
    case sf::Keyboard::Left:
        if(isKeyPressed[1] == left) isKeyPressed[1] = none;
        break;
    case sf::Keyboard::Up:
        if(isKeyPressed[1] == up) isKeyPressed[1] = none;
        break;
    case sf::Keyboard::Down:
        if(isKeyPressed[1] == down) isKeyPressed[1] = none;
        break;
    case sf::Keyboard::Right:
        if(isKeyPressed[1] == right) isKeyPressed[1] = none;
        break;
    default:
        break;
    }
}

dir LD48::getDirection(int i) {
    return isKeyPressed[i];
}

Board* LD48::getBoard() {
    return &board;
}

Player* LD48::getPlayer(int id){
    return &players[id];
}

sf::RenderWindow* LD48::getWindow() {
    return &window;
}
