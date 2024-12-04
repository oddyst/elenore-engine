// Author: oknauta
// License:
// File: tools.cpp
// Date: 2024-12-02

#include "elenore/tools.hpp"
#include "elenore/logger.hpp"

#include <zip.h>

namespace Elenore::Tools
{
    const char *readTextFromZip(const char *zip_path, const char *file_path)
    {

        int _error = 0;
        zip_t *_zip = zip_open(zip_path, 0, &_error);
        if (_zip == nullptr)
        {
            Log::error("Failed to open packed file.");
            return nullptr;
        }

        zip_file_t *_file = zip_fopen(_zip, file_path, 0);
        if (_file == nullptr)
        {
            Log::error("Failed to open file inside packed file.");
            return nullptr;
        }

        zip_stat_t _stat;
        zip_stat(_zip, file_path, 0, &_stat);

        char *buffer = new char[_stat.size + 1];

        zip_fread(_file, buffer, _stat.size);

        zip_fclose(_file);
        zip_close(_zip);

        buffer[_stat.size] = '\0';

        return buffer;
    }
} // namespace Elenore::Tools