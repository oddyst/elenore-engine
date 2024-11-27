// Author: oknauta
// License:
// File: text.hpp
// Date: 2024-11-27

#ifndef TEXT_HPP
#define TEXT_HPP

#include <freetype2/ft2build.h>
#include FT_FREETYPE_H

#include <map>
#include <string>

namespace Elenore::Graphics::UI
{
    class Text
    {
    public:
        Text(const std::string &text, const int &size);
        ~Text();

    private:
        struct Character;
        std::map<char, Character> Characters;
        int _size;
        FT_Library _ft;
        FT_Face _face;
    };
} // namespace Elenore::Graphics::UI

#endif // TEXT_HPP