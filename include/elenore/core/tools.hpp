// Author: oknauta
// License:
// File: tools.hpp
// Date: 2024-11-30

#ifndef ELN_EXTRAS_HPP
#define ELN_EXTRAS_HPP

namespace Elenore::Tools
{
    /**
     * @brief Reads a text file from a packed file.
     * @param path_zip The packed file. It must be a zip type.
     * @param path_file The file path inside the packed file.
     */
    const char *readTextFile(const char *path_zip, const char *path_file);

} // namespace Elenore::Tools

#endif // ELN_EXTRAS_HPP