// Author: oknauta
// License: 
// File: text.cpp
// Date: 2024-11-23

#include <text.hpp>

namespace Elenore
{
    struct Character
    {
        
    };
    
    Text::Text(const char *text, int position_x, int position_y, unsigned int font_size, int red, int green, int blue)
    {
        initFreetype();
    }
    
    // void Text::loadFont(const char* font_path) {
    //     if (FT_New_Face(_library, font_path, 0, &_face)) {
    //         std::cerr << "Erro ao carregar a fonte!" << std::endl;
    //         exit(1);
    //     }

    //     FT_Set_Pixel_Sizes(_face, 0, _font_size);

    //     // Carrega os caracteres para a renderização
    //     glPixelStorei(GL_UNPACK_ALIGNMENT, 1); // Evita o preenchimento de byte extra
    //     for (GLubyte c = 0; c < 128; c++) {
    //         if (FT_Load_Char(_face, c, FT_LOAD_RENDER)) {
    //             std::cerr << "Erro ao carregar o caractere: " << c << std::endl;
    //             continue;
    //         }

    //         GLuint texture;
    //         glGenTextures(1, &texture);
    //         glBindTexture(GL_TEXTURE_2D, texture);
    //         glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, _face->glyph->bitmap.width, _face->glyph->bitmap.rows, 0,
    //                      GL_RED, GL_UNSIGNED_BYTE, face->glyph->bitmap.buffer);
    //         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //         glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    //         Character character = {
    //             texture,
    //             glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
    //             glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
    //             static_cast<GLuint>(face->glyph->advance.x)
    //         };
    //         characters.insert(std::pair<char, Character>(c, character));
    //     }
    // }

    void Text::draw()
    {
    }

    void Text::initFreetype()
    {
        if(FT_Init_FreeType(&_library))
        {
            std::cerr << "Error while starting Freetype library.\n";
            exit(1);
        }
    }
} // Elenore