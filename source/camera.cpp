// Author: oknauta
// License:
// File: camera.cpp
// Date: 2024-11-25

#include <camera.hpp>
#include <logger.hpp>

namespace Elenore
{

    Camera::Camera(glm::vec3 position, float fov, float aspect_ratio, float near_plane, float far_plane, glm::vec3 target,
                   glm::vec3 up_vector)
        : _position(position), _target(target), _up_vector(up_vector)
    {
        Log::info("Starting camera...");

        _projection = glm::perspective(glm::radians(fov), aspect_ratio, near_plane, far_plane);
        _view = glm::lookAt(_position, _target, _up_vector);
    }

} // namespace Elenore