#include "Object.hpp"
#include "LD48.hpp"

Object::Object(LD48 *game, sf::Vector2f size, sf::Texture &tex,  sf::Vector2i spriteCount)
    : game(game), size(size), tex(tex), spriteCount(spriteCount), receivesCollisions(false), dead(false)
{
    sprite.setTexture(tex);
}

void Object::draw() {
    sprite.setScale(size.x/tex.getSize().x*spriteCount.x, size.y/tex.getSize().y*spriteCount.y);
    sprite.setTextureRect(sf::IntRect(
                              spriteNum.x*tex.getSize().x/spriteCount.x,
                              spriteNum.y*tex.getSize().y/spriteCount.y,
                              tex.getSize().x/spriteCount.x,
                              tex.getSize().y/spriteCount.y
                              ));
    sprite.setPosition(position);
    game->getWindow()->draw(sprite);
}

bool Object::collidesWith(Object *b) {
    if(position.x + size.x < b->position.x) return false;
    if(position.y + size.y < b->position.y) return false;
    if(b->position.x + b->size.x < position.x) return false;
    if(b->position.y + b->size.y < position.y) return false;

    return true;
}

void Object::update(float deltaTime) {
    (void)deltaTime;
}

void Object::collidedWith(Object *b) {
    (void)b;
}
