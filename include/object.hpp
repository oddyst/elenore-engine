// Author: oknauta
// License: 
// File: object.hpp
// Date: 2024-11-23

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <mesh.hpp>

namespace Elenore
{
    class Object
    {
    private:
        Mesh *_mesh;
        const char *_name;
    public:
        Object(Mesh *mesh, const char *object_name);
        void draw();
    };
} // Elenore

#endif // OBJECT_HPP