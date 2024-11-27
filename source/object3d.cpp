// Author: oknauta
// License:
// File: object3d.cpp
// Date: 2024-11-27

#include <GL/glew.h>
#include <glm/ext.hpp>

#include <elenore/log.hpp>
#include <elenore/object3d.hpp>

namespace Elenore::Entity
{
    Object3D::Object3D(std::shared_ptr<Graphics::Mesh3D> mesh, std::string name, glm::vec3 initial_position)
        : _mesh(mesh), _name(name), _position(initial_position), _rotation(glm::vec3(0.0f, 0.0f, 0.0f)), _scale(glm::vec3(1.0f, 1.0f, 1.0f))
    {
        Log::info("Object in scene: " + _name);
    }

    void Object3D::draw()
    {
        if (!_mesh)
        {
            Log::error("Failed to load mesh.");
            return;
        }

        _mesh->getShader().use();

        glm::mat4 model = getModelMatrix();

        _mesh->getShader().setUniform("model", model);

        Graphics::Object::drawElements(_mesh->getVAO(), _mesh->getIndices());
    }

    void Object3D::setPosition(glm::vec3 position)
    {
        _position = position;
    }

    void Object3D::setRotation(glm::vec3 rotation)
    {
        _rotation = rotation;
    }

    void Object3D::setScale(glm::vec3 scale)
    {
        _scale = scale;
    }

    glm::mat4 Object3D::getModelMatrix()
    {
        glm::mat4 model = glm::mat4(1.0f);

        model = glm::translate(model, _position);
        model = glm::rotate(model, glm::radians(_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, glm::radians(_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, _scale);

        return model;
    }
} // namespace Elenore::Entity