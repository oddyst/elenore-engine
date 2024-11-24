// Author: oknauta
// License: 
// File: object.cpp
// Date: 2024-11-23

#include <object.hpp>

namespace Elenore
{
    Object::Object(std::shared_ptr<Mesh>mesh, std::string object_name, glm::vec3 position)
    : _mesh(mesh), _name(object_name), _position(position)
    {
        std::cout << "Object in scene: " << _name << "\n";
        
        
    }
    
    void Object::draw()
    {
        // Use the program shader.
        glUseProgram(_mesh->getShader().getProgram());
        
        // Drawing the frame
        glBindVertexArray(_mesh->getVAO());
        glDrawElements(GL_TRIANGLES, _mesh->getIndices().size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

} // Elenore