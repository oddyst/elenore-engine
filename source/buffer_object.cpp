// Author: oknauta
// License:
// File: buffer_object.cpp
// Date: 2024-11-23

#include <buffer_object.hpp>
#include <logger.hpp>

namespace Elenore::Buffer
{
    VBO::VBO(std::vector<GLfloat> &vertexData)
    {
        glGenBuffers(1, &_data);
        glBindBuffer(GL_ARRAY_BUFFER, _data);
        glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(GLfloat), vertexData.data(), GL_STATIC_DRAW);
    }

    VAO::VAO()
    {
        glGenVertexArrays(1, &_data);
    }

    EBO::EBO(std::vector<GLuint> &indexData)
    {
        glGenBuffers(1, &_data);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _data);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indexData.size() * sizeof(GLuint), indexData.data(), GL_STATIC_DRAW);
    }

    VAO::~VAO()
    {
        glDeleteVertexArrays(1, &_data);
    }

    VBO::~VBO()
    {
        glDeleteBuffers(1, &_data);
    }

    EBO::~EBO()
    {
        glDeleteBuffers(1, &_data);
    }

    void drawElements(GLuint vao, std::vector<GLuint> indices)
    {
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

    void setupVertexAttrib(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)
    {
        glVertexAttribPointer(index, size, type, normalized, stride, pointer);
        glEnableVertexAttribArray(index);
    }

} // Elenore::Buffer