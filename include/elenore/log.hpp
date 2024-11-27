// Author: oknauta
// License:
// File: log.hpp
// Date: 2024-11-26

#ifndef LOG_HPP
#define LOG_HPP

#include <string>

namespace Elenore::Log
{
    void info(const std::string &description);
    void error(const std::string &description);
    void warning(const std::string &description);
} // namespace Elenore::Log

#endif // LOG_HPP