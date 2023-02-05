#ifndef CHUNK_H
#define CHUNK_H

#include <vector>

#include "../tile/Tile.h"

class Chunk : public Component {

private:
	std::vector<Tile> m_tiles;

public:
	Chunk() {
		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 10; y++) {
				float posX = (float)(x * 48), posY = (float)(y * 48);

				m_tiles.emplace_back(Tile(sf::Vector2f(posX, posY)));
			}
		}
	}

public:
	void update(const int32_t& deltaTime) override {
		for (int i = 0; i < m_tiles.size(); i++) {
			m_tiles.at(i).update(deltaTime);
		}
	}

	void render(sf::RenderTarget& target) override {
		for (int i = 0; i < m_tiles.size(); i++) {
			m_tiles.at(i).render(target);
		}
	}

};

#endif