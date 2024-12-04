// Author: oknauta
// License:
// File: shader.hpp
// Date: 2024-12-02

#ifndef ELN_SHADER_HPP
#define ELN_SHADER_HPP

#include <GL/gl.h>
#include <glm/mat4x4.hpp>

namespace Elenore::Graphics
{
    class Shader
    {
    public:
        Shader(const char *vertex_path, const char *fragment_path);
        void use();
        void setUniform(const char *name, glm::mat4 &matrix);
    private:
        GLuint compileShader(const char *shader_path, GLenum type, GLboolean is_shader);
        void compileCheck(GLuint shader, GLboolean is_shader);
        GLuint _program;
    };
} // namespace Elenore::Graphics

#endif // ELN_SHADER_HPP