// Author: oknauta
// License:
// File: widget.hpp
// Date: 2024-11-29

#ifndef ELN_WIDGET_HPP
#define ELN_WIDGET_HPP

#include <glm/vec2.hpp>

namespace Elenore::Graphics::UI
{
    class Widget
    {
    public:
        Widget();
    protected:
        glm::vec2 _position, _size;
        
    };
} // namespace Elenore::UI

#endif // ELN_WIDGET_HPP