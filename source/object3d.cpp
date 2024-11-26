// Author: oknauta
// License:
// File: object.cpp
// Date: 2024-11-23

#include <logger.hpp>
#include <object3d.hpp>

namespace Elenore::Entity
{
    Object3D::Object3D(std::shared_ptr<Graphics::Mesh> mesh, std::string object_name, glm::vec3 position)
        : _mesh(mesh), _name(object_name), _position(position), _rotation(0.0f, 0.0f, 0.0f), _scale(1.0f, 1.0f, 1.0f)
    {
        // std::cout << "Object in scene: " << _name << "\n";
        Log::info("Object in scene: " + _name);
    }

    void Object3D::draw()
    {
        if (!_mesh)
        {
            // std::cerr << "ERROR: mesh didn't initialized.\n";
            Log::error("Mesh didn't initialize.");
        }
        // glUseProgram(_mesh->getShader().getProgram());
        _mesh->getShader().use();

        // GLuint modelLoc = glGetUniformLocation(_mesh->getShader().getProgram(), "model");
        // glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &model[0][0]);

        if (_mesh->getShader().getLocation() == -1)
        {
            Log::error("Uniform 'model' not found in shader.");
            return;
        }

        glm::mat4 model = getModelMatrix();

        _mesh->getShader().setUniform("model", model);
        // _mesh->getShader().setUniform("view", view);
        // _mesh->getShader().setUniform("projection", projection);

        // Drawing the frame
        Buffer::drawElements(_mesh->getVAO(), _mesh->getIndices());
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
        model = glm::rotate(model, glm::radians(_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, glm::radians(_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, _scale);
        model = glm::translate(model, _position);
        return model;
    }
} // Elenore::Entity