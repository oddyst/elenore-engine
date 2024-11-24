// Author: oknauta
// License: 
// File: window.hpp
// Date: 2024-11-22

#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Elenore
{
    class Window
    {
    public:
        /**
         * @param window_width The window's width
         * @param window_height The window's height
         * @param window_title The window's title
         */
        Window(int window_width, int window_height, const char *window_title);
        
        /// @returns The main window.
        GLFWwindow *getWindow() const { return _main_window; };
        
        /// @returns If the window should close.
        int windowShouldClose() { return glfwWindowShouldClose(_main_window); }
        void beginDraw();
        void endDraw();
        ~Window();
    private:
        GLFWwindow *_main_window;
    };
} // Elenore

#endif // ENGINE_HPP