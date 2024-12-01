// Author: oknauta
// License:
// File: tools.cpp
// Date: 2024-11-30

#include "elenore/core/tools.hpp"
#include "elenore/core/log.hpp"
#include <zip.h>

namespace Elenore::Tools
{
    const char *readTextFile(const char *zip_path, const char *file_path)
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

        char *buffer = new char[_stat.size];

        zip_fread(_file, buffer, _stat.size);

        zip_fclose(_file);
        zip_close(_zip);
        
        buffer[_stat.size] = '\0';
        
        return buffer;
    }

} // namespace Elenore::Tools