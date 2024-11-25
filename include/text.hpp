// Author: oknauta
// License:
// File: text.hpp
// Date: 2024-11-23

// This file is obsolete.

#ifndef TEXT_HPP
#define TEXT_HPP

#include <GL/glew.h>
#include <iostream>
#include <memory>
#include <glm/vec3.hpp>

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
        Text(std::string *text, int position_x, int position_y, unsigned int font_size, int red, int green, int blue);
        /**
         * @brief Draw the text.
         */
        void draw();

    private:
        void initFreetype();
        void loadFont(const char *font_path);
        int _font_size;
        FT_Face _face;       // Handle to freetype face object.
        FT_Library _library; // Handle to freetype library.
    };

} // Elenore

#endif // TEXT_HPP