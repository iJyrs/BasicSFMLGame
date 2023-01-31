#include "../../../include/entity/animation/Animated.h"

void Animated::registerAnimation(const Animation animation) {
	m_animations.insert({ animation.getName(), animation });
}

Animation* Animated::getAnimation(const std::string& name) {
	auto results = m_animations.find(name);

	if (results == m_animations.end())
		return nullptr;

	return &results->second;
}

void Animated::playAnimation(const std::string name) {
	if (getAnimation(name) == nullptr)
		return;

	Animation* old = getAnimation(currentAnimation);
	if (old != nullptr)
		old->reset();
	
	currentAnimation = name;
}

const Frame* Animated::nextFrame(int16_t deltaTime) {
	Animation* animation = getAnimation(currentAnimation);
	if (animation == nullptr) return nullptr;

	return animation->nextFrame(deltaTime);
}
