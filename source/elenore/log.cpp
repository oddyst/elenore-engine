// Author: oknauta
// License:
// File: log.cpp
// Date: 2024-11-26

#include "elenore/log.hpp"

#include <iostream>

namespace Elenore::Log
{
    const std::string RESET = "\033[0m";
    const std::string INFO_COLOR = "\033[32m";
    const std::string WARNING_COLOR = "\033[33m";
    const std::string ERROR_COLOR = "\033[31m";

    void info(const std::string &description)
    {
        std::cout << INFO_COLOR << "[INFO]: " << RESET << description << "\n";
    }
    void error(const std::string &description)
    {
        std::cerr << ERROR_COLOR << "[ERROR]: " << RESET << description << "\n";
    }
    void warning(const std::string &description)
    {
        std::cout << WARNING_COLOR << "[WARNING]: " << RESET << description << "\n";
    }
} // namespace Elenore::Log