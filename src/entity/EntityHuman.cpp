#include "../../include/entity/EntityHuman.h"

#include <array>
#include <SFML/Graphics.hpp> 

EntityHuman::EntityHuman() {
	m_texture.loadFromFile("assets/player.png");

	m_sprite.setTexture(m_texture);
	m_sprite.setTextureRect(sf::IntRect(0, 0, 48, 48));

	m_sprite.setScale({5, 5});

	std::vector<Frame> frames;
	frames.emplace_back(sf::IntRect(0, 336, 48, 48), 500);
	frames.emplace_back(sf::IntRect(48, 336, 48, 48), 500);
	frames.emplace_back(sf::IntRect(96, 336, 48, 48), 500);
	frames.emplace_back(sf::IntRect(144, 336, 48, 48), 500);

	Animation animation("idle", frames);
	registerAnimation(animation);
}

void EntityHuman::update(int32_t deltaTime) {
	Entity::update(deltaTime);

	const Frame* frame = nextFrame(deltaTime);
	if (frame != nullptr)
		m_sprite.setTextureRect(frame->bounds);
}

void EntityHuman::render(sf::RenderTarget& target) {
	sf::Vector3f pos = getPosition();
	m_sprite.setPosition(pos.x, pos.y);

	target.draw(m_sprite);
}