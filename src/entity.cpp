// #include <SFML/Graphics>
#include "../include/entity.h"

Entity::Entity(float x, float y, char* texturePath){
    this->sprite.setPosition(x, y);
    this->texture.loadFromFile(texturePath);
    this->sprite.setTexture(this->texture);
}

Entity::~Entity(){

}
