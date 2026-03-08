#pragma once

#include "texture.hpp"
#include <memory>
#include <glm/common.hpp>

class GameObject {
  public:
    std::unique_ptr<Texture> texture;
    glm::vec3 color;

    glm::vec2 position;
    glm::vec2 size;

    float rotation;

  public:
    GameObject();

    GameObject(GameObject &&) = default;
    GameObject &operator=(GameObject &&) = default;

    // Picks up the ownership of the texture
    void storeTexture(Texture texture);
    void moveTo(glm::vec2 position);
};