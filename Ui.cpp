#include "Ui.hpp"
#include "LD48.hpp"

Ui::Ui(LD48* g) : game(g){
    select = 0;
    beforeState = unstarted;
}

void Ui::draw() {
    if (currentState != playing) {
        game->getWindow()->draw(fondo);
        game->getWindow()->draw(title);
        for(unsigned i = 0; i < texts.size(); ++i) {
            game->getWindow()->draw(texts[i].second);
            game->getWindow()->draw(texts[i].first);
        }
    } else {
        for(unsigned i = 0; i < texts.size(); ++i) {
            game->getWindow()->draw(texts[i].second);
            game->getWindow()->draw(texts[i].first);
        }
    }
}

void Ui::init() {
    font = Resources::menuFont;
    fondo.setTexture(Resources::menuTexture);
    fondo.setPosition(sf::Vector2f(0,0));
    float scalex, scaley;
    scalex =  game->getWindow()->getSize().x/float(fondo.getTexture()->getSize().x);
    scaley =  game->getWindow()->getSize().y/float(fondo.getTexture()->getSize().y);
    fondo.setScale(scalex,scaley);
    changeState(menu);
}

void Ui::update() {
    if (beforeState != currentState) {
        if (currentState == menu) {
            texts.resize(6);
            setText();
            setPositions();
            changeSelected(0);
        } else if (currentState == help) {
            texts.resize(1);
            setText();
            setPositions();
            changeSelected(0);
        } else if (currentState == credits) {
            texts.resize(10);
            setText();
            setPositions();
            changeSelected(5);
        } else if (currentState == playing) {
            texts.resize(nPlayers * 3);
            setText();
            setPositions();
        }
    }
    if (currentState == playing) {
        updateScore();
    }
    beforeState = currentState;
}

void Ui::updateScore() {
    for (int i = 0; i < nPlayers; ++i) {
        texts[i*3+2].first.setString(std::to_string(game->getPlayer(i)->getPoints()));
        texts[i*3+2].second.setString(std::to_string(game->getPlayer(i)->getPoints()));
    }
}

void Ui::changeState(state s) {
    currentState = s;
}

void Ui::setKeyPressed(sf::Keyboard::Key k) {
    if ((k == sf::Keyboard::Up or k == sf::Keyboard::W) and currentState != credits) {
        int aux = select;
        if (aux-1<0) aux = texts.size();
        changeSelected((aux-1)%texts.size());
    }
    else if ((k == sf::Keyboard::Down or k == sf::Keyboard::S) and currentState != credits) changeSelected((select+1)%texts.size());
    else if (k == sf::Keyboard::Return) {
        if (currentState == menu) {
            switch (select) {
            case 0:
                nPlayers = 2;
                game->init(2);
                break;
            case 1:
                nPlayers = 3;
                game->init(3);
                break;
            case 2:
                nPlayers = 4;
                game->init(4);
                break;
            case 3:
                changeState(help);
                break;
            case 4:
                changeState(credits);
                break;
            case 5:
                game->getWindow()->close();
                break;
            default:
                break;
            }
        } else if (currentState == help) changeState(menu);
        else if (currentState == credits) changeState(menu);
    }
}

int Ui::getNPlayers() {
    return nPlayers;
}

