#include "../include/entity.h"
#include "../include/animation.h"

#include <SFML/Graphics.hpp>

#define TILE_SIZE 1.0f

int main(){
    // init
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game", sf::Style::Close | sf::Style::Titlebar);

    // player stuff
    Entity player(206.0f, 206.0f, (char*) "images/boot-sheet.png");
    Animation player_animation(&player.texture, sf::Vector2u(4, 2), TILE_SIZE);

    // f at art
    // Entity bg(0.0f, 0.0f, (char*) "images/tmp_bg.jpg");

    // enemy
    Entity enemy(220.0f, 220.0f, "images/boot-sheet.png");
    Animation enemy_animation(&enemy.texture, sf::Vector2u(4, 2), TILE_SIZE);

    float deltaTime = 0.0f;

    sf::Clock clock;
    
    while(window.isOpen()){

        deltaTime = clock.restart().asSeconds();
        sf::Event evnt;

        while(window.pollEvent(evnt)){
            switch(evnt.type){
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
            player.sprite.move(-TILE_SIZE, 0.0f);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
            player.sprite.move(TILE_SIZE, 0.0f);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
            player.sprite.move(0.0f, -TILE_SIZE);
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
            player.sprite.move(0.0f, TILE_SIZE);

        // update

        player.collision_rect.setFillColor(sf::Color(255, 30, 100, 255)); // tmp
        enemy.collision_rect.setFillColor(sf::Color(255, 30, 100, 255)); // tmp

        player.set_collsion_size(sf::Vector2f(player.texture.getSize().x / float(player_animation.get_imageCount().x), player.texture.getSize().y / float(player_animation.get_imageCount().y)));
        player.update_rect_pos(player.sprite.getPosition());

        enemy.set_collsion_size(sf::Vector2f(enemy.texture.getSize().x / (float) enemy_animation.get_imageCount().x, enemy.texture.getSize().y / (float) enemy_animation.get_imageCount().y));
        enemy.update_rect_pos(enemy.sprite.getPosition());

        player_animation.Update(0, deltaTime, false);
        enemy_animation.Update(0, deltaTime, false);

        player.sprite.setTextureRect(player_animation.uvRect);
        enemy.sprite.setTextureRect(enemy_animation.uvRect);

        // draw
        window.clear(sf::Color::White);
        // window.draw(bg.sprite);
        window.draw(player.collision_rect);
        window.draw(player.collision_rect);
        window.draw(enemy.collision_rect);

        window.draw(player.sprite);
        window.draw(enemy.sprite);


        window.display();

    }
    return 0;
}
