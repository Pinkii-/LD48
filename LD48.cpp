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
	ui.changeState(selectMaxPoints);
	gameState = selectMaxPoints;
	nPlayers = nPlayer;
	spawnTimer = rand()%2 + 3;

	objects = std::list<Object*>();
	for (int i = 0; i < nPlayers; ++i) {
		Player* p = new Player(i, this);
		p->position = sf::Vector2f ((window.getSize().x/2)-10*(nPlayers-1)+20*i, 230);
		addObject(p);
	}

	isKeyPressed = std::vector<std::vector<dir> >(nPlayers,std::vector<dir>(2));
	for(int i = 0; i < nPlayers; i++) {
		isKeyPressed[i][0] = none;
		isKeyPressed[i][1] = none;
	}

	float boardWidth = 800;
	board = Board(this, boardWidth, nPlayers);

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
		for (int i = 0; i < nPlayers; ++i) {
			if (getPlayer(i)->getPoints() >= maxPoints) {
				ui.win(i);
				gameState = winned;
				break;
			}
		}
	}
	ui.update();
}

void LD48::spawnCollectible(collectible type)
{
	int x = rand()%(800-15) + board.horOffset;
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
	if (gameState != playing and gameState != winned and gameState != selectMaxPoints) ui.draw();
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
		case sf::Keyboard::Escape:
			ui.changeState(menu);
			break;
		case sf::Keyboard::A:
			if (isKeyPressed[0][1] != left) {
				if (isKeyPressed[0][1] != none) isKeyPressed[0][0] = isKeyPressed[0][1];
				isKeyPressed[0][1] = left;
			}
			break;
		case sf::Keyboard::W:
			if (isKeyPressed[0][1] != up) {
				if (isKeyPressed[0][1] != none) isKeyPressed[0][0] = isKeyPressed[0][1];
				isKeyPressed[0][1] = up;
			}
			break;
		case sf::Keyboard::S:
			if (isKeyPressed[0][1] != down) {
				if (isKeyPressed[0][1] != none) isKeyPressed[0][0] = isKeyPressed[0][1];
				isKeyPressed[0][1] = down;
			}
			break;
		case sf::Keyboard::D:
			if (isKeyPressed[0][1] != right) {
				if (isKeyPressed[0][1] != none) isKeyPressed[0][0] = isKeyPressed[0][1];
				isKeyPressed[0][1] = right;
			}
			break;
		case sf::Keyboard::Left:
			if (isKeyPressed[1][1] != left) {
				if (isKeyPressed[1][1] != none) isKeyPressed[1][0] = isKeyPressed[1][1];
				isKeyPressed[1][1] = left;
			}
			break;
		case sf::Keyboard::Up:
			if (isKeyPressed[1][1] != up) {
				if (isKeyPressed[1][1] != none) isKeyPressed[1][0] = isKeyPressed[1][1];
				isKeyPressed[1][1] = up;
			}
			break;
		case sf::Keyboard::Down:
			if (isKeyPressed[1][1] != down) {
				if (isKeyPressed[1][1] != none) isKeyPressed[1][0] = isKeyPressed[1][1];
				isKeyPressed[1][1] = down;
			}
			break;
		case sf::Keyboard::Right:
			if (isKeyPressed[1][1] != right) {
				if (isKeyPressed[1][1] != none) isKeyPressed[1][0] = isKeyPressed[1][1];
				isKeyPressed[1][1] = right;
			}
			break;
		default:
			//        if (nPlayers > 2) {
			//            switch (event.key.code) {
			//            case sf::Keyboard::J:
			//                isKeyPressed[2] = left;
			//                break;
			//            case sf::Keyboard::I:
			//                isKeyPressed[2] = up;
			//                break;
			//            case sf::Keyboard::K:
			//                isKeyPressed[2] = down;
			//                break;
			//            case sf::Keyboard::L:
			//                isKeyPressed[2] = right;
			//                break;
			//            default:
			//                if (nPlayers > 3) {
			//                    switch (event.key.code) {
			//                    case sf::Keyboard::Numpad1:
			//                        isKeyPressed[3] = left;
			//                        break;
			//                    case sf::Keyboard::Numpad5:
			//                        isKeyPressed[3] = up;
			//                        break;
			//                    case sf::Keyboard::Numpad2:
			//                        isKeyPressed[3] isKeyPressed[1][1] = right;= down;
			//                        break;
			//                    case sf::Keyboard::Numpad3:
			//                        isKeyPressed[3] = right;
			//                        break;
			//                    default:
			//                        break;
			//                    }
			//                }
			//                break;
			//            }
			//        }
			break;
	}
}

