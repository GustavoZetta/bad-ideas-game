#pragma once

#include "gameobject.hpp"
#include <vector>

class Scene {
  public:
    std::vector<GameObject> objects;

  public:
    static Scene loadScene(const std::string &scenePath, const std::string &configPath);

    void update(float deltaTime);
};