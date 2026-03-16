#include "native/glglfw.h"
#include "native/stb_image.h"

#include "util.hpp"

#include "yaml-cpp/yaml.h"

#include <fstream>
#include <memory>
#include <sstream>

#include "core/resourcemanager.hpp"

// Static Sprite

std::unique_ptr<StaticSprite> ResourceManager::loadSprite(const std::string &imagePath, bool alpha) {
    std::unique_ptr<StaticSprite> staticSpr = std::make_unique<StaticSprite>();
    staticSpr->sprite = std::make_unique<Sprite>();

    if (alpha) {
        staticSpr->sprite->internal_format = GL_RGBA;
        staticSpr->sprite->img_format = GL_RGBA;
    }

    int width;
    int height;
    int nrChannels;

    unsigned char *data = stbi_load(imagePath.c_str(), &width, &height, &nrChannels, alpha ? 4 : 3);
    if (!data) {
        Logger::log("Texture loading error: " + std::string(imagePath));
        Logger::log("Reason: " + std::string(stbi_failure_reason()));
    }

    staticSpr->sprite->createSprite(width, height, data);
    stbi_image_free(data);

    return std::move(staticSpr);
}

// Animated Sprite

std::unique_ptr<AnimatedSprite> ResourceManager::loadSprite(const std::string &imagePath, const std::string &configPath, bool alpha) {
    YAML::Node sprConfig = YAML::LoadFile(configPath);

    YAML::Node anim = sprConfig["animation"];

    if (!anim.IsMap()) {
        Logger::log("Warning: Couldn't open animation config: " + configPath);
    }

    int rows = anim["rows"].as<int>(1);
    int columns = anim["columns"].as<int>(1);
    int frames = anim["frames"].as<int>(1);
    int fps = anim["fps"].as<int>(1);

    std::unique_ptr<AnimatedSprite> animSpr = std::make_unique<AnimatedSprite>(rows, columns, fps, frames);
    animSpr->sprite = std::make_unique<Sprite>();

    if (alpha) {
        animSpr->sprite->internal_format = GL_RGBA;
        animSpr->sprite->img_format = GL_RGBA;
    }

    int width;
    int height;
    int nrChannels;

    unsigned char *data = stbi_load(imagePath.c_str(), &width, &height, &nrChannels, alpha ? 4 : 3);
    if (!data) {
        Logger::log("Texture loading error: " + std::string(imagePath));
        Logger::log("Reason: " + std::string(stbi_failure_reason()));
    }

    animSpr->sprite->createSprite(width, height, data);
    stbi_image_free(data);

    return std::move(animSpr);
}

// Texture Atlas

// TODO: Implement texture atlas
std::unique_ptr<TextureAtlas> ResourceManager::loadAtlas(const std::string &imagePath, const std::string &configPath, bool alpha) {
    std::unique_ptr<TextureAtlas> atlas = std::make_unique<TextureAtlas>();

    return std::move(atlas);
}

// Shader

Shader ResourceManager::loadShader(const std::string &vertexPath, const std::string &fragmentPath) {
    std::string vertexSrc = getTextFromFile(vertexPath);
    std::string fragmentSrc = getTextFromFile(fragmentPath);

    Shader shader;
    shader.createShader(vertexSrc, fragmentSrc);

    return shader;
}

std::string ResourceManager::getTextFromFile(const std::string &vertexPath) {
    std::ifstream file(vertexPath);
    std::stringstream buffer;

    buffer << file.rdbuf();
    return buffer.str();
}