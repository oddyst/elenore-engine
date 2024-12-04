// Author: oknauta
// License:
// File: mesh3d.cpp
// Date: 2024-12-02

#include "GL/glew.h"

#include "elenore/logger.hpp"
#include "elenore/mesh3d.hpp"

namespace Elenore::Graphics
{
    Mesh3D::Mesh3D(std::vector<GLfloat> vertices, std::vector<GLuint> indices)
        : _vertices(std::move(vertices)), _indices(std::move(indices))
    {
        _vao = std::make_unique<VAO>();
        _vbo = std::make_unique<VBO>(_vertices);
        _ebo = std::make_unique<EBO>(_indices);

        _vao->bind();
        _vbo->bind();
        _ebo->bind();

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void *)0);
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void *)(3 * sizeof(float)));
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);

        _vao->unbind();
        _vbo->unbind();
        _ebo->unbind();

        Log::info("Mesh created");
    }

    void Mesh3D::draw()
    {
        _vao->bind();
        glDrawElements(GL_TRIANGLES, _indices.size(), GL_UNSIGNED_INT, 0);
        _vao->unbind();
    }
    
    
} // namespace Elenore::Graphics