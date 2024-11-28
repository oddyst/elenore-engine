// Author: oknauta
// License:
// File: buffer_object.cpp
// Date: 2024-11-26

#include "elenore/buffer_object.hpp"

namespace Elenore::Graphics::Object
{
    GLuint BufferObject::getID()
    {
        return _data;
    }

    VAO::VAO()
    {
        glGenVertexArrays(1, &_data);
    }

    void VAO::bind()
    {
        glBindVertexArray(_data);
    }

    void VAO::unbind() const
    {
        glBindVertexArray(0);
    }

    VBO::VBO(std::vector<GLfloat> &vertices) : _vertices(vertices)
    {
        glGenBuffers(1, &_data);
    }

    void VBO::bind()
    {
        glBindBuffer(GL_ARRAY_BUFFER, _data);
        glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(GLfloat), _vertices.data(), GL_STATIC_DRAW);
    }

    void VBO::unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    EBO::EBO(std::vector<GLuint> &indices) : _indices(indices)
    {
        glGenBuffers(1, &_data);
    }

    void EBO::bind()
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _data);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(GLuint), _indices.data(), GL_STATIC_DRAW);
    }

    void EBO::unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    void setupVertexAttrib(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *pointer)
    {
        glVertexAttribPointer(index, size, type, normalized, stride, pointer);
        glEnableVertexAttribArray(index);
    }

    void drawElements(GLuint vao, std::vector<GLuint> indices)
    {
        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }
} // namespace Elenore::Graphics::Object