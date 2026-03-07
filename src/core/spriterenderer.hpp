#pragma once

#define GLFW_INCLUDE_GLCOREARB

#include <memory>
#include <vector>

#include "shader.hpp"
#include "sprite.hpp"

class SpriteRenderer {
  public:
    // Size of the rendered scene (temporary)
    // TODO: Scene system
    int width;
    int height;

  public:
    SpriteRenderer();

    void createSprite();

    void init();
    void render();
    void cleanup();

  private:
    std::unique_ptr<Shader> shader;

    std::vector<Sprite> spriteList;
};