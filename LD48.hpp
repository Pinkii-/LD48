#ifndef MYGAME_H
#define MYGAME_H
#include "Game.hpp"
#include "Player.hpp"
#include "Board.hpp"
#include "Ui.hpp"

class Object;
class Player;
class LD48 : public Game {
public:
    LD48(int scrwidth, int scrheight, std::string title, int style);
    ~LD48();
    void init(int nPlayer);
    void update(float deltaTime);
    void draw();
    void processEvents();
    void keyPressed(sf::Event event);
    void keyReleased(sf::Event event);
    void setState(state s);
    int getNplayer();
    dir getDirection(int id);
    Board* getBoard();
    Player* getPlayer(int id);
    sf::RenderWindow* getWindow();
    void addObject(Object* obj);
    void spawnCollectible(collectible type);
private:
    state gameState;
    Ui ui;
    Board board;

    std::list<Object*> objects;

    std::vector<dir> isKeyPressed;
    int nPlayers;
};

#endif // MYGAME_H
