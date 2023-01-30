#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>

#include "../Component.h"

class World : public Component {

private:
	std::string m_name;

public:
	World(const std::string m_name);

public:
	void update(int32_t deltaTime) override;
	void render(sf::RenderTarget& target) override;

};

#endif