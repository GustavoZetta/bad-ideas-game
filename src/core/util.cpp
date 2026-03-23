
#include "util.hpp"

#include <algorithm>
#include <iostream>

std::string Common::getContentPath() {
    return "../../content";
}

std::string Common::getContentPath(const std::string &s) {
    return "../../content" + s;
}

std::string Common::toUpperCase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

std::string Common::toLowerCase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

// TODO: more robust logging
void Logger::log(std::string message) {
    if (canLog) {
        std::cout << message << std::endl;
    }
}

void Logger::info(std::string message) {
    if (canInfo) {
        std::cout << "[INFO] " << message << std::endl;
    }
}

void Logger::warn(std::string message) {
    if (canWarn) {
        std::cout << "[WARN] " << message << std::endl;
    }
}

void Logger::error(std::string message) {
    if (canError) {
        std::cout << "[ERROR] " << message << std::endl;
    }
}
