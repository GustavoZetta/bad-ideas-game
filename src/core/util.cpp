
#include "util.hpp"

#include <iostream>

const std::string path = "../../content";

const std::string &Common::getContentPath() {
    return path;
}

// TODO: more robust logging
void Logger::log(std::string message) {
    std::cout << message << std::endl;
}

