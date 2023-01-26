#ifndef ENTITYHUMAN_H
#define ENTITYHUMAN_H

#include "Entity.h"

class EntityHuman : public Entity {

public:
	EntityHuman();

public:
	void render(sf::RenderTarget& target) override;

};

#endif