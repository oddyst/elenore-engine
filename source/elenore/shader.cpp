// Author: oknauta
// License:
// File: shader.cpp
// Date: 2024-11-27

#include <elenore/log.hpp>
#include <elenore/shader.hpp>
#include <glm/ext.hpp>

namespace Elenore::Graphics
{
    Shader::Shader(const char *vertex_shader_source, const char *fragment_shader_source)
    {
        GLuint vertex_shader = compileShader(GL_VERTEX_SHADER, vertex_shader_source);
        GLuint fragment_shader = compileShader(GL_FRAGMENT_SHADER, fragment_shader_source);

        createProgram(vertex_shader, fragment_shader);
    }

    void Shader::createProgram(GLuint vertex_shader, GLuint fragment_shader)
    {
        _program = glCreateProgram();
        glAttachShader(_program, vertex_shader);
        glAttachShader(_program, fragment_shader);
        glLinkProgram(_program);
        compileCheck(_program, GL_FALSE);
    }

    GLuint Shader::compileShader(GLenum type, const char *shader_source)
    {
        GLuint _shader;

        if (type == GL_VERTEX_SHADER)
            Log::info("Compiling vertex shader...");
        else if (type == GL_FRAGMENT_SHADER)
            Log::info("Compiling fragment shader...");

        _shader = glCreateShader(type);
        glShaderSource(_shader, 1, &shader_source, nullptr);
        glCompileShader(_shader);
        compileCheck(_shader, GL_TRUE);
        return _shader;
    };

    void Shader::compileCheck(GLuint id, GLboolean is_shader)
    {
        GLint _success;
        GLchar _log[1024];

        if (is_shader)
        {
            glGetShaderiv(id, GL_COMPILE_STATUS, &_success);

            if (!_success)
            {
                glGetShaderInfoLog(id, sizeof(_log), nullptr, _log);
                Log::error(_log);
            }
        }
        else
        {
            glGetProgramiv(id, GL_LINK_STATUS, &_success);
            if (!_success)
            {
                glGetShaderInfoLog(id, sizeof(_log), nullptr, _log);
                Log::error(_log);
            }
        }
    }

    void Shader::use()
    {
        glUseProgram(_program);
    }

    void Shader::setUniform(const char *name, glm::mat4 matrix)
    {
        _location = glGetUniformLocation(_program, name);

        if (_location == -1)
        {
            Log::error(std::string("Failed to get uniform location ") + name);
            return;
        }

        glUniformMatrix4fv(_location, 1, GL_FALSE, glm::value_ptr(matrix));
    }
} // namespace Elenore::Graphics