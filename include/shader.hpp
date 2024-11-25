// Author: oknauta
// License: 
// File: shader.hpp
// Date: 2024-11-23

#ifndef SHADER_HPP
#define SHADER_HPP

#include <iostream>
#include <vector>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext.hpp>


namespace Elenore
{
    class Shader
    {
    public:
        Shader(const char *vertex_path, const char *fragment_path);
        GLuint getProgram() const { return _program_id; }
        void setUniformMatrix4fv(const char *name, const glm::mat4 &matrix);
        GLint &getLocation() { return _location; };
    private:
        GLint _location;
        GLuint _program_id;
        /**
         * @brief Compile or link a shader to a program.
         * @param shader_type It can be `GL_VERTEX_SHADER` or `GL_FRAGMENT_SHADER`.
         * @param shader The shade that will compile.
         * @param shader_source The shader source.
         * @param is_shader If it is a shader or a program. It must be `GL_TRUE` for shader or `GL_TRUE` for program.
         */
        GLuint compileShader(GLenum shader_type, const char *shader_source);
        /**
         * @brief Checks if the shader success the compile.
         * @param program The shader or program.
         * @param is_shader If it is a shader or a program. It must be `GL_TRUE` for shader or `GL_FALSE` for program.
         */
        void compileCheck(GLuint program, GLboolean is_shader);
    };
    
} // Elenore

#endif // SHADER_HPP