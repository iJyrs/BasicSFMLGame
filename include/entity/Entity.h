#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

#include "../Component.h"
#include "animation/Animated.h"
#include "../world/World.h"

class Entity : public Component, public Animated {

public:
	Entity();

private:
	std::shared_ptr<World> m_world;
	sf::Vector3f m_position;

public:
	int16_t m_direction; // int16_t isn't required (Since int type is at least 16 bits)
	float m_velocity; // same here ^
	float m_friciton = 0.01f;;

public:
	void update(int32_t deltaTime) override;

public:
	std::shared_ptr<World> getWorld();
	void setWorld(const std::shared_ptr<World>& world);
	sf::Vector3f getPosition();
	void setPosition(const sf::Vector3f& position);

};

#endif