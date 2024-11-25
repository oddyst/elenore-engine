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
#include <glm/vec4.hpp>

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
        Window(int window_width, int window_height, const char *window_title = "GL Generic window");
        
        /// @returns The main window.
        GLFWwindow *getWindow() const { return _main_window; };
        
        /// @returns If the window should close.
        int shouldClose() { return glfwWindowShouldClose(_main_window); }
        void beginDraw(const glm::vec4 &clear_color = {0.1f, 0.1f, 0.1f, 1.0f});
        void endDraw();
        ~Window();
    private:
        static void framebufferSizeCallback(GLFWwindow *window, int w, int h);
        GLFWwindow *_main_window;
    };
} // Elenore

#endif // ENGINE_HPP