// Author: oknauta
// License:
// File: log.cpp
// Date: 2024-11-26

#include <elenore/log.hpp>

#include <iostream>

namespace Elenore::Log
{
    void info(const char *description)
    {
        std::cout << "INFO: " << description << "\n";
    }
    void error(const char *description)
    {
        std::cerr << "INFO: " << description << "\n";
    }
    void warning(const char *description)
    {
        std::cout << "WARNING: " << description << "\n";
    }
} // namespace Elenore::Log