// Author: oknauta
// License:
// File: mesh.cpp
// Date: 2024-11-23

#include <mesh.hpp>

namespace Elenore
{
Mesh::Mesh(std::vector<GLfloat> vertices, std::vector<GLuint> indices, Shader &shader)
    : _vertices(vertices), _indices(indices), _shader(shader)
{

    _vao = std::make_unique<Buffer::VAO>();
    _vbo = std::make_unique<Buffer::VBO>(_vertices);
    _ebo = std::make_unique<Buffer::EBO>(_indices);

    // _vao = new VAO();
    // _vbo = new VBO(_vertices); // This makes memory leak. As a good practice, get away from that.
    // _ebo = new EBO(_indices);

    _vao->bind();
    _vbo->bind();
    _ebo->bind();

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
    glEnableVertexAttribArray(0);

    _vao->unbind();
    _vbo->unbind();
    _ebo->unbind();
}
} // namespace Elenore