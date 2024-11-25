// Author: oknauta
// License:
// File: object.cpp
// Date: 2024-11-23

#include <logger.hpp>
#include <object.hpp>

namespace Elenore
{
    Object::Object(std::shared_ptr<Mesh> mesh, std::string object_name, glm::vec3 position)
        : _mesh(mesh), _name(object_name), _position(position), _rotation(0.0f, 0.0f, 0.0f), _scale(1.0f, 1.0f, 1.0f)
    {
        // std::cout << "Object in scene: " << _name << "\n";
        Log::info("Object in scene: " + _name);
    }

    void Object::draw(const glm::mat4 &view, const glm::mat4 &projection)
    {
        if (!_mesh)
        {
            // std::cerr << "ERROR: mesh didn't initialized.\n";
            Log::error("Mesh didn't initialize.");
        }
        glUseProgram(_mesh->getShader().getProgram());

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
        glBindVertexArray(_mesh->getVAO());
        glDrawElements(GL_TRIANGLES, _mesh->getIndices().size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

    void Object::setPosition(glm::vec3 position)
    {
        _position = position;
    }

    void Object::setRotation(glm::vec3 rotation)
    {
        _rotation = rotation;
    }

    void Object::setScale(glm::vec3 scale)
    {
        _scale = scale;
    }

    glm::mat4 Object::getModelMatrix()
    {
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::rotate(model, glm::radians(_rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        model = glm::rotate(model, glm::radians(_rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        model = glm::rotate(model, glm::radians(_rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, _scale);
        model = glm::translate(model, _position);
        return model;
    }

} // namespace Elenore