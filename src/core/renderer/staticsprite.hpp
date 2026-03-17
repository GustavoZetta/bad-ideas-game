#pragma once

#include <glm/common.hpp>

#include <memory>

#include "core/renderer/sprite.hpp"

// Expects you to initialize the sprite
class StaticSprite {
  public:
    std::unique_ptr<Sprite> sprite;

  public:
    StaticSprite(std::unique_ptr<Sprite> spr);

    glm::vec2 getUVSize();
    glm::vec2 getUVOffset();
};