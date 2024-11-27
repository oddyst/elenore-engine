// Author: oknauta
// License:
// File: mesh.hpp
// Date: 2024-11-26

#ifndef MESH_HPP
#define MESH_HPP

#include <elenore/buffer_object.hpp>
#include <elenore/shader.hpp>
#include <memory>

namespace Elenore::Graphics
{
    class Mesh3D
    {
    public:
        Mesh3D(std::vector<GLfloat> &vertices, std::vector<GLuint> &indices, Shader &shader);
        std::vector<GLfloat> getVertices() const;
        std::vector<GLuint> getIndices() const;
        GLuint getVBO() const;
        GLuint getEBO() const;
        GLuint getVAO() const;
        Shader getShader() const;

    private:
        Shader _shader;
        std::vector<GLfloat> _vertices;
        std::vector<GLuint> _indices;
        std::unique_ptr<Object::VBO> _vbo;
        std::unique_ptr<Object::EBO> _ebo;
        std::unique_ptr<Object::VAO> _vao;
    };
} // namespace Elenore::Graphics

#endif // MESH_HPP