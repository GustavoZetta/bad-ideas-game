
#include "util.hpp"

#include <iostream>

std::string Common::getContentPath() {
    return "../../content";
}

// TODO: more robust logging
void Logger::log(std::string message) {
    std::cout << message << std::endl;
}

