#ifndef TILE_H
#define TILE_H

#include "../Component.h"

class Tile : public Component {

public:
	Tile(sf::Vector2f position) :
		m_position(position)
	{
		sprite.setScale({ 1.5, 1.5 });
	}

public:
	void update(const int32_t& deltaTime) override {

	}

	void render(sf::RenderTarget& target) override {
		sf::Texture texture;
		texture.loadFromFile("assets/tile.png");

		sprite.setTexture(texture);
		sprite.setPosition(m_position);

		target.draw(sprite);
	}

private:
	sf::Vector2f m_position;
	sf::Sprite sprite;

};

#endif