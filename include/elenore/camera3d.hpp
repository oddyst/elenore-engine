// Author: oknauta
// License:
// File: camera.hpp
// Date: 2024-11-27

#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "entity3d.hpp"

namespace Elenore::Entity
{
    class Camera3D : public Entity3D
    {
    public:
        Camera3D(const char *name, float fov, const glm::vec3 &position = glm::vec3(0.0f, 0.0f, 0.0f));
        glm::mat4 getView() const;
        glm::mat4 getProjection() const;
        void updateViewMatrix();

    private:
        glm::vec3 _target, _direction;
        glm::vec3 _up, _right;
        glm::mat4 _view, _projection;
        float _fov;
        float _near, _far;
    };
} // namespace Elenore::Entity

#endif // CAMERA_HPP