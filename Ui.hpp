#ifndef UI_HPP
#define UI_HPP
#include "utils.hpp"

class LD48;
class Ui {
public:
    Ui(LD48* game);
    void draw();
    void init();
    void update();
    void updateScore();
    void changeState(state s);
    void setKeyPressed(sf::Keyboard::Key k);
    void win(int w);
    int getNPlayers();
private:
    LD48* game;
    sf::Sprite fondo;
    sf::Font font;
    sf::Text title;
    std::vector<std::pair<sf::Text,sf::Text> > texts;
    state currentState;
    state beforeState;
    int nPlayers;
    int winner;
    unsigned select;
    void setText();
    void setPositions();
    void changeSelected(int newSelected);
};

#endif // UI_HPP
