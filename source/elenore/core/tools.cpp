// Author: oknauta
// License:
// File: tools.cpp
// Date: 2024-11-30

#include "elenore/core/tools.hpp"
#include "elenore/core/log.hpp"
#include <miniz.h>

namespace Elenore::Tools
{
    const char *readTextFile(const char *path_zip, const char *path_file)
    {
        mz_zip_archive _zip;
        memset(&_zip, 0, sizeof(_zip));

        if (!mz_zip_reader_init_file(&_zip, path_zip, 0))
        {
            Log::error("Failed to open packed file.");
            return nullptr;
        }

        mz_uint _index = mz_zip_reader_locate_file(&_zip, path_file, nullptr, MZ_ZIP_FLAG_CASE_SENSITIVE);

        if (_index < 0)
        {
            Log::error("Failed to locate file.");
            mz_zip_reader_end(&_zip);
            return nullptr;
        }

        mz_zip_archive_file_stat _stat;
        if (!mz_zip_reader_file_stat(&_zip, _index, &_stat))
        {
            Log::error("Failed to load file.");
            mz_zip_reader_end(&_zip);
            return nullptr;
        }

        size_t _buffer_size = (size_t)_stat.m_uncomp_size;
        char *_buffer = new char[_buffer_size + 1];

        if (!mz_zip_reader_extract_to_mem(&_zip, _index, _buffer, _buffer_size, 0))
        {
            delete[] _buffer;
            Log::error("Failed to extract to memory.");
            mz_zip_reader_end(&_zip);
            return nullptr;
        }

        _buffer[_buffer_size] = '\0';

        mz_zip_reader_end(&_zip);

        return _buffer;
    }

} // namespace Elenore::Tools