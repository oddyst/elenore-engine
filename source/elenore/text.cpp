// Author: oknauta
// License:
// File: text.cpp
// Date: 2024-11-27

#include <GL/glew.h>

#include <elenore/log.hpp>
#include <elenore/text.hpp>
#include <glm/vec2.hpp>

namespace Elenore::Graphics::UI
{
    struct Text::Character
    {
        GLuint _texture_ID;
        glm::ivec2 size;
        glm::ivec2 bearing;
        glm::ivec2 advance;
    };

    Text::Text(const std::string &text, const int &size)
        : _size(size)
    {
        if (FT_Init_FreeType(&_ft))
        {
            Log::warning("Failed to start FreeType.");
            return;
        }

        // Setting width 0 will calculate automatically.
        if (FT_New_Face(_ft, "fonts/arial.ttf", 0, &_face))
        {
            Log::warning("Failed to load font.");
            return;
        }
        FT_Set_Pixel_Sizes(_face, 0, size);

        FT_Load_Glyph(_face, 'x', FT_LOAD_RENDER);
    }

    Text::~Text()
    {
        if (_face)
            FT_Done_Face(_face);
        if (_ft)
            FT_Done_FreeType(_ft);
    }
} // namespace Elenore::Graphics::UI