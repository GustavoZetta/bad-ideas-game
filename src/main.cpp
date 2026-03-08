
#include "core/util.hpp"

#include "native/glglfw.h"

#include <iostream>
#include <string>

#include "core/game.hpp"

int main() {
    Game game;

    game.init();
    game.run();

    game.stop();

    Logger::log("Program finalized, end of execution");
}