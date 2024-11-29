// Author: oknauta
// License:
// File: entity.cpp
// Date: 2024-11-28

#include "elenore/entity.hpp"
#include <glm/ext.hpp>

namespace Elenore::Entity
{
    void Entity3D::setPosition(glm::vec3 position) { _position = position; }
    void Entity3D::setRotation(glm::vec3 rotation) { _rotation = rotation; }
    void Entity3D::setScale(glm::vec3 scale) { _scale = scale; }

    glm::mat4 Entity3D::getModel() const
    {
        glm::mat4 model = glm::mat4(1.0f);

        model = glm::translate(model, _position);
        model = glm::rotate(model, glm::radians(_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, glm::radians(_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, _scale);

        return model;
    }
} // namespace Elenore::Entity