// Author: oknauta
// License:
// File: scene.hpp
// Date: 2024-11-30

#ifndef ELN_SCENE_HPP
#define ELN_SCENE_HPP

#include "entity.hpp"
#include "object3d.hpp"
#include <vector>
#include "camera3d.hpp"

namespace Elenore::Entity
{
    class Scene3D : Entity3D
    {
    public:
        Scene3D(Camera3D camera, std::vector<Object3D> objects);
    private:
        std::vector<Object3D> _objects;
        Camera3D _camera;
    };
} // namespace Elenore::Entity

#endif // ELN_SCENE_HPP