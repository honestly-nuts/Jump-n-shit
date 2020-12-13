#include "../include/entity.h"
#include "../include/animation.h"

#include <SFML/Graphics.hpp>

#define TILE_SIZE 0.2f

int main(){
    // init
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game", sf::Style::Close | sf::Style::Titlebar);

    // player stuff
    Entity player(206.0f, 206.0f, (char*) "images/boot-sheet.png");
    Animation animation(&player.texture, sf::Vector2u(4, 2), TILE_SIZE);

    // f at art
    // Entity bg(0.0f, 0.0f, (char*) "images/tmp_bg.jpg");

    // enemy
    Entity enemy(220.0f, 220.0f, "images/boot-sheet.png");

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

        animation.Update(0, deltaTime, false);
        player.sprite.setTextureRect(animation.uvRect);
        window.clear(sf::Color::White);
        // window.draw(bg.sprite);
        window.draw(player.sprite);
        // if (player.check_collision(enemy, 50))
        window.draw(enemy.sprite);
        window.display();
    }
    return 0;
}
