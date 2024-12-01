// Author: oknauta
// License: 
// File: scene3d.cpp
// Date: 2024-12-01

#include "elenore/core/scene3d.hpp"
#include "elenore/core/log.hpp"


namespace Elenore::Entity
{
    Scene3D::Scene3D(Camera3D camera, std::vector<Object3D> objects)
    : _camera(camera), _objects(objects)
    {
        
    }
} // Elenore::Entity