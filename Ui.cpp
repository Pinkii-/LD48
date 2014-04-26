#include "Ui.hpp"
#include "LD48.hpp"

Ui::Ui(LD48* g) : game(g){
}

void Ui::draw() {
    game->getWindow()->draw(fondo);
    for(unsigned i = 0; i < texts.size(); ++i) game->getWindow()->draw(texts[i]);
}

void Ui::changeState(state s) {
    if (s == menu) {
        font = Resources::menuFont;
        fondo.setTexture(Resources::menuTexture);
        fondo.setPosition(sf::Vector2f(0,0));
        float scalex, scaley;
        scalex =  game->getWindow()->getSize().x/float(fondo.getTexture()->getSize().x);
        scaley =  game->getWindow()->getSize().y/float(fondo.getTexture()->getSize().y);
        fondo.setScale(scalex,scaley);
        texts = std::vector<sf::Text>(6);
        setText(s);
    }
}

void Ui::setText(state s) {
    if (s == menu) {
        texts[0].setString("2 Players");
        texts[1].setString("3 Players");
        texts[2].setString("4 Players");
        texts[3].setString("Help");
        texts[4].setString("Options");
        texts[5].setString("Exit");
    }
}
