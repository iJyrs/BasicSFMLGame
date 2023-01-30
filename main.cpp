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
		sf::FloatRect visibleArea;

		while (window.pollEvent(event)) {
			switch (event.type) {
			case sf::Event::Closed:

				window.close();
				
				break;
			case sf::Event::Resized:

				visibleArea = sf::FloatRect(0, 0, (float) event.size.width, (float) event.size.height);
				window.setView(sf::View(visibleArea));

				break;
			case sf::Event::KeyPressed:

				game.getPlayer().handleInput();

				break;
			}
		}

		window.clear(sf::Color::Red);

		game.update(clock.restart().asMilliseconds());
		game.render();

		window.display();
	}

	return 0;
}