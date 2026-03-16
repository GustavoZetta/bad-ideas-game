#pragma once

#include <glm/common.hpp>

#include <memory>

#include "core/renderer/sprite.hpp"

// Expects you to initialize the sprite
class AnimatedSprite {
  public:
    std::unique_ptr<Sprite> sprite;

    int frames;
    float frameDuration;
    int cols;
    int rows;

    int currentFrame;
    float timer;

  public:
    AnimatedSprite(int rows, int cols, int fps, int frames);

    void update(float deltaTime);

    glm::vec2 getUVSize();
    glm::vec2 getUVOffset();
};