// Author: oknauta
// License: 
// File: object.hpp
// Date: 2024-11-23

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext.hpp>

#include <mesh.hpp>

namespace Elenore
{
    class Object
    {
    public:
        Object(std::shared_ptr<Mesh>mesh, std::string object_name, glm::vec3 position);
        void draw();
        void setPosition(glm::vec3 position);
        void setRotation(glm::vec3 rotation);
        void setScale(glm::vec3 scale);
    private:
        // Mesh *_mesh;
        glm::mat4 getModelMatrix();
        std::shared_ptr<Mesh>_mesh;
        glm::vec3 _position, _scale, _rotation;
        std::string _name;
    };
} // Elenore

#endif // OBJECT_HPP