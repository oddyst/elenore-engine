// Author: oknauta
// License:
// File: logger.hpp
// Date: 2024-11-24

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

namespace Elenore::Log
{
        void info(const std::string message);

        void error(const std::string message);
} // Elenore::Log

#endif // LOGGER_HPP