// Author: oknauta
// License: 
// File: window.cpp
// Date: 2024-11-30

#include <elenore/core/window.hpp>

int main(void)
{
    int width = 400;
    
    Elenore::Core::Window window(width);
    
    while(!window.shouldClose())
    {
        window.beginDraw();
        
        
        
        window.endDraw();
    }
    
    return 0;
}