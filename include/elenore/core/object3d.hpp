// Author: oknauta
// License:
// File: object3d.hpp
// Date: 2024-11-28

#ifndef ELN_OBJECT_HPP
#define ELN_OBJECT_HPP

#include "entity.hpp"
#include "mesh3d.hpp"
#include <memory>


namespace Elenore::Entity
{
    class Object3D : public Entity3D
    {
    public:
        Object3D(const char *name, std::shared_ptr<Graphics::Mesh3D> mesh);
        void draw();
        ~Object3D();
        
    private:
        std::shared_ptr<Graphics::Mesh3D> _mesh;
        const char *_name;
    };
} // namespace Elenore::Entity

#endif // ELN_OBJECT_HPP