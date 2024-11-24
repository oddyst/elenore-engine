// Author: oknauta
// License: 
// File: text.hpp
// Date: 2024-11-23

#ifndef TEXT_HPP
#define TEXT_HPP

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

namespace Elenore
{
    
    class Text
    {
    public:
        /**
         * @brief Makes a text.
         * @param text The text.
         * @param position_x The horizontal position of text.
         * @param position_y The vertical position of text.
         * @param text_size The size of text.
         */
        Text(const char *text, int position_x, int position_y, unsigned int text_size, int red, int green, int blue);
    private:
        FT_Face _face; // Handle to freetype face object.
        FT_Library _library; // Handle to freetype library.
    };
    
} // Elenore

#endif // TEXT_HPP