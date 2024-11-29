// Author: oknauta
// License:
// File: log.cpp
// Date: 2024-11-28

#include "elenore/log.hpp"
#include <iostream>

#define RED_COLOR "\033[31m"
#define GREEN_COLOR "\033[32m"
#define WHITE_COLOR "\033[0m"

namespace Elenore::Log
{

    void info(const std::string &description)
    {
        std::cout << GREEN_COLOR
                  << "[INFO] "
                  << WHITE_COLOR
                  << description
                  << "\n";
    }
    void error(const std::string &description)
    {
        std::cerr << RED_COLOR
                  << "[ERROR] "
                  << WHITE_COLOR
                  << description
                  << "\n";
    }
} // namespace Elenore::Log