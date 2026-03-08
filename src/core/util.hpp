#pragma once

#include <string>

struct Common {
    static std::string getContentPath();
};

// TODO: more robust logging
struct Logger {
    static void log(std::string message);
};