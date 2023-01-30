#include "../../include/player/Player.h"
#include <SFML/Graphics.hpp>

Player::Player() {

}

void Player::handleInput() {
    const int16_t MAX_VELOCITY = 1;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        m_direction = 180;
        m_velocity = MAX_VELOCITY;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        m_direction = 0;
        m_velocity = MAX_VELOCITY;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        m_direction = 90;
        m_velocity = MAX_VELOCITY;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        m_direction = 270;
        m_velocity = MAX_VELOCITY;
    }
}
