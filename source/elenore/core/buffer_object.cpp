// Author: oknauta
// License:
// File: buffer_object.cpp
// Date: 2024-11-28

#include "elenore/core/buffer_object.hpp"
#include "elenore/core/log.hpp"

namespace Elenore::Graphics
{
    void BufferObject::bind() const {}
    void BufferObject::unbind() const {}
    GLuint BufferObject::getData() const { return _data; }

    // VAO

    VAO::VAO()
    {
        glGenVertexArrays(1, &_data);
        Log::info("Generated VAO");
    }
    void VAO::bind() const { glBindVertexArray(_data); }
    void VAO::unbind() const { glBindVertexArray(0); }
    VAO::~VAO()
    {
        Log::info("Destroyed VAO");
        glDeleteVertexArrays(1, &_data);
    }

    // VBO

    VBO::VBO(std::vector<GLfloat> vertices) : _vertices(vertices)
    {
        glGenBuffers(1, &_data);
        Log::info("Generated VBO");
    }
    void VBO::bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, _data);
        glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(GLfloat), _vertices.data(), GL_STATIC_DRAW);
    }
    void VBO::unbind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
    VBO::~VBO()
    {
        Log::info("Destroyed VBO");
        glDeleteBuffers(1, &_data);
    }

    // EBO

    EBO::EBO(std::vector<GLuint> indices) : _indices(indices)
    {
        glGenBuffers(1, &_data);
        Log::info("Generated EBO");
    }
    void EBO::bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _data);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(GLuint), _indices.data(), GL_STATIC_DRAW);
    }
    void EBO::unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }
    EBO::~EBO()
    {
        Log::info("Destroyed EBO");
        glDeleteBuffers(1, &_data);
    }

    BufferObject::BufferObject() {}
    BufferObject::~BufferObject() {}
} // namespace Elenore::Graphics