#ifndef ANIMATION_H
#define ANIMATION_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "../FaceDirection.h"

struct Frame {

	sf::IntRect bounds;
	int16_t duration;

};

class Animation {

private:
	const std::string m_name;
	bool m_looping = false;
	std::map<FaceDirection, std::vector<Frame>> m_frames;
	int8_t m_index = 0;
	int16_t m_indexProgress = 0;

public:
	Animation(const std::string& name, const bool& isLooping);

public:
	const std::string& getName() const;
	const bool& isLooping() const;
	void setLooping(const bool& looping);

	void addFrames(const FaceDirection& direction, const std::vector<Frame>& frames);
	void addFrames(const std::vector<Frame>& frames);
	const Frame* nextFrame(const int16_t& deltaTime, FaceDirection direction);
	void reset();

};

#endif