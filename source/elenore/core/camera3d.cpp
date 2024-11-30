// Author: oknauta
// License:
// File: camera3d.cpp
// Date: 2024-11-30

#include "elenore/core/camera3d.hpp"
#include <glm/ext.hpp>

namespace Elenore::Entity
{
    Camera3D::Camera3D(glm::vec3 target)
        : _target(target)
    {
        // _forward = glm::normalize(_position - target);
    }

    glm::mat4 Camera3D::lookAt()
    {
        // return glm::lookAt(_position, _forward)
    }
} // namespace Elenore::Entity