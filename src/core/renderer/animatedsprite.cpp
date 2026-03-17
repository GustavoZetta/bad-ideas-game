#include "core/renderer/animatedsprite.hpp"

AnimatedSprite::AnimatedSprite(std::unique_ptr<Sprite> spr, int rows, int cols, int fps, int frames)
    : sprite(nullptr), cols(cols), rows(rows), frames(frames),
      currentFrame(0), frameDuration(1.0f / fps), timer(0.0f) {
    sprite = std::move(spr);
}

void AnimatedSprite::update(float deltaTime) {
    timer += deltaTime;
    if (timer >= frameDuration) {
        timer = 0.0f;
        currentFrame = (currentFrame + 1) % frames;
    }
}

glm::vec2 AnimatedSprite::getUVOffset() {
    int col = currentFrame % cols;
    int row = currentFrame / cols;
    return glm::vec2(
        (float)col / cols,
        (float)row / rows);
}

glm::vec2 AnimatedSprite::getUVSize() {
    return glm::vec2(1.0f / cols, 1.0f / rows);
}