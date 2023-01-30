#include "../../../include/entity/animation/AnimationManager.h"

void AnimationManager::registerAnimation(const Animation& animation) {
	m_animations.insert({ animation.getName(), animation });
}

void AnimationManager::playAnimation(const std::string& name, bool force) {

}

void AnimationManager::playAnimation(const std::string& name) {
	playAnimation(name, false);
}

void AnimationManager::reset() {

}

const Frame* AnimationManager::nextFrame(int16_t deltaTime) {
	return nullptr;
}
