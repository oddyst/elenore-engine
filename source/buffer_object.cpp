// Author: oknauta
// License: 
// File: buffer_object.cpp
// Date: 2024-11-23

#include <buffer_object.hpp>

namespace Buffer
{
    VBO::VBO(std::vector<GLfloat>vertices)
    {
        glGenBuffers(1, &_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, _vbo);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(GLfloat), vertices.data(), GL_STATIC_DRAW);
    }
    
    
    VAO::VAO()
    {
        glGenVertexArrays(1, &_vao);
    }
    
    EBO::EBO(std::vector<GLuint>indices)
    {
        glGenBuffers(1, &_ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint), indices.data(), GL_STATIC_DRAW);
    }
    
    VAO::~VAO()
    {
        glDeleteVertexArrays(1, &_vao);
    }
    
    VBO::~VBO()
    {
        glDeleteBuffers(1, &_vbo);
    }
    
    EBO::~EBO()
    {
        glDeleteBuffers(1, &_ebo);
    }
} // Elenore