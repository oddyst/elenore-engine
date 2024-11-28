// Author: oknauta
// License:
// File: object3d.hpp
// Date: 2024-11-27

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "entity3d.hpp"
#include "mesh3d.hpp"
#include <string>

namespace Elenore::Entity
{

    class Object3D : public Entity3D
    {
    public:
        Object3D(std::shared_ptr<Graphics::Mesh3D> mesh, std::string name, glm::vec3 initial_position = glm::vec3(0.0f, 0.0f, 0.0f));
        void draw();
        glm::mat4 getModelMatrix();

    private:
        std::string _name;
        std::shared_ptr<Graphics::Mesh3D> _mesh;
    };

} // namespace Elenore::Entity

#endif // OBJECT_HPP