// Author: oknauta
// License: 
// File: shader.cpp
// Date: 2024-11-23

#include <shader.hpp>

namespace Elenore
{
    
    Shader::Shader(const char *source_vertex_shader, const char *source_fragment_shader) : _source_vertex_shader(source_vertex_shader), _source_fragment_shader(source_fragment_shader)
    {
        compileShader(GL_VERTEX_SHADER, _vertex_shader, source_vertex_shader, GL_TRUE);
        compileShader(GL_FRAGMENT_SHADER, _fragment_shader, source_fragment_shader, GL_TRUE);
        
        // _vertex_shader = glCreateShader(GL_VERTEX_SHADER);
        // _fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
        
        // glShaderSource(_vertex_shader, 1, &_source_vertex_shader, nullptr);
        // glCompileShader(_vertex_shader);
        // checkShaderCompile(_vertex_shader, true);
        
        // glShaderSource(_fragment_shader, 1, &_source_fragment_shader, nullptr);
        // glCompileShader(_fragment_shader);
        // checkShaderCompile(_fragment_shader, true);
        
        _program_id = glCreateProgram();
        glAttachShader(_program_id, _vertex_shader);
        glAttachShader(_program_id, _fragment_shader);
        glLinkProgram(_program_id);
        checkShaderCompile(_program_id, false);
    }
    
    void Shader::compileShader(GLenum shader_type, GLuint shader, const char *shader_source, GLboolean is_shader)
    {
        std::cout << "Compiling shader...\n";
        
        shader = glCreateShader(shader_type);
        
        glShaderSource(shader, 1, &shader_source, nullptr);
        glCompileShader(shader);
        checkShaderCompile(shader, is_shader);
    }
    
    void Shader::checkShaderCompile(GLuint program_id, bool is_shader)
    {
        GLint success;
        GLchar info[1024];
        
        if(is_shader)
        {
            glGetShaderiv(program_id, GL_COMPILE_STATUS, &success);
            if(!success)
            {
                glGetShaderInfoLog(program_id, sizeof(info), nullptr, info);
                
                std::cerr << "Error while compiling shader. -> " << (is_shader ? "SHADER" : "PROGRAM") << "\n" << info;
            }
            else
            {
                std::cout << "Successfuly shader compiling.\n";
            }
        }
        else
        {
            glGetProgramiv(program_id, GL_LINK_STATUS, &success);
            if(!success)
            {
                glGetShaderInfoLog(program_id, sizeof(info), nullptr, info);
                std::cerr << "Error linking shader.\n" << info;
            }
            else
            {
                std::cout << "Successfuly shader linking.\n";
            }
        }
    }
    
    Shader::~Shader()
    {
        glDeleteShader(_fragment_shader);
        glDeleteShader(_vertex_shader);
        glDeleteProgram(_program_id);
        
    }
} // Elenore