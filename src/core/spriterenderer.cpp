#include "../native/glglfw.h"

#include "logger.hpp"
#include "spriterenderer.hpp"

#include <glm/common.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/matrix.hpp>
#include <memory>

SpriteRenderer::SpriteRenderer() : shader(nullptr), width(640), height(480) {
    spriteList.reserve(16);
}

void SpriteRenderer::init() {
    Logger::log("Initializing Sprite Renderer...");
    shader = std::make_unique<Shader>();

    shader->setInt("image", 0, true);

    glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f, -1.0f, 1.0f);
    shader->setMat4x4("projection", projection, true);

    createSprite();
}

void SpriteRenderer::render() {
    glUseProgram(shader->ID());

    for (size_t i = 0; i < spriteList.size(); ++i) {
        Sprite &spr = spriteList[i];

        glm::mat4 model = glm::mat4(1.0f);

        model = glm::translate(model, glm::vec3(spr.position, 0.0f));
        model = glm::translate(model, glm::vec3(0.5 * spr.size.x, 0.5 * spr.size.y, 0.0));

        model = glm::rotate(model, glm::radians(spr.rotation), glm::vec3(0.0, 0.0, 1.0));

        model = glm::translate(model, glm::vec3(-0.5 * spr.size.x, -0.5 * spr.size.y, 0.0));
        model = glm::scale(model, glm::vec3(spr.size, 1.0f));

        shader->setMat4x4("model", model, false);
        shader->setVec3f("spriteColor", spr.color, false);

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, spr.texture->ID());

        glBindVertexArray(spr.getVAO());
        glDrawArrays(GL_TRIANGLES, 0, 6);
        glBindVertexArray(0);
    }
}

void SpriteRenderer::cleanup() {
    spriteList.clear(); // Sprite destructor deletes VAOs & VBOs
    shader.reset();     // Shader destructor deletes shader program
}

void SpriteRenderer::createSprite() {
    unsigned int VAO;
    unsigned int VBO;
    float vertices[] = {
        // pos // tex
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f};

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(VAO);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void *)0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    spriteList.emplace_back(VAO, VBO);

    Sprite &sprite = spriteList.back();
    sprite.texture = std::make_unique<Texture>("../../src/assets/player.png", true);

    sprite.color = glm::vec3(1.0f, 1.0f, 1.0f);

    sprite.position = glm::vec2(50.0f, 50.0f);
    sprite.size = glm::vec2(100.0f, 100.0f);
    sprite.rotation = 0.0f;
}