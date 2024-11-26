// Author: oknauta
// License:
// File: camera.cpp
// Date: 2024-11-25

#include <camera.hpp>
#include <glm/ext.hpp>
#include <logger.hpp>

namespace Elenore::Entity
{
    Camera3D::Camera3D(glm::vec3 position, float fov, float aspect_ratio, float near_plane, float far_plane, glm::vec3 target, glm::vec3 up_vector)
        : _position(position), _target(target), _up_vector(up_vector)
    {
        Log::info("Starting camera...");

        _projection = glm::perspective(glm::radians(fov), aspect_ratio, near_plane, far_plane);
        updateView();
    }
    void Camera3D::setPosition(glm::vec3 &position)
    {
        _position = position;
        updateView();
    }
    void Camera3D::setRotation(glm::vec3 &rotation)
    {
        _rotation = rotation;
        updateView();
    }
    void Camera3D::updateView()
    {
        _view = glm::lookAt(_position, _target, _up_vector);
    }
} // namespace Elenore::Entity