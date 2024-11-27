// Author: oknauta
// License:
// File: mesh.cpp
// Date: 2024-11-26

#include <elenore/log.hpp>
#include <elenore/mesh.hpp>

namespace Elenore::Graphics
{
    Mesh3D::Mesh3D(std::vector<GLfloat> &vertices, std::vector<GLuint> &indices, Shader &shader)
        : _vertices(vertices), _indices(indices), _shader(shader)
    {
        Log::info("Creating mesh...");

        _vao = std::make_unique<Object::VAO>();
        _vbo = std::make_unique<Object::VBO>(_vertices);
        _ebo = std::make_unique<Object::EBO>(_indices);

        _vao->bind();
        _vbo->bind();
        _ebo->bind();

        Object::setupVertexAttrib(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void *)0);
        Object::setupVertexAttrib(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void *)(3 * sizeof(GLfloat)));

        _vao->unbind();
        _vbo->unbind();
        _ebo->unbind();
    }

    std::vector<GLfloat> Mesh3D::getVertices() const
    {
        return _vertices;
    }
    std::vector<GLuint> Mesh3D::getIndices() const
    {
        return _indices;
    }
    GLuint Mesh3D::getVBO() const
    {
        return _vbo->getID();
    }
    GLuint Mesh3D::getEBO() const
    {
        return _ebo->getID();
    }
    GLuint Mesh3D::getVAO() const
    {
        return _vao->getID();
    }

    Shader Mesh3D::getShader() const
    {
        return _shader;
    }
} // namespace Elenore::Graphics