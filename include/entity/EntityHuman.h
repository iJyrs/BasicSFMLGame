#ifndef ENTITYHUMAN_H
#define ENTITYHUMAN_H

#include "Entity.h"

class EntityHuman : public Entity {

public:
	EntityHuman(const sf::Vector2f& position) : Entity(position) {
		skinTexture.loadFromFile("assets/player.png");

		m_sprite.setTexture(skinTexture);
		m_sprite.setTextureRect({ 0, 0, 48, 48 });
		m_sprite.setScale({ 3, 3 });

		std::vector<Frame> frames;
		Animation idleAnim("idle", true);

		frames.emplace_back(sf::IntRect(0, 0, 48, 48), 300);
		frames.emplace_back(sf::IntRect(48, 0, 48, 48), 300);
		frames.emplace_back(sf::IntRect(96, 0, 48, 48), 300);
		frames.emplace_back(sf::IntRect(144, 0, 48, 48), 300);
		frames.emplace_back(sf::IntRect(240, 0, 48, 48), 300);

		idleAnim.addFrames(SOUTH, frames);
		frames.clear();

		frames.emplace_back(sf::IntRect(0, 96, 48, 48), 300);
		frames.emplace_back(sf::IntRect(48, 96, 48, 48), 300);
		frames.emplace_back(sf::IntRect(96, 96, 48, 48), 300);
		frames.emplace_back(sf::IntRect(144, 96, 48, 48), 300);
		frames.emplace_back(sf::IntRect(240, 96, 48, 48), 300);

		idleAnim.addFrames(NORTH, frames);
		frames.clear();

		frames.emplace_back(sf::IntRect(48, 48, -48, 48), 300);
		frames.emplace_back(sf::IntRect(48, 48, -48, 48), 300);
		frames.emplace_back(sf::IntRect(144, 48, -48, 48), 300);
		frames.emplace_back(sf::IntRect(240, 48, -48, 48), 300);
		frames.emplace_back(sf::IntRect(288, 48, -48, 48), 300);

		idleAnim.addFrames(WEST, frames);
		frames.clear();

		frames.emplace_back(sf::IntRect(0, 48, 48, 48), 300);
		frames.emplace_back(sf::IntRect(48, 48, 48, 48), 300);
		frames.emplace_back(sf::IntRect(96, 48, 48, 48), 300);
		frames.emplace_back(sf::IntRect(144, 48, 48, 48), 300);
		frames.emplace_back(sf::IntRect(240, 48, 48, 48), 300);

		idleAnim.addFrames(EAST, frames);
		frames.clear();

		registerAnimation(idleAnim); // Register the "idle" animation

		Animation walkAnim("walking", true);

		frames.emplace_back(sf::IntRect(0, 144, 48, 48), 300);
		frames.emplace_back(sf::IntRect(48, 144, 48, 48), 300);
		frames.emplace_back(sf::IntRect(96, 144, 48, 48), 300);
		frames.emplace_back(sf::IntRect(144, 144, 48, 48), 300);
		frames.emplace_back(sf::IntRect(192, 144, 48, 48), 300);

		walkAnim.addFrames(SOUTH, frames);
		frames.clear();

		frames.emplace_back(sf::IntRect(0, 240, 48, 48), 300);
		frames.emplace_back(sf::IntRect(48, 240, 48, 48), 300);
		frames.emplace_back(sf::IntRect(96, 240, 48, 48), 300);
		frames.emplace_back(sf::IntRect(144, 240, 48, 48), 300);
		frames.emplace_back(sf::IntRect(192, 240, 48, 48), 300);

		walkAnim.addFrames(NORTH, frames);
		frames.clear();

		frames.emplace_back(sf::IntRect(48, 192, -48, 48), 300);
		frames.emplace_back(sf::IntRect(96, 192, -48, 48), 300);
		frames.emplace_back(sf::IntRect(144, 192, -48, 48), 300);
		frames.emplace_back(sf::IntRect(192, 192, -48, 48), 300);
		frames.emplace_back(sf::IntRect(240, 192, -48, 48), 300);

		walkAnim.addFrames(WEST, frames);
		frames.clear();

		frames.emplace_back(sf::IntRect(0, 192, 48, 48), 300);
		frames.emplace_back(sf::IntRect(48, 192, 48, 48), 300);
		frames.emplace_back(sf::IntRect(96, 192, 48, 48), 300);
		frames.emplace_back(sf::IntRect(144, 192, 48, 48), 300);
		frames.emplace_back(sf::IntRect(192, 192, 48, 48), 300);

		walkAnim.addFrames(EAST, frames);
		frames.clear();

		registerAnimation(walkAnim); // Register the "walking" animation

		Animation attackAnim("attack", false);

		frames.emplace_back(sf::IntRect(0, 288, 48, 48), 300);
		frames.emplace_back(sf::IntRect(48, 288, 48, 48), 300);
		frames.emplace_back(sf::IntRect(96, 288, 48, 48), 300);
		frames.emplace_back(sf::IntRect(144, 288, 48, 48), 300);

		attackAnim.addFrames(SOUTH, frames);
		frames.clear();

		frames.emplace_back(sf::IntRect(0, 384, 48, 48), 300);
		frames.emplace_back(sf::IntRect(48, 384, 48, 48), 300);
		frames.emplace_back(sf::IntRect(96, 384, 48, 48), 300);
		frames.emplace_back(sf::IntRect(144, 384, 48, 48), 300);

		attackAnim.addFrames(NORTH, frames);
		frames.clear();

		frames.emplace_back(sf::IntRect(0, 336, 48, 48), 300);
		frames.emplace_back(sf::IntRect(48, 336, 48, 48), 300);
		frames.emplace_back(sf::IntRect(96, 336, 48, 48), 300);
		frames.emplace_back(sf::IntRect(144, 336, 48, 48), 300);

		attackAnim.addFrames(EAST, frames);
		frames.clear();

		frames.emplace_back(sf::IntRect(48, 336, -48, 48), 300);
		frames.emplace_back(sf::IntRect(96, 336, -48, 48), 300);
		frames.emplace_back(sf::IntRect(144, 336, -48, 48), 300);
		frames.emplace_back(sf::IntRect(192, 336, -48, 48), 300);

		attackAnim.addFrames(WEST, frames);
		frames.clear();

		registerAnimation(attackAnim);
	}

	void update(const int32_t& deltaTime) override {
		Entity::update(deltaTime);

		const Frame* frame = nextFrame(deltaTime, m_direction);
		if (frame != nullptr)
			m_sprite.setTextureRect(frame->bounds);
	}

	void render(sf::RenderTarget& target) override {
		m_sprite.setPosition(m_position.x, m_position.y);

		target.draw(m_sprite);
	}

private:
	sf::Texture skinTexture;
	sf::Sprite m_sprite;
};

#endif