void Ui::setText() {
    for (unsigned i = 0; i < texts.size(); ++i) {
        texts[i].first = sf::Text();
        texts[i].second = sf::Text();
    }
    if (currentState == menu) {
        title.setString("LD48");
        texts[0].first.setString("2 Players");
        texts[1].first.setString("3 Players");
        texts[2].first.setString("4 Players");
        texts[3].first.setString("Help"     );
        texts[4].first.setString("Credits"  );
        texts[5].first.setString("Exit"     );

        texts[0].second.setString("2 Players");
        texts[1].second.setString("3 Players");
        texts[2].second.setString("4 Players");
        texts[3].second.setString("Help"     );
        texts[4].second.setString("Credits"  );
        texts[5].second.setString("Exit"     );
    } else if (currentState == help) {
        title.setString("Help");
        texts[0].first.setString("Menu");
        texts[0].second.setString("Menu");
    } else if (currentState == playing) {
        for (unsigned i = 0; i < texts.size(); ++i) {
            std::string aux;
            switch (i%3) {
            case 0: aux = "Player  " + std::to_string((i/3)+1); break;
            case 1: aux = "Points";                             break;
            case 2: aux = "0";                                  break;
            }
            texts[i].first.setString(aux);
            texts[i].second.setString(aux);
        }
    } else if (currentState == credits) {
        title.setString("Credits");
        texts[0].first.setString("Dirbaio Minikiwi" );
        texts[1].first.setString("kaitokidi"        );
        texts[2].first.setString("Marce Coll"       );
        texts[3].first.setString("Pinkii"          );
        texts[4].first.setString("Nikita Kieffer"   );
        texts[5].first.setString("Menu"             );

        texts[0].second.setString("Dirbaio Minikiwi" );
        texts[1].second.setString("kaitokidi"        );
        texts[2].second.setString("Marce Coll"       );
        texts[3].second.setString("Pinkii"          );
        texts[4].second.setString("Nikita Kieffer"   );
        texts[5].second.setString("Menu"             );
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
        sf::Color firstColor = sf::Color(0,0,0,100);
        sf::Color secondColor = sf::Color(255,255,255,255);
        if (currentState == playing) {
            if (i%3 != 0) msf = 50;
            else msf = 70;
            firstColor = sf::Color(0,0,0,200);
        } else if (currentState == credits) msf = 50;
        texts[i].first.setCharacterSize(msf);
        texts[i].second.setCharacterSize(msf);
        texts[i].first.setFont(Resources::menuFont);
        texts[i].second.setFont(Resources::menuFont);
        texts[i].second.setStyle(sf::Text::Bold);
        texts[i].first.setColor(firstColor);
        texts[i].second.setColor(secondColor);
        textRect = texts[i].first.getLocalBounds();
        texts[i].first.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
        textRect = texts[i].second.getLocalBounds();
        texts[i].second.setOrigin(textRect.left + textRect.width/2.0f, textRect.top  + textRect.height/2.0f);
    }
    if (currentState == menu) {
        title.setPosition(sf::Vector2f(windowSize.x/2.0f,windowSize.y/((texts.size()*1.5))));
        for (unsigned i = 0; i < texts.size(); ++i) {
            texts[i].first.setPosition(sf::Vector2f(windowSize.x/2.0f,windowSize.y/(texts.size()+2)*(i+2)));
            texts[i].second.setPosition(sf::Vector2f(windowSize.x/2.0f,windowSize.y/(texts.size()+2)*(i+2)));
            texts[i].second.setScale(1,1.15);
        }
    }
    else if (currentState == help) {
        title.setPosition(sf::Vector2f(windowSize.x/2.0f,windowSize.y/((6*1.5))));
        texts[0].first.setPosition(sf::Vector2f(windowSize.x/2.0f,windowSize.y/(6+2)*(5+2)));
        texts[0].second.setPosition(sf::Vector2f(windowSize.x/2.0f,windowSize.y/(6+2)*(5+2)));
    } else if (currentState == playing) {
        sf::Vector2f position;
        for (int i = 0; i < nPlayers; ++i) {
            int bWidth = game->getBoard()->getWidth();
            if (i == 0) position = sf::Vector2f((windowSize.x-bWidth)/4.f,(windowSize.y-bWidth+(bWidth/8)));
            else if (i == 1) position = sf::Vector2f((windowSize.x-bWidth)/2+bWidth+texts[i*3].first.getLocalBounds().width,(windowSize.y-bWidth+(bWidth/8)));
            else if (i == 2) position = sf::Vector2f((windowSize.x-bWidth)/4.f,(windowSize.y-bWidth+(bWidth*6/8)));
            else if (i == 3) position = sf::Vector2f((windowSize.x-bWidth)/2+bWidth+texts[i*3].first.getLocalBounds().width,(windowSize.y-bWidth+(bWidth*6/8)));
            texts[i*3].first.setPosition(sf::Vector2f(position.x,position.y));
            texts[i*3].second.setPosition(sf::Vector2f(position.x,position.y));
            texts[i*3+1].first.setPosition(sf::Vector2f(position.x-50,position.y+50));
            texts[i*3+1].second.setPosition(sf::Vector2f(position.x-50,position.y+50));
            texts[i*3+2].first.setPosition(sf::Vector2f(position.x+60,position.y+50));
            texts[i*3+2].second.setPosition(sf::Vector2f(position.x+60,position.y+50));
        }
    }
    else if (currentState == credits) {
        title.setPosition(sf::Vector2f(windowSize.x/2.0f,windowSize.y/((6*1.5))));
        texts[0].first.setScale(1.035,1);
        texts[0].first.setColor(sf::Color(153,255,153,200));
        texts[0].first.setPosition(sf::Vector2f(windowSize.x/4,windowSize.y*2.5/((6*1.5))));
        texts[0].second.setPosition(sf::Vector2f(windowSize.x/4,windowSize.y*2.5/((6*1.5))));
        texts[1].first.setScale(1.03,1);
        texts[1].first.setColor(sf::Color(255,255,153,200));
        texts[1].first.setPosition(sf::Vector2f(windowSize.x/2.2,windowSize.y*2.2/((6*1.5))));
        texts[1].second.setPosition(sf::Vector2f(windowSize.x/2.2,windowSize.y*2.2/((6*1.5))));
        texts[2].first.setScale(1.03,1);
        texts[2].first.setColor(sf::Color(255,153,153,200));
        texts[2].first.setPosition(sf::Vector2f(windowSize.x/1.55,windowSize.y*2.1/((6*1.5))));
        texts[2].second.setPosition(sf::Vector2f(windowSize.x/1.55,windowSize.y*2.1/((6*1.5))));
        texts[3].first.setColor(sf::Color(255,153,255,200));
        texts[3].first.setPosition(sf::Vector2f(windowSize.x/1.25,windowSize.y*1.6/((6*1.5))));
        texts[3].second.setPosition(sf::Vector2f(windowSize.x/1.25,windowSize.y*1.6/((6*1.5))));
        texts[4].first.setScale(1.03,1);
        texts[4].first.setColor(sf::Color(153,255,255,200));
        texts[4].first.setPosition(sf::Vector2f(windowSize.x/1.07,windowSize.y/(12)));
        texts[4].second.setPosition(sf::Vector2f(windowSize.x/1.07,windowSize.y/(12)));
        texts[5].first.setPosition(sf::Vector2f(windowSize.x/2.0f,windowSize.y/(6+2)*(5+2)));
        texts[5].second.setPosition(sf::Vector2f(windowSize.x/2.0f,windowSize.y/(6+2)*(5+2)));
    }
}

void Ui::changeSelected(int newSelected) {
    if (texts.size() > select and currentState != credits)texts[select].first.setColor(sf::Color(0,0,0,100));
    select = newSelected;
    texts[select].first.setColor(sf::Color(0,0,0,200));
}
