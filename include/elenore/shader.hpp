// Author: oknauta
// License:
// File: shader.hpp
// Date: 2024-11-27

#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>
#include <glm/matrix.hpp>

namespace Elenore::Graphics
{
    class Shader
    {
    public:
        Shader(const char *vertex_shader_source, const char *fragment_shader_source);
        void setUniform(const char *name, glm::mat4 matrix);
        void use();

    private:
        GLuint _program;
        GLuint compileShader(GLenum type, const char *shader_source);
        void compileCheck(GLuint program, GLboolean is_shader);
        void createProgram(GLuint vertex_shader, GLuint fragment_shader);
        GLint _location;
    };
} // namespace Elenore::Graphics

#endif // SHADER_HPP