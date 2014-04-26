#ifndef UI_HPP
#define UI_HPP
#include "utils.hpp"

class LD48;
class Ui {
public:
    Ui(LD48* game);
    void draw();
    void changeState(state s);
    void setText(state s);
private:
    LD48* game;
    sf::Sprite fondo;
    sf::Font font;
    std::vector<sf::Text> texts;
};

#endif // UI_HPP
