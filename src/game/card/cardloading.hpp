#pragma once

#include <yaml-cpp/yaml.h>

#include "game/card/card.hpp"
#include "game/card/cardpack.hpp"

#include "core/resourcemanager.hpp"

namespace ResourceManager {
    CardValue getCardValue(YAML::Node &valueConfig, CardValueType type);
    std::unordered_map<std::string, Card> loadCards(const std::string &configPath, TextureAtlas* cardAtlas);
    std::unordered_map<std::string, CardPack> loadCardPacks(const std::string &configPath);
}