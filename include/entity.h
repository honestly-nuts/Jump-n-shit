#pragma once 

#include <SFML/Graphics.hpp>
#include <math.h>
#include "entity.h"

class Entity {
    public:
        Entity(float x, float y, char* texturePath);
        ~Entity();
    public:
        sf::Sprite sprite;
        sf::Texture texture;
    private:
};
