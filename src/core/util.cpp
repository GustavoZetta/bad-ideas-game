
#include "util.hpp"

#include <iostream>

const std::string &Common::getContentPath() {
    return "../../content";
}

// TODO: more robust logging
void Logger::log(std::string message) {
    if (true) { // Set false for a release build
        std::cout << message << std::endl;
    }
}

