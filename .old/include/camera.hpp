// Author: oknauta
// License:
// File: camera.hpp
// Date: 2024-11-25

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/mat4x4.hpp>

namespace Elenore::Entity
{
    class Camera3D
    {
    public:
        Camera3D(glm::vec3 position, float fov, float aspect_ratio, float near_plane, float far_plane, glm::vec3 target, glm::vec3 up_vector = glm::vec3(0.0f, 1.0f, 0.0f));
        glm::mat4 getProjectionMatrix() { return _projection; }
        glm::vec3 getPosition() { return _position; }
        glm::vec3 getUpVector() { return _up_vector; }
        glm::mat4 getViewMatrix() { return _view; }
        
        void setPosition(glm::vec3 &position);
        void setRotation(glm::vec3 &rotation);
        
        void updateView();

    private:
        glm::mat4 _projection;
        glm::mat4 _view;
        glm::vec3 _position;
        glm::vec3 _rotation;
        glm::vec3 _up_vector;
        glm::vec3 _target;
    };

    class Camera2D
    {
    };
} // Elenore::Entity

#endif // CAMERA_HPP