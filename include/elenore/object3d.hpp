// Author: oknauta
// License:
// File: object3d.hpp
// Date: 2024-11-27

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <elenore/mesh.hpp>
#include <glm/matrix.hpp>
#include <glm/vec3.hpp>
#include <string>

namespace Elenore::Entity
{

    class Object3D
    {
    public:
        Object3D(std::shared_ptr<Graphics::Mesh3D> mesh, std::string name, glm::vec3 initial_position = glm::vec3(0.0f, 0.0f, 0.0f));
        void draw();
        void setPosition(glm::vec3 position);
        void setRotation(glm::vec3 rotation);
        void setScale(glm::vec3 scale);
        glm::mat4 getModelMatrix();

    private:
        std::string _name;
        glm::vec3 _position;
        glm::vec3 _rotation;
        glm::vec3 _scale;
        std::shared_ptr<Graphics::Mesh3D> _mesh;
    };

} // namespace Elenore::Entity

#endif // OBJECT_HPP