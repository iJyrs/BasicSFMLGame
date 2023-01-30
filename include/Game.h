#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>

#include "world/World.h"
#include "player/Player.h"

class Game {

private:
	sf::RenderWindow m_window;
	World m_world;
	Player m_player;

public:
	Game();

public:
	void update(int32_t deltaTime);
	void render();

public:
	sf::RenderWindow& getWindow();
	World& getWorld();
	Player& getPlayer();
	void setPlayer(const Player& player);

};

#endif