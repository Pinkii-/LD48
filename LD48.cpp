#include "LD48.hpp"
#include "Object.hpp"
#include "Collectible.hpp"

LD48::LD48(int scrwidth, int scrheight, std::string title, int style)
    : Game(scrwidth,scrheight,title,style)
    , gameState(menu)
    , ui(this){
    ui.init();
    srand (time(NULL));
}

LD48::~LD48() {}


void LD48::addObject(Object* obj)
{
    objects.push_back(obj);
}

void LD48::init(int nPlayer) {
    ui.changeState(playing);
    gameState = playing;
    nPlayers = nPlayer;
    spawnTimer = rand()%2 + 3;;

    for (unsigned i = 0; i < 2; ++i) {
        Player* p = new Player(i, this);
        p->position = sf::Vector2f ((window.getSize().x/2)-10*(nPlayers-1)+20*i, 230);
        addObject(p);
    }

    isKeyPressed = std::vector<dir>(nPlayers);
    for(int i = 0; i < nPlayers; i++)
    {
        isKeyPressed[i] = none;
    }

    float boardWidth = 800;
    board = Board(this, boardWidth);

    for(int i = 0; i < N_STARTING_OBJECTS; i++)
        spawnRandomCollectible();
}

void LD48::update(float deltaTime){
    if (gameState == playing) {

        for(std::list<Object*>::iterator it = objects.begin(); it != objects.end(); it++)
        {
            (*it)->update(deltaTime);
            if( (*it)->receivesCollisions)
                for(std::list<Object*>::iterator it2 = objects.begin(); it2 != objects.end(); it2++)
                    if(*it != *it2 && (*it)->collidesWith(*it2))
                        (*it)->collidedWith(*it2);
        }

        for(std::list<Object*>::iterator it = objects.begin(); it != objects.end();)
        {
            if((*it)->dead)
            {
                std::list<Object*>::iterator it2 = it;
                it2++;
                objects.erase(it);
                it = it2;
            }
            else
                it++;
        }

        board.update(deltaTime);

        spawnTimer -= deltaTime;
        if(spawnTimer <= 0)
        {
            spawnRandomCollectible();
            spawnTimer = rand()%2 + 3;
        }
    }
    ui.update();
}

void LD48::spawnCollectible(collectible type)
{
    int x = rand()%800 + board.horOffset;
    int y = rand()%800 + TOP_MARGIN;

    addObject(new Collectible(this, type, sf::Vector2f(x, y)));
}

void LD48::spawnRandomCollectible()
{
    int randSpawns = rand()%5;
    if(randSpawns < 1) spawnCollectible((rand()%2==0) ? dB_Speed : dB_Strength);
    else if(randSpawns < 2) spawnCollectible((rand()%2==0) ? pU_Speed : pU_Strength);
    else if(randSpawns < 5) spawnCollectible(collectible(pO_one + (rand()%3)));
}

void LD48::draw(){
    if (gameState != playing) ui.draw();
    else {
        board.draw();
        for(std::list<Object*>::iterator it = objects.begin(); it != objects.end(); it++)
            (*it)->draw();
        ui.draw();
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

    //TODO FIX HACK
    for(std::list<Object*>::iterator it = objects.begin(); it != objects.end(); it++)
    {
        if(id == 0)
            return (Player*) *it;
        id--;
    }
    return NULL;
}

sf::RenderWindow* LD48::getWindow() {
    return &window;
}

int LD48::getNplayer(){
    return nPlayers;
}


