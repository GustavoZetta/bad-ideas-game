#pragma once

#define GLFW_INCLUDE_GLCOREARB

#include <glm/common.hpp>
#include <memory>

#include "gameobject.hpp"
#include "shader.hpp"
#include "texture.hpp"

class SpriteRenderer {
  public:
    std::unique_ptr<Shader> shader;

  public:
    SpriteRenderer();

    void createScreen();
    void drawSprite(Texture &texture, glm::vec3 color, glm::vec2 position, glm::vec2 size, float rotation);
    void drawSprite(GameObject *obj);

    void init();
    void cleanup();

  private:
    unsigned int m_VAO;
    unsigned int m_VBO;
};