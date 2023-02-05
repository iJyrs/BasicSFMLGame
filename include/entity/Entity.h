#ifndef ENTITY_H
#define ENTITY_H

#include "../Component.h"
#include "animation/Animated.h"
#include "FaceDirection.h"

#include <SFML/Graphics.hpp>

class Entity : public Component, public Animated {

public:
	Entity(const sf::Vector2f& position) :
		m_entityId(entityId_it),
		m_position(position),
		m_direction(WEST)
	{
		entityId_it++;
	}

	void update(const int32_t& deltaTime) override {
		if (m_velocity <= 0) return;

		int direction = (int)m_direction;

		float radians = direction * (((float) std::acos(-1)) / 180);
		float x = m_velocity * cos(radians) * (deltaTime);
		float y = m_velocity * sin(radians) * (deltaTime);;
		m_position.x += y; m_position.y += -x;

		float deltaV = m_friction * deltaTime;
		m_velocity -= deltaV;
		if (m_velocity <= 0) {
			m_velocity = 0;
			playAnimation("idle");
		}
	}

	uint16_t getEntityId() {
		return m_entityId;
	}

	sf::Vector2f getPosition() {
		return m_position;
	}

	void setVelocity(const float& velocity) {
		m_velocity = velocity;

		if (velocity > 0) {
			playAnimation("walking");
		}
	}

	bool& isMoving() {
		return m_isMoving;
	}

private:
	static uint16_t entityId_it;
	bool m_isMoving = false;

protected:
	const uint16_t m_entityId;
	sf::Vector2f m_position;

	FaceDirection m_direction; // 0-360
	float m_velocity = 0;
	float m_friction = 0;

};

enum EntityType {

	HUMAN, CAT

};

#endif