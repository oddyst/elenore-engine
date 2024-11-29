// Author: oknauta
// License:
// File: mesh3d.cpp
// Date: 2024-11-28

#include "elenore/core/mesh3d.hpp"
#include "elenore/core/log.hpp"

namespace Elenore::Graphics
{
    Mesh3D::Mesh3D(std::vector<GLfloat> vertices, std::vector<GLuint> indices, Shader &shader)
        : _vertices(vertices), _indices(indices), _shader(shader)
    {
        _vao = std::make_unique<VAO>();
        _vbo = std::make_unique<VBO>(_vertices);
        _ebo = std::make_unique<EBO>(_indices);

        _vao->bind();
        _vbo->bind();
        _ebo->bind();

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void *)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void *)(3 * sizeof(GLfloat)));
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        _vao->unbind();
        _vbo->unbind();
        _ebo->unbind();
        Log::info("Created mesh");
    }

    Shader &Mesh3D::getShader() const { return _shader; }
    
    GLuint Mesh3D::getVAO() const { return _vao->getData(); }
    GLuint Mesh3D::getVBO() const { return _vbo->getData(); }
    GLuint Mesh3D::getEBO() const { return _ebo->getData(); };

    std::vector<GLfloat> Mesh3D::getVertices() const { return _vertices; }
    std::vector<GLuint> Mesh3D::getIndices() const { return _indices; };
} // namespace Elenore::Graphics