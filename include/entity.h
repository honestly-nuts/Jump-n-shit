#pragma once 

#include <SFML/Graphics.hpp>
#include <math.h>
#include "entity.h"

class Entity {
    public:
        Entity(float x, float y, char* texturePath);
        ~Entity();
        
        void set_collsion_size(sf::Vector2f size);
        void update_rect_pos(sf::Vector2f loc);
    public:
        sf::Sprite sprite;
        sf::Texture texture;
        sf::RectangleShape collision_rect;
    private:
};
