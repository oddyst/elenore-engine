// Author: oknauta
// License: 
// File: object.cpp
// Date: 2024-11-23

#include <object.hpp>

namespace Elenore
{
    Object::Object(Mesh *mesh, const char *object_name) : _mesh(mesh), _name(object_name)
    {
        std::cout << "Object in scene: " << _name << "\n";
    }
    
    void Object::draw()
    {
        glUseProgram(_mesh->getShader().getProgram());
        glBindVertexArray(_mesh->getVAO());
        glDrawElements(GL_TRIANGLES, _mesh->getIndices().size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }
} // Elenore