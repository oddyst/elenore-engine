// Author: oknauta
// License:
// File: mesh3d.hpp
// Date: 2024-11-28

#ifndef ELN_MESH_HPP
#define ELN_MESH_HPP

#include "buffer_object.hpp"
#include "shader.hpp"

#include <memory>

namespace Elenore::Graphics
{
    class Mesh3D
    {
    public:
        Mesh3D(std::vector<GLfloat> vertices, std::vector<GLuint> indices, Shader &shader);
        GLuint getVAO() const;
        GLuint getVBO() const;
        GLuint getEBO() const;
        
        Shader &getShader() const;
        std::vector<GLfloat> getVertices() const;
        std::vector<GLuint> getIndices() const;

    private:
        Shader &_shader;

        std::unique_ptr<VAO> _vao;
        std::unique_ptr<VBO> _vbo;
        std::unique_ptr<EBO> _ebo;

        std::vector<GLfloat> _vertices;
        std::vector<GLuint> _indices;
    };
} // namespace Elenore::Graphics

#endif // ELN_MESH_HPP