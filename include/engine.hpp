// Author: oknauta
// License: 
// File: engine.hpp
// Date: 2024-11-22

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Elenore
{
    class Engine
    {
    public:
        /**
         * @param window_width The window's width
         * @param window_height The window's height
         * @param window_title The window's title
         */
        Engine(int window_width, int window_height, const char *window_title);
        inline GLFWwindow *getWindow() const { return _main_window; };
        inline int windowShouldClose() { return glfwWindowShouldClose(_main_window); }
        void beginDraw();
        void endDraw();
        ~Engine();
    private:
        GLFWwindow *_main_window;
    };
} // Elenore

#endif // ENGINE_HPP