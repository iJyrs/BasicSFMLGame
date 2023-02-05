#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Component {

public:
	virtual void update(const int32_t& deltaTime) = 0;
	virtual void render(sf::RenderTarget& target) = 0;

};

#endif