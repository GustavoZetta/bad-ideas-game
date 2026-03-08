
#include "world.hpp"

World::World() : player(nullptr) {
    player = std::make_unique<Player>();
}