void LD48::keyReleased(sf::Event event) {
	switch (event.key.code) {
		case sf::Keyboard::A:
			if(isKeyPressed[0][1] == left) isKeyPressed[0][1] = none;
			else if(isKeyPressed[0][0] == left) isKeyPressed[0][0] = none;
			break;
		case sf::Keyboard::W:
			if(isKeyPressed[0][1] == up) isKeyPressed[0][1] = none;
			else if(isKeyPressed[0][0] == up) isKeyPressed[0][0] = none;
			break;
		case sf::Keyboard::S:
			if(isKeyPressed[0][1] == down) isKeyPressed[0][1] = none;
			else if(isKeyPressed[0][0] == down) isKeyPressed[0][0] = none;
			break;
		case sf::Keyboard::D:
			if(isKeyPressed[0][1] == right) isKeyPressed[0][1] = none;
			else if(isKeyPressed[0][0] == right) isKeyPressed[0][0] = none;
			break;
		case sf::Keyboard::Left:
			if(isKeyPressed[1][1] == left) isKeyPressed[1][1] = none;
			else if(isKeyPressed[1][0] == left) isKeyPressed[1][0] = none;
			break;
		case sf::Keyboard::Up:
			if(isKeyPressed[1][1] == up) isKeyPressed[1][1] = none;
			else if(isKeyPressed[1][0] == up) isKeyPressed[1][0] = none;
			break;
		case sf::Keyboard::Down:
			if(isKeyPressed[1][1] == down) isKeyPressed[1][1] = none;
			else if(isKeyPressed[1][0] == down) isKeyPressed[1][0] = none;
			break;
		case sf::Keyboard::Right:
			if(isKeyPressed[1][1] == right) isKeyPressed[1][1] = none;
			else if(isKeyPressed[1][0] == right) isKeyPressed[1][0] = none;
			break;
		default:
			//        if (nPlayers > 2) {
			//            switch (event.key.code) {
			//            case sf::Keyboard::J:
			//                if(isKeyPressed[2] == left) isKeyPressed[2] = none;
			//                break;
			//            case sf::Keyboard::I:
			//                if(isKeyPressed[2] == up) isKeyPressed[2] = none;
			//                break;
			//            case sf::Keyboard::K:
			//                if(isKeyPressed[2] == down) isKeyPressed[2] = none;
			//                break;
			//            case sf::Keyboard::L:
			//                if(isKeyPressed[2] == right) isKeyPressed[2] = none;
			//                break;
			//            default:
			//                if (nPlayers > 2) {
			//                    switch (event.key.code) {
			//                    case sf::Keyboard::NisKeyPressed[1][1] = right;umpad1:
			//                        if(isKeyPressed[3] == left) isKeyPressed[3] = none;
			//                        break;
			//                    case sf::Keyboard::Numpad5:
			//                        if(isKeyPressed[3] == up) isKeyPressed[3] = none;
			//                        break;
			//                    case sf::Keyboard::Numpad2:
			//                        if(isKeyPressed[3] == down) isKeyPressed[3] = none;
			//                        break;
			//                    case sf::Keyboard::Numpad3:
			//                        if(isKeyPressed[3] == right) isKeyPressed[3] = none;
			//                        break;
			//                    default:
			//                        break;
			//                    }
			//                }
			//                break;
			//            }
			//        }
			break;
	}
}

void LD48::setState(state s) {
	gameState = s;
}

dir LD48::getDirection(int i) {
	return isKeyPressed[i][1] != none ? isKeyPressed[i][1] : isKeyPressed[i][0];
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


void LD48::setMaxPoints(int p) {
	maxPoints = p;
	gameState = playing;
	ui.changeState(playing);
}

