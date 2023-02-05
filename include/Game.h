#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "world/World.h"
#include "player/Player.h"

class Game {

public:
	Game() {
		m_window.create(sf::VideoMode(1000, 600), "Farmer Game");
		m_window.setFramerateLimit(75);

		m_world = std::shared_ptr<World>(new World("world"));
		m_player = std::shared_ptr<Player>(new Player({ 10, 10 }));

		m_world->addEntity(m_player);
		m_world->spawnEntity(CAT, { 300, 300 });
	}

public:
	void run() {
		sf::Clock clock;

		sf::View worldView({ 0, 0, 1000, 600 });
		sf::View guiView = m_window.getDefaultView();

		while (m_window.isOpen()) {
			sf::Event event;

			while (m_window.pollEvent(event)) {
				switch (event.type) {
				case sf::Event::Closed:

					m_window.close();

					break;
				case sf::Event::Resized:

					// Resize the view to match the window size.
					worldView.setSize({ (float) event.size.width, (float) event.size.height });

					guiView.setSize(worldView.getSize());
					guiView.setCenter(worldView.getSize() / 2.F);

					break;
				case sf::Event::KeyPressed:
				case sf::Event::KeyReleased:
				case sf::Event::MouseButtonPressed:

					m_player->onEvent(event);

					break;
				}
			}

			m_window.clear(sf::Color::Red);

			const int32_t& deltaTime = clock.restart().asMilliseconds();

			m_world->update(deltaTime);

			// Update and set the World view.
			worldView.setCenter(m_player->getPosition() + sf::Vector2f(100, 100));
			m_window.setView(worldView);

			m_world->render(m_window);

			// Set the GUI view.
			m_window.setView(guiView);

			// Render GUI stuff...

			// Reset the view.
			m_window.setView(m_window.getDefaultView());

			m_window.display();
		}
	}

private:
	sf::RenderWindow m_window;
	std::shared_ptr<World> m_world;
	std::shared_ptr<Player> m_player;

};

#endif