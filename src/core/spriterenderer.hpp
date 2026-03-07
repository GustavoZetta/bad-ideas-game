#pragma once

#include <memory>
#include <vector>

#include "shader.hpp"
#include "sprite.hpp"
#include "texture.hpp"

class SpriteRenderer {
  public:
    SpriteRenderer();

    void createSprite();

    void init();
    void render();

  private:
    std::unique_ptr<Shader> shader;
    std::unique_ptr<Texture> texture;

    std::vector<Sprite> spriteList;
};