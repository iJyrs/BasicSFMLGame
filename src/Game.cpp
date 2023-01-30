#include "../include/Game.h"

#include "../include/entity/Entity.h"

Game::Game() :
	m_window(sf::VideoMode(1000, 600), "Farmer Game"),
	m_world("world"),
	m_player()
{

}

void Game::update(int32_t deltaTime) {
	m_world.update(deltaTime);
	m_player.update(deltaTime);
}

void Game::render() {
	m_world.render(m_window);
	m_player.render(m_window);
}

sf::RenderWindow& Game::getWindow() {
	return m_window;
}

World& Game::getWorld() {
	return m_world;
}

Player& Game::getPlayer() {
	return m_player;
}

void Game::setPlayer(const Player& player) {
	m_player = player;
}
