#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <SFML/Graphics.hpp>

struct Frame {

	sf::IntRect bounds;
	int16_t duration;

};

class Animation {

private:
	const std::string m_name;
	std::vector<Frame> m_frames;
	int8_t m_index = 0;
	int16_t m_indexProgress = 0;

public:
	Animation();

public:
	Animation(const std::string& name, const std::vector<Frame>& frames);

public:
	const std::string& getName() const;
	const Frame* nextFrame(int16_t deltaTime);
	void reset();

};

#endif