#ifndef UI_HPP
#define UI_HPP
#include "utils.hpp"

class LD48;
class Ui {
public:
    Ui(LD48* game, state s);
private:
    LD48* game;
};

#endif // UI_HPP
