#ifndef ANIMATED_H
#define ANIMTED_H

#include <map>
#include "Animation.h"

class Animated {

private:
	std::map<std::string, Animation> m_animations;
	std::string currentAnimation = "idle";

public:
	void registerAnimation(const Animation& animation);
	Animation* getAnimation(const std::string& name);
	void playAnimation(const std::string name);

public:
	const Frame* nextFrame(const int16_t& deltaTime, const FaceDirection& direction);

};

#endif