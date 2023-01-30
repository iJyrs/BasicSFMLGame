#ifndef ENTITYHUMAN_H
#define ENTITYHUMAN_H

#include "Entity.h"
#include "animation/Animation.h"

class EntityHuman : public Entity {

public:
	EntityHuman();

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	Animation m_animation;

public:
	void update(int32_t deltaTime) override;
	void render(sf::RenderTarget& target) override;

};

#endif