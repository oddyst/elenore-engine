// Author: oknauta
// License:
// File: shader.cpp
// Date: 2024-12-02

#include <GL/glew.h>

#include "elenore/logger.hpp"
#include "elenore/shader.hpp"

#include <string>

#include <glm/gtc/type_ptr.hpp>

namespace Elenore::Graphics
{
    Shader::Shader(const char *vertex_path, const char *fragment_path)
    {
        GLuint vertex_shader = compileShader(vertex_path, GL_VERTEX_SHADER, GL_TRUE);
        GLuint fragment_shader = compileShader(fragment_path, GL_FRAGMENT_SHADER, GL_TRUE);

        _program = glCreateProgram();
        glAttachShader(_program, vertex_shader);
        glAttachShader(_program, fragment_shader);
        glLinkProgram(_program);
        
        glDeleteShader(vertex_shader);
        glDeleteShader(fragment_shader);
    }

    GLuint Shader::compileShader(const char *shader_path, GLenum type, GLboolean is_shader)
    {
        GLuint _compiled_shader = glCreateShader(type);
        glShaderSource(_compiled_shader, 1, &shader_path, nullptr);
        glCompileShader(_compiled_shader);
        compileCheck(_compiled_shader, is_shader);
        return _compiled_shader;
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

    void Shader::use() { glUseProgram(_program); }
    
    void Shader::setUniform(const char *name, glm::mat4 &matrix)
    {
        GLint _location = glGetUniformLocation(_program, name);
        
        if(_location == -1)
        {
            Log::error((std::string("Uniform not found: ") + name).c_str());
            return;
        }
        
        glUniformMatrix4fv(_location, 1, GL_FALSE, glm::value_ptr(matrix));
        
    }
} // namespace Elenore::Graphics