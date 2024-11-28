// Author: oknauta
// License:
// File: entity.cpp
// Date: 2024-11-27

#include "elenore/entity3d.hpp"

namespace Elenore::Entity
{
    void Entity3D::setPosition(glm::vec3 position) { _position = position; }
    void Entity3D::setRotation(glm::vec3 rotation) { _rotation = rotation; }
    void Entity3D::setScale(glm::vec3 scale) { _scale = scale; }
} // namespace Elenore::Entity