#ifndef COMPONENT_H
#define COMPONENT_H

#include <SFML/Graphics/RenderTarget.hpp>

class Component {

public:
	virtual void update(float deltaTime) = 0;
	virtual void render(sf::RenderTarget& target) = 0;

};

#endif