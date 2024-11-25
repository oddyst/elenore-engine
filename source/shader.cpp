// Author: oknauta
// License: 
// File: shader.cpp
// Date: 2024-11-23

#include <shader.hpp>
#include <logger.hpp>

namespace Elenore
{
    Shader::Shader(const char *vertex_path, const char *fragment_path)
    {
        GLuint vertex_shader = compileShader(GL_VERTEX_SHADER, vertex_path);
        GLuint fragment_shader = compileShader(GL_FRAGMENT_SHADER, fragment_path);
        
        // compileShader(GL_VERTEX_SHADER, vertex_shader, vertex_path, GL_TRUE);
        // compileShader(GL_FRAGMENT_SHADER, fragment_shader, fragment_path, GL_TRUE);
        
        _program_id = glCreateProgram();
        glAttachShader(_program_id, vertex_shader);
        glAttachShader(_program_id, fragment_shader);
        glLinkProgram(_program_id);
        compileCheck(_program_id, GL_FALSE);
    }
    
    void Shader::setUniformMatrix4fv(const char *name, const glm::mat4 &matrix)
    {
        _location = glGetUniformLocation(_program_id, name);
        glUniformMatrix4fv(_location, 1, GL_FALSE, glm::value_ptr(matrix));
    }
    
    GLuint Shader::compileShader(GLenum shader_type, const char *shader_source)
    {
        if(shader_type == GL_VERTEX_SHADER)
        {
            // std::cout << "Compiling vertex shader...\n";
            Logger::log("Compiling vertex shader...");
            
        }
        else if(shader_type == GL_FRAGMENT_SHADER)
        {
            // std::cout << "Compiling fragment shader...\n";
            Logger::log("Compiling fragment shader...");
        }
        
        GLuint shader = glCreateShader(shader_type);
        glShaderSource(shader, 1, &shader_source, nullptr);
        glCompileShader(shader);
        
        compileCheck(shader, GL_TRUE);
        return shader;
    }
    
    
    void Shader::compileCheck(GLuint program, GLboolean is_shader)
    {
        GLint success;
        GLchar log[1024];
        
        if(is_shader)
        {
            glGetShaderiv(program, GL_COMPILE_STATUS, &success);
            if(!success)
            {
                glGetShaderInfoLog(program, sizeof(log), nullptr, log);
                // std::cerr << "Error compiling shader.\n" << log;
                Logger::error(log);
            }
        }
        else
        {
            glGetProgramiv(program, GL_LINK_STATUS, &success);
            if(!success)
            {
                glGetShaderInfoLog(program, sizeof(log), nullptr, log);
                // std::cerr << "Error linking shader.\n" << log;
                Logger::error(log);
            }
        }
    }
} // Elenore