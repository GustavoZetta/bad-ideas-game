
#include "core/util.hpp"

#include "native/glglfw.h"

#include <iostream>
#include <string>

#include "core/game.hpp"

const bool debug = true;

int main() {
    Game game(debug);

    game.init();
    game.run();

    game.stop();

    Logger::log("Program finalized, end of execution");
}