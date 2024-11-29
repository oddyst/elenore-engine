// Author: oknauta
// License:
// File: entity.hpp
// Date: 2024-11-28

#ifndef ELN_ENTITY_HPP
#define ELN_ENTITY_HPP

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>

namespace Elenore::Entity
{
    class Entity3D
    {
    public:
        void setPosition(glm::vec3 position);
        void setRotation(glm::vec3 rotation);
        void setScale(glm::vec3 scale);
        glm::mat4 getModel() const;
    protected:
        glm::mat4 _model;
        glm::vec3 _position;
        glm::vec3 _rotation;
        glm::vec3 _scale;
    };
} // namespace Entity

#endif // ELN_ENTITY_HPP