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
#include <glm/vec3.hpp>

#include <mesh.hpp>

namespace Elenore
{
    class Object
    {
    public:
        Object(Mesh *mesh, std::string object_name, glm::vec3 position);
        void draw();
    private:
        // Mesh *_mesh;
        std::shared_ptr<Mesh>_mesh;
        glm::vec3 _position;
        std::string _name;
    };
} // Elenore

#endif // OBJECT_HPP