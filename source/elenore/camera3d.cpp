// Author: oknauta
// License:
// File: camera.cpp
// Date: 2024-11-27

#include "elenore/camera3d.hpp"
#include "elenore/log.hpp"
#include <glm/ext.hpp>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

namespace Elenore::Entity
{
    Camera3D::Camera3D(const char *name, float fov, const glm::vec3 &position)
        : _fov(fov), _near(0.1f), _far(100.0f),
          _target(glm::vec3(0.0f, 0.0f, 0.0f)),
          _up(glm::vec3(0.0f, 1.0f, 0.0f))
    {
        _name = name;
        _position = position;
        _direction = glm::normalize(_position - _target);

        _right = glm::normalize(glm::cross(_up, _direction));
        _up = glm::cross(_direction, _right);

        updateViewMatrix();

        _projection = glm::perspective(glm::radians(_fov), 800.0f / 600.0f, _near, _far);

        Log::info("Camera in scene: " + std::string(_name));
        Log::info("Camera up: " + glm::to_string(_up));
        Log::info("Camera right: " + glm::to_string(_right));
        Log::info("Camera FOV: " + std::to_string(_fov));
    }

    glm::mat4 Camera3D::getView() const
    {
        return _view;
    }
    glm::mat4 Camera3D::getProjection() const
    {
        return _projection;
    }
    void Camera3D::updateViewMatrix()
    {
        _view = glm::lookAt(_position, _target, _up);
    }
} // namespace Elenore::Entity
