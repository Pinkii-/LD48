#include "Ui.hpp"
#include "LD48.hpp"

Ui::Ui(LD48* g, state s) : game(g){
    if (s == menu) {
        font = Resources::menuFont;
        fondo.setTexture(Resources::menuTexture);
        fondo.setPosition(sf::Vector2f(0,0));
        float scalex, scaley;
        scalex =  g->getWindow()->getSize().x/float(fondo.getTexture()->getSize().x);
        scaley =  g->getWindow()->getSize().y/float(fondo.getTexture()->getSize().y);
        fondo.setScale(scalex,scaley);
    }
}

void Ui::draw() {
    game->getWindow()->draw(fondo);
}
