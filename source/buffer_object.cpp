// Author: oknauta
// License:
// File: buffer_object.cpp
// Date: 2024-11-23

#include <buffer_object.hpp>

namespace Buffer
{
    VBO::VBO(std::vector<GLfloat> &vertexData)
    {
        glGenBuffers(1, &_vbo);
        glBindBuffer(GL_ARRAY_BUFFER, _vbo);
        glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(GLfloat), vertexData.data(), GL_STATIC_DRAW);
    }

    VAO::VAO()
    {
        glGenVertexArrays(1, &_vao);
    }

    EBO::EBO(std::vector<GLuint> &indexData)
    {
        glGenBuffers(1, &_ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexData.size() * sizeof(GLuint), indexData.data(), GL_STATIC_DRAW);
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
} // namespace Buffer