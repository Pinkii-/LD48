#include "LD48.hpp"

LD48::LD48(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style)
    , gameState(menu)
    , ui(this){
    ui.init();
}

LD48::~LD48() {}

void LD48::init(int nPlayer) {
    ui.changeState(playing);
    gameState = playing;
    nPlayers = nPlayer;
    players = std::vector<Player>(nPlayers);
    for (unsigned i = 0; i < players.size(); ++i) {
        sf::Vector2f pos(800,100*(i+1));
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
    ui.draw();
    if (gameState == playing) {
        board.draw();
        for (unsigned i = 0; i < players.size(); ++i) players[i].draw(window);
    }
}

void LD48::processEvents(){
    sf::Event event;
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape) window.close();
            if (gameState == playing) keyPressed(event);
            else ui.setKeyPressed(event.key.code);
            break;
        case sf::Event::KeyReleased:
            if (gameState == playing) keyReleased(event);
            break;
        default:
            break;
        }
    }
}

void LD48::keyPressed(sf::Event event) {
    switch (event.key.code) {
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
    default:
        if (nPlayers > 2) {
            switch (event.key.code) {
            case sf::Keyboard::J:
                isKeyPressed[2] = left;
                break;
            case sf::Keyboard::I:
                isKeyPressed[2] = up;
                break;
            case sf::Keyboard::K:
                isKeyPressed[2] = down;
                break;
            case sf::Keyboard::L:
                isKeyPressed[2] = right;
                break;
            default:
                break;
            }
        }
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
        if (nPlayers > 2) {
            switch (event.key.code) {
            case sf::Keyboard::J:
                if(isKeyPressed[2] == left) isKeyPressed[2] = none;
                break;
            case sf::Keyboard::I:
                if(isKeyPressed[2] == up) isKeyPressed[2] = none;
                break;
            case sf::Keyboard::K:
                if(isKeyPressed[2] == down) isKeyPressed[2] = none;
                break;
            case sf::Keyboard::L:
                if(isKeyPressed[2] == right) isKeyPressed[2] = none;
                break;
            default:
                break;
            }
        }
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
