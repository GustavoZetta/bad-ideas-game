
#include "gameobject.hpp"

GameObject::GameObject() : texture(nullptr), color(glm::vec3(1.0f)), position(glm::vec2(0.0f)), size(glm::vec2(0.0f)), rotation(0.0f) {}

void GameObject::storeTexture(Texture t) {
    texture = std::make_unique<Texture>(std::move(t));
}

void GameObject::moveTo(glm::vec2 pos) {
    position = pos;
}