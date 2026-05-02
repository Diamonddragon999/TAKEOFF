#include <iostream>

#include <SFML/Graphics.hpp>
#include <filesystem>

#include "env_fixes.h"
#include "game.h"

int main() {
    init_threads();

    Game game;
    game.ruleaza();

    sf::RenderWindow window;
    window.create(sf::VideoMode({800, 700}), "My Window", sf::Style::Default);
    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) {
        sf::Event e{};
        while (window.pollEvent(e)) {
            if (e.type == sf::Event::Closed) window.close();
            if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape) window.close();
        }
        window.clear(sf::Color::White);
        window.display();
    }
    return 0;
}
