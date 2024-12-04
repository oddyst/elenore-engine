// Author: oknauta
// License:
// File: mesh3d.hpp
// Date: 2024-12-02

#ifndef ELN_MESH_3D
#define ELN_MESH_3D

#include "buffer_object.hpp"
#include <memory>
#include <vector>

namespace Elenore::Graphics
{
    class Mesh3D
    {
    public:
        Mesh3D(std::vector<GLfloat> vertices, std::vector<GLuint> indices);
        void draw();
    private:
        std::unique_ptr<VAO> _vao;
        std::unique_ptr<VBO> _vbo;
        std::unique_ptr<EBO> _ebo;
        std::vector<GLuint> _indices;
        std::vector<GLfloat> _vertices;
    };
} // namespace Elenore::Graphics

#endif // ELN_MESH_3D