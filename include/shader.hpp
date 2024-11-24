// Author: oknauta
// License: 
// File: shader.hpp
// Date: 2024-11-23

#ifndef SHADER_HPP
#define SHADER_HPP

#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>


namespace Elenore
{
    class Shader
    {
    public:
        Shader(const char *source_vertex_shader, const char *source_fragment_shader);
        inline GLuint getProgram() const { return _program_id; }
        ~Shader();
    private:
        void checkShaderCompile(GLuint programID, bool is_shader);
        void compileShader(GLenum shader_type, GLuint shader, const char *shader_source, GLboolean is_shader);
        GLuint _program_id;
        GLuint _fragment_shader;
        GLuint _vertex_shader;
        const char *_source_vertex_shader, *_source_fragment_shader;
    };
    
} // Elenore

#endif // SHADER_HPP