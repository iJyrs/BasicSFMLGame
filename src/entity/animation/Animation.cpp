#include "../../../include/entity/animation/Animation.h"

Animation::Animation(const std::string& name, const bool& isLooping) :
	m_name(name),
	m_looping(isLooping)
{

}

const std::string& Animation::getName() const {
	return m_name;
}

const bool& Animation::isLooping() const {
	return m_looping;
}

void Animation::setLooping(const bool& isLooping) {
	m_looping = isLooping;
}

void Animation::addFrames(const FaceDirection& direction, const std::vector<Frame>& frames) {
	m_frames.insert({ direction, frames });
}

void Animation::addFrames(const std::vector<Frame>& frames) {
	addFrames(NORTH, frames);
	addFrames(SOUTH, frames);
	addFrames(WEST, frames);
	addFrames(EAST, frames);
}

const Frame* Animation::nextFrame(const int16_t& deltaTime, FaceDirection direction) {
	switch (direction) {
		case NORTH_EAST:
		case SOUTH_EAST:
			direction = EAST;
		break;
		case NORTH_WEST:
		case SOUTH_WEST:
			direction = WEST;
		break;
	}

	auto animation = m_frames.find(direction);
	if (animation == m_frames.end()) {
		animation = m_frames.find(SOUTH); // Attempt to default to SOUTH direction.

		if (animation == m_frames.end()) return nullptr; // Animation with given direction not found.
	}

	Frame& frame = animation->second.at(m_index);

	if (m_indexProgress >= frame.duration) { // if the animation is over
		m_index++; // move to the next frame
		m_indexProgress = 0; // reset progress

		if (m_index >= animation->second.size()) { // if index is out of bounds reset.
			reset();

			return nullptr;
		}
	}

	m_indexProgress += deltaTime;
	return &frame;
}

void Animation::reset() {
	m_index = 0;
	m_indexProgress = 0;
}