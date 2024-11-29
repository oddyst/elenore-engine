// Author: oknauta
// License:
// File: object3d.cpp
// Date: 2024-11-28

#include "elenore/core/object3d.hpp"
#include "elenore/core/log.hpp"

namespace Elenore::Entity
{
    Object3D::Object3D(const char *name, std::shared_ptr<Graphics::Mesh3D> mesh)
        : _name(name), _mesh(mesh)
    {
        Log::info(std::string("Object in scene: ") + _name);
    }

    void Object3D::draw()
    {
        _mesh->getShader().use();

        _model = getModel();

        _mesh->getShader().setUniform("model", _model);

        glBindVertexArray(_mesh->getVAO());
        glDrawElements(GL_TRIANGLES, _mesh->getIndices().size(), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

    Object3D::~Object3D()
    {
        Log::info("Destroyed object");
    }
} // namespace Elenore::Entity