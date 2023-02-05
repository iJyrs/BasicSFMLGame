#ifndef WORLD_H
#define WORLD_H

#include <stdlib.h>

#include <map>
#include "../Component.h"
#include "../entity/Entity.h"
#include "../entity/EntityHuman.h"
#include "../entity/Cat.h"
#include "Chunk.h"

typedef std::map<uint16_t, std::shared_ptr<Entity>> EntityMap;

class World : public Component {

public:
	World(const std::string& name) :
		m_name(name)
	{

	}

	void addEntity(const std::shared_ptr<Entity> entity) {
		if (!entity) return;

		m_entities.insert({ entity->getEntityId(), entity });
	}

	std::weak_ptr<Entity> spawnEntity(const EntityType& type, const sf::Vector2f& position) {
		std::shared_ptr<Entity> entity;

		switch (type) {
		case HUMAN:

			entity = std::shared_ptr<Entity>(new EntityHuman(position));

			break;
		case CAT:

			entity = std::shared_ptr<Entity>(new Cat(position));
			
			break;
		default:
			return entity; // nullptr, we return here to stop map adding.
		}

		addEntity(entity);

		return entity;
	}

	void update(const int32_t& deltaTime) override {
		EntityMap::iterator it;

		chunk.update(deltaTime);

		for (it = m_entities.begin(); it != m_entities.end(); it++) {
			it->second->update(deltaTime);
		}
	}

	void render(sf::RenderTarget& target) override {
		EntityMap::iterator it;

		chunk.render(target);

		for (it = m_entities.begin(); it != m_entities.end(); it++) {
			it->second->render(target);
		}
	}

private:
	const std::string m_name;
	EntityMap m_entities;
	Chunk chunk;


};

#endif 