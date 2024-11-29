// Author: oknauta
// License:
// File: log.hpp
// Date: 2024-11-28

#ifndef ELN_LOG_HPP
#define ELN_LOG_HPP

#include <string>

namespace Elenore::Log
{
    void info(const std::string &description);
    void error(const std::string &description);
} // namespace Elenore::Log

#endif // ELN_LOG_HPP