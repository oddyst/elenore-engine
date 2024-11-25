// Author: oknauta
// License:
// File: logger.cpp
// Date: 2024-11-24

#include <iostream>
#include <logger.hpp>

namespace Log
{
void info(const std::string message)
{
    std::cout << "INFO: " << message << "\n";
}

void error(const std::string message)
{
    std::cerr << "ERROR: " << message << "\n";
}

// Your code
} // namespace Log