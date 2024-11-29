// Author: oknauta
// License:
// File: shader.hpp
// Date: 2024-11-28

#ifndef ELN_SHADER_HPP
#define ELN_SHADER_HPP

#include <GL/glew.h>
#include <glm/mat4x4.hpp>

namespace Elenore::Graphics
{
    class Shader
    {
    public:
        Shader(const char *vertex_shader_source, const char *fragment_shader_source);
        /**
         * @brief Compiles a shader.
         * @param source Receiving the source.
         * @param type The type of the shader. It can be `GL_VERTEX_SHADER` or `GL_FRAGMENT_SHADER`.
         * @param is_shader If it is a shader, or a program.
         * @return `GLuint` aka `shader`
         */
        GLuint compileShader(const char *source, GLenum type, GLboolean is_shader);
        void compileCheck(GLuint shader, GLboolean is_shader);
        void use() const;
        GLuint getProgram() const;
        void setUniform(const char *name, const glm::mat4 &matrix) const;
        ~Shader();

    private:
        GLuint _program;
    };
} // namespace Elenore::Graphics

#endif // ELN_SHADER_HPP