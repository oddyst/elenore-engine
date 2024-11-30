// Author: oknauta
// License: 
// File: camera.hpp
// Date: 2024-11-30

#ifndef ELN_CAMERA_HPP
#define ELN_CAMERA_HPP

#include "entity.hpp"

namespace Elenore::Entity
{
    class Camera3D : Entity3D
    {
    public:
        Camera3D(glm::vec3 target);
        glm::mat4 lookAt();
    private:
        glm::vec3 _up, _right, _forward;
        glm::vec3 _target;
    };
    
    
} // Elenore::Entity

#endif // ELN_CAMERA_HPP