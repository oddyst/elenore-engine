// Author: oknauta
// License:
// File: shader.cpp
// Date: 2024-11-28

#include "elenore/shader.hpp"
#include "elenore/log.hpp"
#include <glm/ext.hpp>

namespace Elenore::Graphics
{
    void Shader::use() const { glUseProgram(_program); }
    GLuint Shader::getProgram() const { return _program; }

    Shader::Shader(const char *vertex_shader_source, const char *fragment_shader_source)
    {
        GLuint _vertex_shader = compileShader(vertex_shader_source, GL_VERTEX_SHADER, GL_TRUE);
        GLuint _fragment_shader = compileShader(fragment_shader_source, GL_FRAGMENT_SHADER, GL_TRUE);

        _program = glCreateProgram();
        glAttachShader(_program, _vertex_shader);
        glAttachShader(_program, _fragment_shader);
        glLinkProgram(_program);
        compileCheck(_program, GL_FALSE);
    }

    GLuint Shader::compileShader(const char *source, GLenum type, GLboolean is_shader)
    {
        GLuint _shader = glCreateShader(type);
        glShaderSource(_shader, 1, &source, nullptr);
        glCompileShader(_shader);
        compileCheck(_shader, is_shader);
        if (is_shader)
            Log::info("Compiled shader");

        return _shader;
    }

    void Shader::compileCheck(GLuint shader, GLboolean is_shader)
    {
        GLint success;
        GLchar log[1024];

        if (is_shader)
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
                Log::error(log);
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
                Log::error(log);
            }
        }
    }

    void Shader::setUniform(const char *name, const glm::mat4 &matrix) const
    {
        GLuint _location = glGetUniformLocation(_program, name);

        if (_location == -1)
        {
            Log::error("Uniform not founded: " + std::string(name));
            return;
        }

        glUniformMatrix4fv(_location, 1, GL_FALSE, glm::value_ptr(matrix));
    }

    Shader::~Shader()
    {
        glDeleteShader(_program);
    }
} // namespace Elenore::Graphics