// Author: oknauta
// License:
// File: mesh.hpp
// Date: 2024-11-23

#ifndef MESH_HPP
#define MESH_HPP

#include <iostream>
#include <memory>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <buffer_object.hpp>
#include <shader.hpp>

namespace Elenore::Data
{
    typedef std::vector<GLfloat> vertex;
    typedef std::vector<GLuint> index;
};

namespace Elenore::Graphics
{

    class Mesh
    {
    public:
        /**
         * @brief Creates a mesh for objects.
         * @param vertices The mesh vertices that will be storaged
         * @param indices The mesh indices that will be storaged
         */
        Mesh(Data::vertex &vertices, Data::index &indices, Shader &shader);
        Shader &getShader()
        {
            return _shader;
        }
        std::vector<GLfloat> getVertices() const
        {
            return this->_vertices;
        };
        std::vector<GLuint> getIndices() const
        {
            return this->_indices;
        };
        GLuint getVAO() const
        {
            return _vao->get();
        }

    private:
        std::unique_ptr<Buffer::VAO> _vao;
        std::unique_ptr<Buffer::EBO> _ebo;
        std::unique_ptr<Buffer::VBO> _vbo;

        // VAO *_vao;
        // VBO *_vbo;
        // EBO *_ebo;

        std::vector<GLuint> _indices;
        std::vector<GLfloat> _vertices;
        Shader _shader;
    };
} // Elenore::Graphics

#endif // MESH_HPP