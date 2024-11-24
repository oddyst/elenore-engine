// Author: oknauta
// License: 
// File: mesh.hpp
// Date: 2024-11-23

#ifndef MESH_HPP
#define MESH_HPP

#include <iostream>
#include <vector>
#include <memory>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <shader.hpp>
#include <buffer_object.hpp>

namespace Elenore
{
    class Mesh
    {
    public:
        /**
         * @brief Creates a mesh for objects.
         * @param vertices The mesh vertices that will be storaged
         * @param indices The mesh indices that will be storaged
         */
        Mesh(std::vector<GLfloat> vertices, std::vector<GLuint> indices, Shader shader);
        Shader &getShader() { return _shader; }
        std::vector<GLfloat>getVertices() const { return this->_vertices; };
        std::vector<GLuint>getIndices() const { return this->_indices; };
        GLuint getVAO() const { return _vao->getVAO(); }
    private:
        std::unique_ptr<VAO> _vao;
        std::unique_ptr<EBO> _ebo;
        std::unique_ptr<VBO> _vbo;
        
        // VAO *_vao;
        // VBO *_vbo;
        // EBO *_ebo;
        
        std::vector<GLuint>_indices;
        std::vector<GLfloat>_vertices;
        Shader _shader;
    };
} // Elenore

#endif // MESH_HPP