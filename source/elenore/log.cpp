// Author: oknauta
// License:
// File: log.cpp
// Date: 2024-11-26

#include <elenore/log.hpp>

#include <iostream>
#include <string>

namespace Elenore::Log
{
    void info(const std::string &description)
    {
        std::cout << "INFO: " << description << "\n";
    }
    void error(const std::string &description)
    {
        std::cerr << "ERROR: " << description << "\n";
    }
    void warning(const std::string &description)
    {
        std::cout << "WARNING: " << description << "\n";
    }
} // namespace Elenore::Log