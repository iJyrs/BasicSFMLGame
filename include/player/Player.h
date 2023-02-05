#ifndef PLAYER_H
#define PLAYER_H

#include "../../include/entity/EntityHuman.h"

class Player : public EntityHuman {

public:
	Player(const sf::Vector2f& position) : EntityHuman(position) {

	}

	void onEvent(const sf::Event& event) {
		FaceDirection direction = UNKNOWN;

		if (event.type == sf::Event::KeyPressed) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
				direction = WEST;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				direction = EAST;
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
				direction = NORTH;

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					direction = NORTH_WEST;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					direction = NORTH_EAST;
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				direction = SOUTH;

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
					direction = SOUTH_WEST;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
					direction = SOUTH_EAST;
				}
			}

			if (direction != UNKNOWN) {
				m_direction = direction;
				setVelocity(0.25F);
				m_friction = 0;
			}
		}

		if (event.type == sf::Event::KeyReleased) {
			if (
				!sf::Keyboard::isKeyPressed(sf::Keyboard::W) &&
				!sf::Keyboard::isKeyPressed(sf::Keyboard::A) &&
				!sf::Keyboard::isKeyPressed(sf::Keyboard::S) &&
				!sf::Keyboard::isKeyPressed(sf::Keyboard::D)
			)
			{
				m_friction = 0.1f;
			}

		}

		if (event.type == sf::Event::MouseButtonPressed) {
			playAnimation("attack");
		}
	}

};

#endif