#include "../../include/entity/EntityHuman.h"
#include <SFML/Graphics/RectangleShape.hpp>

EntityHuman::EntityHuman() {

}

void EntityHuman::render(sf::RenderTarget& target) {
	sf::RectangleShape shape(sf::Vector2f(10, 10));
	sf::Vector3f pos = getPosition();

	shape.setPosition(sf::Vector2f(pos.x, pos.y));

	target.draw(shape);
}