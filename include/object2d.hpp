// Author: oknauta
// License:
// File: object2d.hpp
// Date: 2024-11-26

#ifndef OBJECT2D_HPP
#define OBJECT2D_HPP

#include <string>

#include <glm/vec2.hpp>

#include <mesh.hpp>

namespace Elenore::Entity
{
    class Object2D
    {
    public:
        Object2D(std::string name = "Untitled object", glm::vec3 color = glm::vec3(1.0f, 0.0f, 0.0f), glm::vec2 size = glm::vec2(1.0f, 1.0f));
        void draw();
        void setPosition(glm::vec2 position);
        void setRotation(glm::vec2 rotation);
        void setScale(glm::vec2 scale);

    private:
        std::string _name;
        glm::vec2 _size;
        glm::vec2 _scale, _position, _rotation;
    };
} // Elenore::Entity

#endif // OBJECT2D_HPP