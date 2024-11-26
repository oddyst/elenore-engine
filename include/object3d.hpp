// Author: oknauta
// License:
// File: object3d.hpp
// Date: 2024-11-23

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext.hpp>

#include <mesh.hpp>

namespace Elenore::Entity
{
    class Object3D
    {
    public:
        /**
         * @brief Creates an object.
         * @param mesh The object's mesh.
         * @param object_name The object's name.
         * @param position The object's location.
         */
        Object3D(std::shared_ptr<Graphics::Mesh> mesh, std::string name, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f));
        void draw();
        /// @brief Sets a new position.
        void setPosition(glm::vec3 position);
        /// @brief Sets a new rotation.
        void setRotation(glm::vec3 rotation);
        /// @brief Sets a new scale.
        void setScale(glm::vec3 scale);

    private:
        // Mesh *_mesh;
        glm::mat4 getModelMatrix();
        std::shared_ptr<Graphics::Mesh> _mesh;
        glm::vec3 _position, _scale, _rotation;
        std::string _name;
    };

} // Elenore::Entity

#endif // OBJECT_HPP