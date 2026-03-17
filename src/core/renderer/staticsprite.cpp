
#include "core/renderer/staticsprite.hpp"

StaticSprite::StaticSprite(std::unique_ptr<Sprite> spr) : sprite(nullptr) {
    sprite = std::move(spr);
}

glm::vec2 StaticSprite::getUVSize() {
    return glm::vec2(1.0f, 1.0f);
}

glm::vec2 StaticSprite::getUVOffset() {
    return glm::vec2(0.0f, 0.0f);
}