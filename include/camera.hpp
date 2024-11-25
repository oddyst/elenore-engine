// Author: oknauta
// License:
// File: camera.hpp
// Date: 2024-11-25

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/ext.hpp>

namespace Elenore
{
    class Camera
    {
    public:
        Camera(glm::vec3 position, float fov, float aspect_ratio, float near_plane, float far_plane, glm::vec3 target, glm::vec3 up_vector = glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 getProjectionMatrix() { return _projection; }
        glm::vec3 getPosition() { return _position; }
        glm::vec3 getUpVector() { return _up_vector; }
        glm::mat4 getViewMatrix() { return _view; }

    private:
        glm::mat4 _projection;
        glm::mat4 _view;
        glm::vec3 _position;
        glm::vec3 _up_vector;
        glm::vec3 _target;
    };
} // Elenore

#endif // CAMERA_HPP