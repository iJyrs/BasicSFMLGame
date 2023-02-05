#ifndef CAT_H
#define CAT_H

#include "Entity.h"

class Cat : public Entity {

public:
	Cat(const sf::Vector2f position) : Entity(position) {
		skinTexture.loadFromFile("assets/cat.png");

		m_sprite.setTexture(skinTexture);
		m_sprite.setTextureRect({ 0, 0, 32, 32 });
		m_sprite.setScale({ 3, 3 });

		Animation animation("idle", true);
		std::vector<Frame> frames;

		frames.push_back({ sf::IntRect(0, 0, 32, 32), 300 });
		frames.push_back({ sf::IntRect(32, 0, 32, 32), 300 });
		frames.push_back({ sf::IntRect(64, 0, 32, 32), 300 });
		frames.push_back({ sf::IntRect(96, 0, 32, 32), 300 });

		animation.addFrames(frames);
		registerAnimation(animation);
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