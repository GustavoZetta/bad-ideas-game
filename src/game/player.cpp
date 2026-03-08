
#include "../core/util.hpp"
#include "player.hpp"

Player::Player() : GameObject() {
    texture = std::make_unique<Texture>(Common::getContentPath() + "/assets/player.png", true);

    size = glm::vec3(100.0f);
}