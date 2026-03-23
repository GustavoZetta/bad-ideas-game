#pragma once

#include <string>

struct Common {
    static std::string getContentPath();
    static std::string Common::getContentPath(const std::string &path);
    static std::string toUpperCase(std::string str);
    static std::string toLowerCase(std::string str);
};

// TODO: more robust logging
struct Logger {
    static const bool canLog = true;
    static const bool canInfo = true;
    static const bool canWarn = true;
    static const bool canError = true;

    static void log(std::string message);
    static void info(std::string message);
    static void warn(std::string message);
    static void error(std::string message);
};