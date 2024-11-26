// Author: oknauta
// License:
// File: scene.hpp
// Date: 2024-11-25

#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>
#include <vector>

#include <camera.hpp>
#include <object2d.hpp>
#include <object3d.hpp>

namespace Elenore::Core
{
        class Scene3D
        {
        public:
        private:
            std::vector<std::shared_ptr<Entity::Object3D>> _objects;
            std::shared_ptr<Entity::Camera3D> _active_camera;
        };

        class Scene2D
        {
        private:
            std::vector<std::shared_ptr<Entity::Object2D>> _objects;
            std::shared_ptr<Entity::Camera2D> _active_camera;
        };
} // Elenore::Core

#endif // SCENE_HPP