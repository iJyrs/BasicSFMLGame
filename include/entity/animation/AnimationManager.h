#ifndef ANIMATIONMANAGER_H
#define ANIMATIONMANAGER_H

#include <iostream>
#include <map>
#include "Animation.h"

class AnimationManager {

private:
	std::map<std::string, Animation> m_animations;
	std::string current;
	std::string m_default = "idle"; // The animation an entity should revert to when a selcted animation is over.

public:
	AnimationManager() {

	}

public:
	void registerAnimation(const Animation& animation);
	void playAnimation(const std::string& name, bool force);
	void playAnimation(const std::string& name);
	void reset();

public:
	const Frame* nextFrame(int16_t deltaTime);

};

#endif