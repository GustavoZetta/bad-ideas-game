#include "../core/resourcemanager.hpp"
#include "../core/util.hpp"

#include "player.hpp"

Player::Player() : GameObject() {
    storeTexture(ResourceManager::loadTexture(Common::getContentPath() + "/assets/player.png", false));

    size = glm::vec2(100.0f);
}