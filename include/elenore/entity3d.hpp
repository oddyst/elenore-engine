// Author: oknauta
// License:
// File: entity.hpp
// Date: 2024-11-27

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <glm/vec3.hpp>
#include <glm/matrix.hpp>

namespace Elenore::Entity
{
    class Entity3D
    {
    public:
        void setPosition(glm::vec3 position);
        void setRotation(glm::vec3 rotation);
        void setScale(glm::vec3 scale);

    protected:
        glm::vec3 _position;
        glm::vec3 _rotation;
        glm::vec3 _scale;
        const char *_name;
    };
} // namespace Elenore::Entity

#endif // ENTITY_HPP