// Author: oknauta
// License: 
// File: logger.cpp
// Date: 2024-11-24

#include <logger.hpp>
#include <iostream>

namespace Logger
{
    void log(const std::string message)
    {
        std::cout << "LOG: " << message << "\n";
    }

    void error(const std::string message)
    {
        std::cerr << "ERROR: " << message << "\n";
    }

    // Your code
} // Logger