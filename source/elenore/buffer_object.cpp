// Author: oknauta
// License:
// File: buffer_object.cpp
// Date: 2024-12-02

#include <GL/glew.h>

#include "elenore/buffer_object.hpp"
#include "elenore/logger.hpp"

namespace Elenore::Graphics
{
    GLuint BufferObject::getData() const { return _data; }

    BufferObject::~BufferObject() {}
    
    /* VAO */
    
    VAO::VAO()
    {
        glGenVertexArrays(1, &_data);
        Log::info("VAO generated");
    }

    void VAO::bind() const { glBindVertexArray(_data); }

    void VAO::unbind() const { glBindVertexArray(0); }

    VAO::~VAO()
    {
        glDeleteVertexArrays(1, &_data);
        Log::info("VAO deleted");
    }
    
    /* VBO */
    
    VBO::VBO(std::vector<GLfloat> vertices)
        : _vertices(std::move(vertices))
    {
        glGenBuffers(1, &_data);
        Log::info("VBO generated");
    }

    void VBO::bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, _data);
        glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(GLfloat), _vertices.data(), GL_STATIC_DRAW);
    }

    void VBO::unbind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }

    VBO::~VBO()
    {
        glDeleteBuffers(1, &_data);
        Log::info("VBO deleted");
    }
    
    /* EBO */

    EBO::EBO(std::vector<GLuint> indices)
        : _indices(std::move(indices))
    {
        Log::info("EBO generated");
        glGenBuffers(1, &_data);
    }

    void EBO::bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _data);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(GLuint), _indices.data(), GL_STATIC_DRAW);
    }

    void EBO::unbind() const { glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0); }

    EBO::~EBO()
    {
        glDeleteBuffers(1, &_data);
        Log::info("EBO deleted");
    }

} // namespace Elenore::Graphics