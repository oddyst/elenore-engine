// Author: oknauta
// License: 
// File: object.hpp
// Date: 2024-11-23

#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/ext.hpp>

#include <mesh.hpp>

namespace Elenore
{
    class Object
    {
    public:
        /**
         * @brief Creates an object.
         * @param mesh The object's mesh.
         * @param object_name The object's name.
         * @param position The object's location.
         */
        Object(std::shared_ptr<Mesh>mesh, std::string object_name, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f));
        void draw(const glm::mat4& view, const glm::mat4& projection);
        /// @brief Sets a new position.
        void setPosition(glm::vec3 position);
        /// @brief Sets a new rotation.
        void setRotation(glm::vec3 rotation);
        /// @brief Sets a new scale.
        void setScale(glm::vec3 scale);
    private:
        // Mesh *_mesh;
        glm::mat4 getModelMatrix();
        std::shared_ptr<Mesh>_mesh;
        glm::vec3 _position, _scale, _rotation;
        std::string _name;
    };
} // Elenore

#endif // OBJECT_HPP