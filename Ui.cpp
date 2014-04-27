#include "Ui.hpp"
#include "LD48.hpp"

Ui::Ui(LD48* g) : game(g){
    select = 0;
    currentState = menu;
}

void Ui::draw() {
    game->getWindow()->draw(fondo);
    if (currentState != playing) {
        for(unsigned i = 0; i < texts.size(); ++i) {
            game->getWindow()->draw(title);
            game->getWindow()->draw(texts[i].second);
            game->getWindow()->draw(texts[i].first);
        }
    }
}

void Ui::changeState(state s) {
    currentState = s;
    if (currentState == menu or currentState == help or currentState == options) {
        font = Resources::menuFont;
        fondo.setTexture(Resources::menuTexture);
        fondo.setPosition(sf::Vector2f(0,0));
        float scalex, scaley;
        scalex =  game->getWindow()->getSize().x/float(fondo.getTexture()->getSize().x);
        scaley =  game->getWindow()->getSize().y/float(fondo.getTexture()->getSize().y);
        fondo.setScale(scalex,scaley);
    }
    if (currentState == menu) {
        texts = std::vector<std::pair<sf::Text,sf::Text> >(6);
        setText();
        setPositions();
        changeSelected(0);
    }
    else if (currentState == help) {
        texts = std::vector<std::pair<sf::Text,sf::Text> >(1);
        setText();
        setPositions();
        changeSelected(0);
    }
    else {
        //        fondo.setTexture(Resources::playingTexture);
        fondo = sf::Sprite();
    }
}

void Ui::setKeyPressed(sf::Keyboard::Key k) {
    if (k == sf::Keyboard::Up or k == sf::Keyboard::W) {
        int aux = select;
        if (select-1<0) aux = 6;
        changeSelected((aux-1)%6);
    }
    else if (k == sf::Keyboard::Down or k == sf::Keyboard::S) changeSelected((select+1)%6);
    else if (k == sf::Keyboard::Return) {
        switch (select) {
        case 0:
            nPlayers = 2;
            game->init();
            break;
        case 1:
            nPlayers = 3;
            game->init();
            break;
        case 2:
            nPlayers = 4;
            game->init();
            break;
        case 3:
            changeState(help);
            break;
        case 4:
            changeState(options);
            break;
        case 5:
            game->getWindow()->close();
            break;
        default:
            break;
        }
    }
}

int Ui::getNPlayers() {
    return nPlayers;
}

void Ui::setText() {
    if (currentState == menu) {
        title.setString("LD48");
        texts[0].first.setString("2 Players");
        texts[1].first.setString("3 Players");
        texts[2].first.setString("4 Players");
        texts[3].first.setString("Help"     );
        texts[4].first.setString("Options"  );
        texts[5].first.setString("Exit"     );

        texts[0].second.setString("2 Players");
        texts[1].second.setString("3 Players");
        texts[2].second.setString("4 Players");
        texts[3].second.setString("Help"     );
        texts[4].second.setString("Options"  );
        texts[5].second.setString("Exit"     );
    }
}

void Ui::setPositions() {
    sf::Vector2u windowSize = game->getWindow()->getSize();
    int msf = 70;
    title.setCharacterSize(msf+40);
    title.setColor(sf::Color::White);
    title.setFont(Resources::menuFont);
    title.setStyle(sf::Text::Bold);
    sf::FloatRect textRect = title.getLocalBounds();
    title.setOrigin(textRect.left + textRect.width/2.0f,
                    textRect.top  + textRect.height/2.0f);
    for (unsigned i = 0; i < texts.size(); ++i) {
        texts[i].first.setCharacterSize(msf);
        texts[i].second.setCharacterSize(msf);
        texts[i].first.setFont(Resources::menuFont);
        texts[i].second.setFont(Resources::menuFont);
        texts[i].second.setStyle(sf::Text::Bold);
        texts[i].first.setColor(sf::Color(0,0,0,100));
        texts[i].second.setColor(sf::Color(255,255,255,255));
        textRect = texts[i].first.getLocalBounds();
        texts[i].first.setOrigin(textRect.left + textRect.width/2.0f,
                                 textRect.top  + textRect.height/2.0f);
        textRect = texts[i].second.getLocalBounds();
        texts[i].second.setOrigin(textRect.left + textRect.width/2.0f,
                                  textRect.top  + textRect.height/2.0f);
    }
    if (currentState == menu) {
        title.setPosition(sf::Vector2f(windowSize.x/2.0f,windowSize.y/((texts.size()*1.5))));
        for (unsigned i = 0; i < texts.size(); ++i) {
            texts[i].first.setPosition(sf::Vector2f(windowSize.x/2.0f,windowSize.y/(texts.size()+2)*(i+2)));
            texts[i].second.setPosition(sf::Vector2f(windowSize.x/2.0f,windowSize.y/(texts.size()+2)*(i+2)));
            texts[i].second.setScale(1,1.15);
        }
    }
}

void Ui::changeSelected(int newSelected) {
    texts[select].first.setColor(sf::Color(0,0,0,100));
    select = newSelected;
    texts[select].first.setColor(sf::Color(0,0,0,255));
}
