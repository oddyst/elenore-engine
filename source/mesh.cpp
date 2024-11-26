// Author: oknauta
// License:
// File: mesh.cpp
// Date: 2024-11-23

#include <mesh.hpp>

namespace Elenore::Graphics
{
    Mesh::Mesh(Data::vertex &vertices, Data::index &indices, Shader &shader)
        : _vertices(vertices), _indices(indices), _shader(shader)
    {

        _vbo = std::make_unique<Buffer::VBO>(_vertices);
        _vao = std::make_unique<Buffer::VAO>();
        _ebo = std::make_unique<Buffer::EBO>(_indices);

        // _vao = new VAO();
        // _vbo = new VBO(_vertices); // This makes memory leak. As a good practice, get away from that.
        // _ebo = new EBO(_indices);

        _vbo->bind();
        _vao->bind();
        _ebo->bind();

        // glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
        // glEnableVertexAttribArray(0);

        Buffer::setupVertexAttrib(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);                   // Posição
        Buffer::setupVertexAttrib(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)(3 * sizeof(float))); // Cor

        _vao->unbind();
        _vbo->unbind();
        _ebo->unbind();
    }
} // Elenore::Graphics