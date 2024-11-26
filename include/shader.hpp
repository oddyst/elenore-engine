// Author: oknauta
// License:
// File: shader.hpp
// Date: 2024-11-23

#ifndef SHADER_HPP
#define SHADER_HPP

#include <GL/glew.h>

#include <glm/mat4x4.hpp>

namespace Elenore::Graphics
{
    class Shader
    {
    public:
        /**
         * @brief Creates a shader to use in mesh.
         * @param vertex_shader_source Use your vertex shader here.
         * @param fragment_shader_source Use your fragment shader here.
         */
        Shader(const char *vertex_shader_source, const char *fragment_shader_source);
        /**
         * @brief Obtain the shader program id.
         * @return `_program_id`
         */
        GLuint getProgram() const { return _program_id; }
        /**
         * @brief Sets the uniform shader for transformations.
         * @param name The uniform's name.
         * @param matrix The matrix.
         */
        void setUniform(const char *name, const glm::mat4 &matrix);

        /**
         * @brief Gets the location.
         * @return `_location`
         */
        GLint &getLocation() { return _location; };

        /**
         * @brief Use the shader.
         */
        void use() { glUseProgram(_program_id); }
        ~Shader();

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

} // Elenore::Graphics

#endif // SHADER_HPP