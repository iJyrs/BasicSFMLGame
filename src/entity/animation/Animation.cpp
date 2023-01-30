#include "../../../include/entity/animation/Animation.h"

Animation::Animation() {

}

Animation::Animation(const std::string& name, const std::vector<Frame>& frames) :
	m_name(name),
	m_frames(frames)
{

}

const std::string& Animation::getName() const {
	return m_name;
}

const Frame* Animation::nextFrame(int16_t deltaTime) {
	Frame& frame = m_frames.at(m_index);

	if (m_indexProgress >= frame.duration) {
		m_index++;
		m_indexProgress = 0;

		if (m_index >= m_frames.size()) {
			m_index = 0;
			m_indexProgress = 0;

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