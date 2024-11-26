// Author: oknauta
// License:
// File: log.hpp
// Date: 2024-11-26

#ifndef LOG_HPP
#define LOG_HPP

namespace Elenore::Log
{
    void info(const char *description);
    void error(const char *description);
    void warning(const char *description);
} // namespace Elenore::Log

#endif // LOG_HPP