#include "scene.hpp"
#include "util.hpp"
#include "yaml-cpp/yaml.h"

// TODO: Implement scene
Scene Scene::loadScene(const std::string &scenePath, const std::string &configPath) {
    YAML::Node config = YAML::LoadFile(configPath);
    
    YAML::Node tilesets = config["tilesets"];
    YAML::Node chars = config["chars"];

    if (tilesets.IsMap()) {
        for (auto n : tilesets) {
            
        }
    } else {
        Logger::log("Warning: Could not load ley 'tilesets' in scene config: " + configPath);
    }

    if (chars.IsMap()) {
        for (auto n : chars) {
            
        }
    } else {
        Logger::log("Warning: Could not load ley 'chars' in scene config: " + configPath);
    }
    
    
}

void Scene::update(float dt) {

}