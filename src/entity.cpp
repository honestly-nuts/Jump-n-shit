// #include <SFML/Graphics>
#include "../include/entity.h"

Entity::Entity(float x, float y, char* texturePath){
    this->sprite.setPosition(x, y);
    this->texture.loadFromFile(texturePath);
    this->sprite.setTexture(this->texture);
    this->collision_rect.setSize((sf::Vector2f) this->texture.getSize());
}

Entity::~Entity(){

}

void Entity::set_collsion_size(sf::Vector2f size)
{
    this->collision_rect.setSize((sf::Vector2f) size);
}
void Entity::update_rect_pos(sf::Vector2f loc)
{
    this->collision_rect.setPosition(loc);
}
