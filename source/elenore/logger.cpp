// Author: oknauta
// License: 
// File: logger.cpp
// Date: 2024-12-01

#include "elenore/logger.hpp"
#include <iostream>

namespace Elenore::Log
{
    const char *RESET = "\033[0m";
    const char *RED = "\033[31m";
    const char *GREEN = "\033[32m";

    void info(const char *description)
    {
        std::cout << GREEN
                  << "[INFO] "
                  << RESET
                  << description
                  << "\n";
    }
    void error(const char *description)
    {
        std::cerr << RED
                  << "[ERROR] "
                  << RESET
                  << description
                  << "\n";
    }
} // namespace Elenore::Log