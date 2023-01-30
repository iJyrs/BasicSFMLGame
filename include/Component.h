#ifndef COMPONENT_H
#define COMPONENT_H

#include <SFML/Graphics/RenderTarget.hpp>

class Component {

public:
	virtual void update(int32_t deltaTime) = 0;
	virtual void render(sf::RenderTarget& target) = 0;

};

#endif