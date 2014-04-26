#ifndef UI_HPP
#define UI_HPP
#include "utils.hpp"

class LD48;
class Ui {
public:
    Ui(LD48* game, state s);
    void draw();
private:
    LD48* game;
    sf::Sprite fondo;
    sf::Font font;
};

#endif // UI_HPP
