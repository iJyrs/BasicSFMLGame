#include <iostream>
#include <SFML/Graphics.hpp>

#include "include/Game.h"

int main() {
	Game game;

	sf::RenderWindow& window = game.getWindow();
	window.setFramerateLimit(75);

	sf::Clock clock;

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:

				window.close();
				
				break;
			case sf::Event::KeyPressed:

				game.getPlayer().handleInput();

				break;
			}
		}

		window.clear();


		game.update(clock.restart().asSeconds());
		game.render();

		window.display();
	}

	return 0;
}