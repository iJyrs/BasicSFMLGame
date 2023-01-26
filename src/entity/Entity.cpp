#include "../../include/entity/Entity.h"

Entity::Entity() {
	
}

void Entity::update(float deltaTime) {
	sf::Vector3f position = getPosition();
	deltaTime *= 100;

	float radians = m_direction * (std::acos(-1) / 180);
	float x = m_velocity * cos(radians) * (deltaTime);
	float y = m_velocity * sin(radians) * (deltaTime);;
	position.x += -y; position.y += x;

	setPosition(position);

	float deltaV = m_friciton * deltaTime;
	m_velocity -= deltaV;
	if (m_velocity < 0) m_velocity = 0;
}

sf::Vector3f Entity::getPosition() {
	return m_position;
}

void Entity::setPosition(const sf::Vector3f& position) {
	m_position = position;
}

std::shared_ptr<World> Entity::getWorld() {
	return std::shared_ptr<World>();
}

void Entity::setWorld(const std::shared_ptr<World>& world) {
	m_world = world;
}
